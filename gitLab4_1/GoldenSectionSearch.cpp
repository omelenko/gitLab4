#include <iostream>
#include "GoldenSectionSearch.h"
#include <vector>
#include <cmath>

using namespace std;

const double PHI = (1 + sqrt(5)) / 2;

int goldenSectionSearch(const vector<int>& arr, int start, int end, int target)
{

    if (start >= end) 
    {
        return -1; // Invalid range
    }
    if (end - start <= 1) 
    {
        return (abs(arr[start] - target) < abs(arr[end] - target)) ? start : end;
    }


    int length = end - start;
    int m1 = start + static_cast<int>(length / (PHI + 1) + 0.5);
    int m2 = start + static_cast<int>(length / PHI + 0.5);

    if (abs(arr[m1] - target) < abs(arr[m2] - target))
    {
        return goldenSectionSearch(arr, start, m2, target);
    }
    else
    {
        return goldenSectionSearch(arr, m1, end, target);
    }
}