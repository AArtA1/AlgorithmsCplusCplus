#include <iostream>
#include <vector>


#ifndef SORTINGS_HEAP_SORT_H
#define SORTINGS_HEAP_SORT_H


int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

void max_heapify(std::vector<int> &array, int heap_size, int index) {
    auto l = left(index);
    auto r = right(index);
    int largest = index;
    if (l < heap_size && array[l] > array[largest]) {
        largest = l;
    }
    if (r < heap_size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != index) {
        std::swap(array[index], array[largest]);
        max_heapify(array, heap_size, largest);
    }
}


// Time Complexity: O(nlogn)
// Space Complexity: O(1)
void heap_sort(std::vector<int> &array) {
    int size = array.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        max_heapify(array, size, i);
    }
    for (int i = size - 1; i >= 0; --i) {
        std::swap(array[0], array[i]);
        max_heapify(array, i, 0);
    }
}



#endif //SORTINGS_HEAP_SORT_H
