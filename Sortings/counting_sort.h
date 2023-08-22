#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SORTINGS_COUNTING_SORT_H
#define SORTINGS_COUNTING_SORT_H


// Time Complexity: O(n+k) k - range of array min and max
// Space Complexity: O(k)
void counting_sort(std::vector<int> &array) {
    int min = *std::min_element(array.begin(), array.end());
    int max = *std::max_element(array.begin(), array.end());
    std::vector<int> temp(max - min + 1, 0);
    for (int i : array) {
        ++temp[i - min];
    }
    int k = 0;
    for (int i = 0; i < max - min + 1; ++i) {
        while (temp[i] != 0) {
            array[k] = i + min;
            ++k;
            --temp[i];
        }
    }
}

#endif //SORTINGS_COUNTING_SORT_H
