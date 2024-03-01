#include <stdio.h>
#include <iostream>

using namespace std;

#define max_size 100 // Define the maximum size of the queue

// Struct to represent a regular queue
struct Queue {
    int values[max_size]; // Array to store queue elements
    int size = 0; // Current number of elements in the queue

    // Adds an element to the end of the queue
    // Returns false if the queue is full, true otherwise
    bool enqueue(int element) {
        if (size == max_size) {
            // Cannot add to a full queue
            return false;
        }
        values[size] = element; // Append the new element to the end
        size++;
        return true;
    }

    // Removes the element from the front of the queue
    // Returns false if the queue is empty, true otherwise
    bool dequeue() {
        if (size == 0) {
            // Cannot remove from an empty queue
            return false;
        }
        // Shift all elements one position to the left
        for (int i = 0; i < size - 1; i++) {
            values[i] = values[i + 1];
        }
        size--;
        return true;
    }

    // Prints all elements in the queue from front to back
    void print() {
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

// Struct to represent a loop queue (circular queue)
struct LoopQueue {
    int values[max_size]; // Array to store queue elements
    int head = 0; // Index of the front element
    int tail = 0; // Index where the next element will be inserted
    int size = 0; // Current number of elements in the queue

    // Adds an element to the end of the queue
    // Returns false if the queue is full, true otherwise
    bool enqueue(int element) {
        if (size == max_size) {
            // Cannot add to a full queue
            return false;
        }
        values[tail] = element; // Insert the new element at the tail
        tail = (tail + 1) % max_size; // Increment tail with wrap-around
        size++;
        return true;
    }

    // Removes the element from the front of the queue
    // Returns false if the queue is empty, true otherwise
    bool dequeue() {
        if (size == 0) {
            // Cannot remove from an empty queue
            return false;
        }
        head = (head + 1) % max_size; // Increment head with wrap-around
        size--;
        return true;
    }

    // Prints all elements in the queue from front to back
    void print() {
        cout << "Loop Queue: ";
        for (int i = head, count = 0; count < size; i = (i + 1) % max_size, count++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue; // Create a regular Queue object
    // Enqueue elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    // Print the current queue contents
    queue.print();

    // Dequeue two elements from the queue
    queue.dequeue();
    queue.dequeue();

    // Print the queue contents after two dequeues
    queue.print();
    return 0;
}s