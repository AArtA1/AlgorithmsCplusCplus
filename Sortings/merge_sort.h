#include <iostream>
#include <vector>

#ifndef SORTINGS_MERGE_SORT_H
#define SORTINGS_MERGE_SORT_H

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void mergeSort(std::vector<int> &array) {
    int left, right, mid, end, now;
    std::vector<int> temp = array;
    for (int width = 1; width < array.size(); width *= 2) {
        for (int start = 0; start < array.size(); start += 2 * width) {
            mid = start + width - 1;
            end = start + 2 * width - 1;

            if (mid >= array.size()) {
                mid = array.size() - 1;
            }
            if (end >= array.size()) {
                end = array.size() - 1;
            }
            left = start;
            right = mid + 1;
            now = start;
            while (left <= mid && right <= end) {
                if (array[left] <= array[right]) {
                    temp[now] = array[left];
                    left++;
                } else {
                    temp[now] = array[right];
                    right++;
                }
                now++;
            }
            while (left <= mid) {
                temp[now] = array[left];
                left++;
                now++;
            }
            while (right <= end) {
                temp[now] = array[right];
                right++;
                now++;
            }
        }
        array = temp;
    }
}

#endif //SORTINGS_MERGE_SORT_H
