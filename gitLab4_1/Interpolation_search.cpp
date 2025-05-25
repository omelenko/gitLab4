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

// Custom implementation of bubble sort without using STL
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

// Function for user input array and search
void userInterpolationSearch() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " array elements (in any order):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Check if the array is sorted
    bool isSorted = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            isSorted = false;
            break;
        }
    }
    
    // If the array is not sorted, sort it
    if (!isSorted) {
        cout << "Array is not sorted. Performing automatic sorting...\n";
        bubbleSort(arr); // Using custom bubble sort
        cout << "Sorted array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    int x;
    cout << "Enter element to search: ";
    cin >> x;
    
    int index = interpolationSearch(arr, x);
    if (index != -1)
        cout << "Element " << x << " found at position " << index << endl;
    else
        cout << "Element " << x << " not found in the array" << endl;
}

int main() {
    int choice;
    cout << "Select an option:\n";
    cout << "1. Demonstration with a prepared example\n";
    cout << "2. Enter your own array and search in it\n";
    cout << "Your choice: ";
    cin >> choice;
    
    if (choice == 1) {
        demonstrateInterpolationSearch();
    } else if (choice == 2) {
        userInterpolationSearch();
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}