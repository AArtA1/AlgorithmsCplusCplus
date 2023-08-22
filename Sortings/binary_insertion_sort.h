#include <iostream>
#include <vector>

#ifndef SORTINGS_BINARY_INSERTION_SORT_H
#define SORTINGS_BINARY_INSERTION_SORT_H

int binary_search(std::vector<int> &array, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == array[mid])
            return mid + 1;
        else if (item > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
void binary_insertion_sort(std::vector<int> &array) {
    int i, loc, j, selected, n = array.size();
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = array[i];
        loc = binary_search(array, selected, 0, j);
        while (j >= loc) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = selected;
    }
}


#endif //SORTINGS_BINARY_INSERTION_SORT_H
