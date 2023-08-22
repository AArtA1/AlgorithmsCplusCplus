#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SORTINGS_SELECTION_SORT_H
#define SORTINGS_SELECTION_SORT_H


// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selection_sort(std::vector<int> &array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < array.size(); ++j){
            if (array[j] < array[min]){
                min = j;
            }
        }
        std::swap(array[min], array[i]);
    }
}


#endif //SORTINGS_SELECTION_SORT_H
