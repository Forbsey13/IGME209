// EO5-Will-Forbes.cpp

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack<int> intStack;

    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    intStack.push(20);
    intStack.push(25);

    queue<int> intQueue;

    cout << "Stack:\n";
    while (!intStack.empty()) {
        int temp = intStack.top();
        intStack.pop();

        cout << temp << " " << endl;

        intQueue.push(temp);
    }

    cout << "\nQueue:\n";
    while (!intQueue.empty()) {
        int temp = intQueue.front();
        intQueue.pop();

        cout << temp << " " << endl;
    }
}