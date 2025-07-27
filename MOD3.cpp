/*
This program asks the user to enter three integers and stores each in its own variable.
It then creates three integer pointers, each pointing to one of the variables.
Finally, it displays the contents of the variables and the values pointed to by the pointers.
*/

#include <iostream>
using namespace std;

int main() {
    int integer1, integer2, integer3;

    // Prompt user to enter values
    cout << "Enter first integer: ";
    cin >> integer1;

    cout << "Enter second integer: ";
    cin >> integer2;

    cout << "Enter third integer: ";
    cin >> integer3;

    // Create integer pointers 
    int* pointer1 = new int(integer1);
    int* pointer2 = new int(integer2);
    int* pointer3 = new int(integer3);

    // Display variables
    cout << "\nVariable contents:" << endl;
    cout << "Integer 1: " << integer1 << endl;
    cout << "Integer 2: " << integer2 << endl;
    cout << "Integer 3: " << integer3 << endl;

    // Display pointers
    cout << "\nPointer contents:" << endl;
    cout << "Pointer 1 points to: " << *pointer1 << endl;
    cout << "Pointer 2 points to: " << *pointer2 << endl;
    cout << "Pointer 3 points to: " << *pointer3 << endl;

    // Delete operator
    delete pointer1;
    delete pointer2;
    delete pointer3;

    return 0;
}
