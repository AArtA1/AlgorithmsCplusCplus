#include <iostream>
#include <vector>
#include <algorithm>


// Prefix Function
// Time Complexity: O(n)
std::vector<int> prefix_function(std::string s) {
    int n = (int) s.size();
    std::vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    return p;
}


// Z-function
// Time Complexity: O(n)
std::vector<int> z_function(std::string s) {
    int n = (int) s.size();
    std::vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}


// Time Complexity: O(n+m)
std::vector<int> algorithm(std::string s,std::string t){
    std::string temp = t + "#" + s;
    auto arr = prefix_function(temp);
    std::vector<int> res;
    std::for_each(arr.begin(), arr.end(), [&](const auto &item) {
        static int i = 0;
        if(item == t.size()){
            ++i;
            res.push_back(i);
        }
    });
    return res;
}


int main() {

}
