#include <iostream>
#include <vector>


#ifndef SORTINGS_QUICK_SORT_H
#define SORTINGS_QUICK_SORT_H

int partition(std::vector<int> &array, int start, int end) {
    int pivot = array[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    std::swap(array[pivotIndex], array[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (array[i] <= pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(array[i++], array[j--]);
        }
    }
    return pivotIndex;
}


// Time Complexity: Average O(nlogn), Worst O(n^2)
// Space Complexity: O(nlogn)
void quick_sort(std::vector<int> &array, int start, int end) {
    if (start >= end) {
        return;
    }
    int p = partition(array, start, end);
    quick_sort(array, start, p - 1);
    quick_sort(array, p + 1, end);
}

void quick_sort(std::vector<int> &array) {
    quick_sort(array, 0, array.size() - 1);
}




#endif //SORTINGS_QUICK_SORT_H
