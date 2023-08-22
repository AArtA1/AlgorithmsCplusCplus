#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SORTINGS_SHELL_SORT_OPTIMIZED_H
#define SORTINGS_SHELL_SORT_OPTIMIZED_H


void shell_sort_optimized(std::vector<int> &array) {
    int gap = 1;
    int size = array.size();
    while (gap < size / 3) {
        gap = gap * 3 + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < size; ++i) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        gap = (gap - 1) / 3;
    }
}


#endif //SORTINGS_SHELL_SORT_OPTIMIZED_H
