#include <iostream>
using namespace std;

// Complete this function to implement recursive binary search
int binarySearch(int arr[], int left, int right, int x) {
	// Your code here

	while (left <= right) {
		int middle = (left + right) / 2;

		if (arr[middle] == x) {
			return middle;
		}
		if (arr[middle] < x) {
			left = middle + 1;
		}
		else if (arr[middle] > x) {
			right = middle - 1;
		}
	}
	return -1;
}

int main() {
	// Example sorted array
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10; // Element to be searched
	int result = binarySearch(arr, 0, n - 1, x);

	if (result == -1) {
		cout << "Element not found in the array" << endl;
	}
	else {
		cout << "Element found at index: " << result << endl;
	}
	return 0;
}