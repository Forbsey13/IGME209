#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

// Structure
struct MyStructure {
    int i_var;
    float f_var;
    char c_var = 'a';
};

void structureExample() {
    MyStructure node;
    node.i_var = 10;
    node.f_var = 3.14f;

    printf("%d %f %c\n", node.i_var, node.f_var, node.c_var);

    MyStructure* node_ptr = new MyStructure();
    node_ptr->i_var = 12;
    node_ptr->f_var = 1.23f;

    printf("%d %f %c\n", node_ptr->i_var, node_ptr->f_var, node_ptr->c_var);
}

// C++ standard library
void standardLibrary() {
    // iostream
    int i_var;
    float f_var;

    cout << "Input an integer and a float value: " << endl;
    cin >> i_var >> f_var;
    cout << i_var << "," << f_var << endl << endl;;


    // string 
    string str1 = "IGME";
    string str2 = "209";

    cout << "Combine two strings:" << endl;
    string str = str1 + "-" + str2;
    cout << str1 << "+" << str2 << "=" << str << endl << endl;


    // vector: dynamic array
    vector<int> i_array;
    i_array.push_back(1);
    i_array.push_back(2);
    i_array.push_back(3);

    cout << "Print the vector: " << endl;
    for (int i = 0; i < i_array.size(); i++)
        cout << i_array[i] << " ";
    cout << endl; // start a new line

}

int main() {
    structureExample();
    standardLibrary();
    return 0;
}