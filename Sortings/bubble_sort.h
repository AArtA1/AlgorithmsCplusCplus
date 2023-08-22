#include <iostream>
#include <vector>

#ifndef SORTINGS_BUBBLE_SORT_H
#define SORTINGS_BUBBLE_SORT_H


// Time Complexity: O(n^2)
// Space Complexity: O(1)
void bubble_sort(std::vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}


#endif //SORTINGS_BUBBLE_SORT_H
