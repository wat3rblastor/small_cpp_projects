#include <vector>
#include <algorithm>
#include <iostream>

void selectionSort(std::vector<int>& list) {

    int n = list.size();
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (list[j] < list[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(list[minIdx], list[i]);
    }
}

void bubbleSort(std::vector<int>& list) {

    bool hasSwapped = true;
    while (hasSwapped) {
        hasSwapped = false;
        for (int i = 0; i < static_cast<int>(list.size()) - 1; ++i) {
            if (list[i] > list[i+1]) {
                std::swap(list[i], list[i+1]);
                hasSwapped = true;
            }
        }
    }
}

void insertionSort(std::vector<int>& list) {

    for (int i = 1; i < static_cast<int>(list.size()); ++i) {
        int curIdx = i;
        while (curIdx > 0 && list[curIdx] < list[curIdx - 1]) {
            std::swap(list[curIdx], list[curIdx - 1]);
            --curIdx;
        }
    }
}

void merge(std::vector<int>& list, int l, int mid, int r) {

    std::vector<int> leftTmp(list.begin() + l, list.begin() + mid + 1);
    std::vector<int> rightTmp(list.begin() + mid + 1, list.begin() + r + 1);

    int m = leftTmp.size();
    int n = rightTmp.size();

    int lIdx = 0;
    int rIdx = 0;
    int idx = l;
    while (lIdx < m || rIdx < n) {
        if (lIdx < m && rIdx < n) {
            if (leftTmp[lIdx] < rightTmp[rIdx]) {
                list[idx] = leftTmp[lIdx];
                ++lIdx;
            }
            else {
                list[idx] = rightTmp[rIdx];
                ++rIdx;
            }
        }
        else if (lIdx < m) {
            list[idx] = leftTmp[lIdx];
            ++lIdx;
        }
        else if (rIdx < n) {
            list[idx] = rightTmp[rIdx];
            ++rIdx;
        }
        ++idx;
    }
}

void mergeSort(std::vector<int>& list, int l, int r) {

    if (l == r) return;
    int mid = l + (r - l) / 2;
    mergeSort(list, l, mid);
    mergeSort(list, mid + 1, r);
    merge(list, l, mid, r);
}

void display(const std::vector<int>& list) {
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> list {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Selection Sort
    std::vector<int> selectionSortList = list;
    selectionSort(selectionSortList);
    display(selectionSortList);

    // Bubble Sort
    std::vector<int> bubbleSortList = list;
    bubbleSort(bubbleSortList);
    display(bubbleSortList);

    // Insertion Sort
    std::vector<int> insertionSortList = list;
    insertionSort(insertionSortList);
    display(insertionSortList);

    // Merge Sort
    std::vector<int> mergeSortList = list;
    mergeSort(mergeSortList, 0, static_cast<int>(list.size()) - 1);
    display(mergeSortList);

}