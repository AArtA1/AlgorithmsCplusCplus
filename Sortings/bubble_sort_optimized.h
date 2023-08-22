#include <iostream>
#include <vector>


#ifndef SORTINGS_BUBBLE_SORT_OPTIMIZED_H
#define SORTINGS_BUBBLE_SORT_OPTIMIZED_H


// Time Complexity: O(n^2)
// Space Complexity: O(1)
void bubble_sort_optimized(std::vector<int> &array) {
    int n = array.size();
    bool sorted;
    while (n > 1) {
        sorted = true;
        int n_size = 0;
        for (int j = 1; j <= n - 1; ++j) {
            if (array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
                sorted = false;
                n_size = j;
            }
        }
        if (sorted) {
            break;
        }
        n = n_size;
    }
}

#endif //SORTINGS_BUBBLE_SORT_OPTIMIZED_H
