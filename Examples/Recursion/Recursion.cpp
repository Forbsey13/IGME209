#include <stdio.h>
#include <iostream>

using namespace std;

// example code P06
// recursion algorithm

int Sum(int* arr, int n) {
	if (n < 0) {
		cout << "Error message" << endl;
		return -1;
	}
	else if (n == 0)
		return arr[n];
	else
		return Sum(arr, n - 1) + arr[n];
}

int Factorial(int n) {
	if (n < 1) {
		cout << "Error message" << endl;
		return -1;
	}
	else if (n == 1) {
		return 1;
	}
	else
		return Factorial(n - 1) * n;
}

int Fibonacci(int n) {
	if (n < 0) {
		cout << "Error message" << endl;
		return -1;
	}
	else if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int FrogJump(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return FrogJump(n - 2) + FrogJump(n - 1);
}

bool BashGame(int n) {
	if (n == 0)
		return false;
	if (n == 1)
		return true;
	if (n == 2)
		return true;
	else
		return (!BashGame(n - 1)) || (!BashGame(n - 2));
}

int main() {
	int* arr = new int[10] { 1, 5, 7, 12, 15, 18, 20, 50, 78, 100 };
	cout << "Sum of the array = " << Sum(arr, 9) << endl;

	int type = 1;
	cout << "Input the id of the practice you want to print: ";
	cin >> type;

	int n1 = 10;
	cout << "Fibonacci(" << n1 << ") = " << Fibonacci(n1) << endl;

	int n2 = 10;
	cout << "Jump up " << n2 << " stairs = " << FrogJump(n2) << endl;

	int n3 = 10;
	if (BashGame(n3))
		cout << "Who plays first win with the number of " << n3 << endl;
	else
		cout << "Who plays first lose with the number of " << n3 << endl;

	return 0;
}