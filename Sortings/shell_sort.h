#include <iostream>
#include <vector>
#include <algorithm>


#ifndef SORTINGS_SHELL_SORT_H
#define SORTINGS_SHELL_SORT_H

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void shell_sort(std::vector<int> &array) {
    int n = array.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

#endif //SORTINGS_SHELL_SORT_H
