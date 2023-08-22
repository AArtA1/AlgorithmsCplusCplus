#include <iostream>
#include <vector>

#ifndef SORTINGS_INSERTION_SORT_H
#define SORTINGS_INSERTION_SORT_H

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void insertion_sort(std::vector<int> &array) {
    if (array.size() > 1) {
        int size = array.size();
        for (int i = 1; i < size; ++i) {
            int j = i - 1;
            int key = array[i];
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;
        }
    }
}

#endif //SORTINGS_INSERTION_SORT_H
