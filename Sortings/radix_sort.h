#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SORTINGS_COUNT_SORT_H
#define SORTINGS_COUNT_SORT_H

void count_sort(std::vector<int> &array, int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

// Time Complexity: O(d*(n+k))
// Space Complexity: O(n+k)
void radix_sort(std::vector<int> &array) {
    int n = array.size();
    int m = *std::max_element(array.begin(), array.end());
    for (int exp = 1; m / exp > 0; exp *= 10) {
        count_sort(array, n, exp);
    }
}



#endif //SORTINGS_COUNT_SORT_H
