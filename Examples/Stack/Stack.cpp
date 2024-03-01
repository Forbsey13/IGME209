#include <stdio.h>
#include <iostream>

using namespace std;

#define max_size 100 // Define the maximum size of the stack

// Struct to represent a stack
struct Stack {
    int values[max_size]; // Array to store stack elements
    int size = 0; // Current size of the stack (number of elements)

    // Function to add an element to the stack
    // Returns false if the stack is full, true otherwise
    bool push(int element) {
        if (size == max_size) {
            // Stack overflow condition
            return false;
        }
        values[size] = element; // Place the element on the top of the stack
        size++; // Increment stack size
        return true;
    }

    // Function to remove the top element from the stack
    // Returns false if the stack is empty, true otherwise
    bool pop() {
        if (size == 0) {
            // Stack underflow condition
            return false;
        }
        size--; // Decrement stack size, effectively removing the top element
        return true;
    }

    // Function to print all elements in the stack
    void print() {
        cout << "Stack elements from bottom to top: ";
        for (int i = 0; i < size; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack; // Create a Stack object
    // Push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    // Print the current stack contents
    stack.print();

    // Pop two elements from the stack
    stack.pop();
    stack.pop();

    // Print the stack contents after two pops
    stack.print();

    return 0;
}