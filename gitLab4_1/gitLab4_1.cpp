#include <iostream>
#include <vector>

using namespace std;

// Function to perform interpolation search
// Returns the index of the element if found, otherwise -1
int interpolationSearch(const vector<int>& arr, int x) {
    // Finding the indexes of start and end of array
    int low = 0;
    int high = arr.size() - 1;
    
    // Condition for search termination
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }
        
        // Interpolation formula to calculate position
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        
        // If element is found
        if (arr[pos] == x)
            return pos;
        
        // If x is greater, search in the right part
        if (arr[pos] < x)
            low = pos + 1;
        // If x is smaller, search in the left part
        else
            high = pos - 1;
    }
    
    return -1; // Element not found
}

// Function to demonstrate the algorithm
void demonstrateInterpolationSearch() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    int x = 18;
    int index = interpolationSearch(arr, x);
    if (index != -1)
        cout << "Element " << x << " found at position " << index << endl;
    else
        cout << "Element " << x << " not found in the array" << endl;
    
    x = 25;
    index = interpolationSearch(arr, x);
    if (index != -1)
        cout << "Element " << x << " found at position " << index << endl;
    else
        cout << "Element " << x << " not found in the array" << endl;
}

int main() {
    
        demonstrateInterpolationSearch();
        
    return 0;
}