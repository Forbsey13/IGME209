#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

atomic<bool> keepRunning(true);

// Function to be executed by the background thread
void printNumbers() {
    int count = 0;
    while (keepRunning) { // Loop until keepRunning is false
        this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second
        cout << "Number from background thread: " << count << endl;
        ++count;
    }
}

int main() {
    // Creating a background thread to execute the printNumbers function
    thread backgroundThread(printNumbers);

    // Main thread doing its own work
    cout << "Main thread is working independently... Press Enter to stop." << endl;

    // Wait for user input to stop the background thread
    cin.get();
    keepRunning = false; // This will stop the background thread loop

    // Wait for the background thread to finish
    backgroundThread.join();

    cout << "Background thread has been stopped. Exiting program." << endl;

    return 0;
}