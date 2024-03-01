#include <stdio.h>

void swapValues(int* a, int* b) {
	// Hint: You need to swap the values pointed by a and b.
	// Consider using a temporary variable to hold one of the values during the swap.

	// Your code here
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void filterElementsAndPrint(int* arr, int size) {
	// Hint 1: First, count the number of non-zero elements in the array.
	// This count will be the size of your new array.

	// Hint 2: Dynamically allocate an array of integers with the counted size.
	// Use 'new int[count]' syntax.

	// Hint 3: Iterate through the original array again and copy only the non-zero elements
	// into your dynamically allocated array.

	// Hint 4: Print the elements of the new array. Don't forget to use a loop.

	// Hint 5: After printing, release the dynamically allocated memory using 'delete[]'
	// to avoid memory leaks.

	// Your code here
	//variables
	int count = 0;
	int index = 0;

	//find size of new array
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			count++;
		}
	}

	//create new array
	int* newArr = new int[count];

	//Copy over non-zero
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			newArr[index] = arr[i];
			index++;
		}
	}

	//Print out new array
	printf("New Array: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", newArr[i]);
	}

	//Delete memory
	delete [] newArr;

	return;
}

int main() {
	// Swapping values section
	int x = 2, y = 4;
	int* a = &x;
	int* b = &y;
	printf("1. Swapping Values\n");
	printf("Before Swapping: a = %d, b = %d\n", *a, *b);
	swapValues(a, b);
	printf("After Swapping: a = %d, b = %d\n\n", *a, *b);

	// Data filtering section
	int arr[] = { 0, 2, 0, 3, 3, 1, 2, 1, 2, 2, 2, 3, 1, 2, 2, 0, 2, 3, 0, 1, 1, 3, 1, 1, 2, 3, 3, 3, 0, 2, 3, 2, 2, 0, 3, 3, 1, 3, 2, 2, 0, 2, 3, 0, 0, 3, 1, 2, 2, 0, 1, 3, 3, 0, 1, 2, 3, 1, 0, 1, 0, 3, 1, 3, 3, 1, 0, 3, 3, 0, 3, 1, 3, 1, 2, 3, 0, 1, 2, 1, 2, 1, 1, 1, 0, 2, 3, 1, 1, 1, 3, 2, 3, 2, 2, 1, 1, 3, 2, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("2. Data Filtering of All Non-Zero Elements\n");
	printf("Original Array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	filterElementsAndPrint(arr, size);
	return 0;
}