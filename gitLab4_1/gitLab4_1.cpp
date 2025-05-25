// gitLab4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "search_sort_utils.h"
#include "GoldenSectionSearch.h"
#include "Interpolation_search.cpp"
#include <random>

using namespace std;

int main()
{
	int choice = 0;
	vector<int> arr; // Initialize the array with random numbers
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(-10, 10);

	// Create and fill with random numbers
	for (int i = 0; i < 10; ++i) 
	{
		arr.push_back(dis(gen));
	}

    cout << "Array Search Application!\n";
	cout << "This application demonstrates various search algorithms using a randomly generated array.\n";
	cout << "Generated array: ";
	for (const auto& num : arr)
	{
		cout << num << " ";
	}
	while (true)
	{
		cout << "\n\nPlease select an option:\n";
		cout << "1. Interpolation Search\n";
		cout << "2. Binary Search\n";
		cout << "3. Golden Section Search\n";
		cout << "4. Exit\n\n";
		cin >> choice;

		int target = 0;

		switch (choice)
		{
			case 1:
			{
				cout << "You selected Interpolation Search.\n";
				interpolationSearchMain();// Call the function for Interpolation Search
				break;
			}
			case 2:
			{
				cout << "You selected Binary Search.\n";

				cout << "Input element: " << endl;
				cin >> target;

				int result1 = binarySearch(arr, arr.size(), target);

				// Print search results
				cout << "Searching for " << target << ": ";
				if (result1 != -1) 
				{
					cout << "Found at index " << result1 << endl;
				}
				else 
				{
					cout << "Not found" << endl;
				}

				// Call the function for Binary Search here
				break;
			}
			case 3:
			{
				cout << "You selected Golden Section Search.\n";

				cout << "Input element: " << endl;
				cin >> target; // Example target value

				int result = goldenSectionSearch(arr, 0, arr.size()-1, target);

				// Print result
				cout << "Target value: " << target << endl;
				cout << "Closest element: " << arr[result] << " at index " << result << endl;

				// Call the function for Golden Section Search here
				break;
			}
			case 4:
			{
				cout << "Exiting the application.\n";
				return 0; // Exit the program
			}
			default:
			{
				cout << "Invalid choice. Please try again.\n";
				break;
			}
		}
	}
	}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
