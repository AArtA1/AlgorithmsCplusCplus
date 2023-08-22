
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <string>

typedef unsigned long long ull;

// Генерация случайного основания хэширования на отрезке (before, after):
int gen_base(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

struct PolyHash {
    // -------- Статические переменные класса --------
    static const int mod = (int)1e9+123; // простой модуль полиномиального хэширования
    static std::vector<int> pow1;        // степени основания base по модулю mod
    static std::vector<ull> pow2;        // степени основания base по модулю 2^64
    static int base;                     // основание base

    // --------- Статические функции класса ---------
    static inline int diff(int a, int b) { // разность a и b по модуль mod (Предполагается: 0 <= a < mod, 0 <= b < mod)
        return (a -= b) < 0 ? a + mod : a;
    }

    // -------------- Переменные класса -------------
    std::vector<int> pref1; // Полиномиальный хэш на префиксе по модулю mod
    std::vector<ull> pref2; // Полиномиальный хэш на префиксе по модулю 2^64

    // Конструктор от строки:
    PolyHash(const std::string& s)
            : pref1(s.size()+1u, 0)
            , pref2(s.size()+1u, 0)
    {
        assert(base < mod);
        const int n = s.size(); // Досчитываем необходимые степени основания по модулям хэширования
        while ((int)pow1.size() <= n) {
            pow1.push_back(1LL * pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        for (int i = 0; i < n; ++i) { // Заполняем массив полиномиальных хэшей на префиксе
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }

    // Полиномиальный хэш подпоследовательности [pos, pos+len)
    // Если mxPow != 0, то происходит домножение значения до старшей степени base ^ mxPow
    inline std::pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return std::make_pair(hash1, hash2);
    }
};

// Инициализация статических объектов класса PolyHash:
int PolyHash::base((int)1e9+7);
std::vector<int> PolyHash::pow1{1};
std::vector<ull> PolyHash::pow2{1};

int main() {
    // Чтение данных:
    char buf[1+100000];
    scanf("%100000s", buf);
    std::string a(buf);
    scanf("%100000s", buf);
    std::string b(buf);

    // Вычисление максимальной степени:
    const int mxPow = std::max((int)a.size(), (int)b.size());

    // Генерация случайного основания хэширования:
    PolyHash::base = gen_base(256, PolyHash::mod);

    // Создание объектов хэширования:
    PolyHash hash_a(a), hash_b(b);

    // Копируем нужный нам полиномиальный хэш всей строки b:
    const auto need = hash_b(0, (int)b.size(), mxPow);

    // Проходим по хэшам строки a и ищем совпадение с хэшем всей строки b:
    for (int i = 0; i + (int)b.size() <= (int)a.size(); ++i) {
        if (hash_a(i, b.size(), mxPow) == need) {
            printf("%d ", i);
        }
    }

    return 0;
}