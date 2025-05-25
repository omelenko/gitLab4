// search_sort_utils.h
#pragma once
#include <vector>
using namespace std;
// Функція сортування бульбашкою
static void bubbleSort(vector<int>& arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

// Функція бінарного пошуку
static int binarySearch(vector<int>& arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
