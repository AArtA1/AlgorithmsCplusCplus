
#pragma GCC optimize("O3")
// use avx instructions for optimizing
#pragma GCC target("avx2")


// Karatsuba Algorithm
// Consider we have two polynomials a(x),b(x) which size are n = 2k
// a(x) = a1(x) + x^k*a2(x)
// b(x) = b1(x) + x^k*b2(x)
// c(x) = a(x)*b(x) = a1(x)b1(x) + x^k(a1(x)b2(x) + a2(x)b2(x)) + x^(2k) * a2(x)b2(x)
// then p1(x) = a1(x)*b1(x), p2(x) = a2(x)b2(x)
// t(x) = (a1(x) + a2(x))(b1(x) + b2(x))
// c(x) = a1(x)b1(x) + x^k(t - p1(x) - p2(x)) + x^(2k) * a2(x)b2(x)
// Time Complexity: T(n) = 3T(n/2) => T(n) = O(n^log3) = O(n^1.54)
void karatsuba(int *a, int *b, int *c,int n) {
    if (n <= 64) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i + j] += a[i] * b[j];
    }
    else {
        int k = n / 2;
        int left_sum[k], right_sum[k]; // left_sum = (a1(x) + a2(x)); right_sum = (b1(x) + b2(x))
        int *t = new int[n];
        for (int i = 0; i < k; i++) {
            left_sum[i] = a[i] + a[k + i];
            right_sum[i] = b[i] + b[k + i];
        }
        karatsuba(left_sum, right_sum, t, k); // calculate t
        karatsuba(a, b, c, k); // calculate p1
        karatsuba(a + k, b + k, c + n, k); // calculate p2
        int *t1 = t, *t2 = t + k;
        int *s1 = c, *s2 = c + k, *s3 = c + 2 * k, *s4 = c + 3 * k;
        for (int i = 0; i < k; i++) {
            int c1 = s2[i] + t1[i] - s1[i] - s3[i];
            int c2 = s3[i] + t2[i] - s2[i] - s4[i];
            c[k + i] = c1;
            c[n + i] = c2;
        }
    }
}


int main() {
}
