#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
This program performs the following tasks:
   1. Prompts the user to enter text and appends it to a file named "CSC450_CT5_mod5.txt".
   2. Reads all content from "CSC450_CT5_mod5.txt".
   3. Reverses the order of all characters in the file.
   4. Saves the reversed content to a new file named "CSC450-mod5-reverse.txt".
*/

int main() {
    string userInput;

    // Get input from user
    cout << "Enter text to add to file: ";
    getline(cin, userInput);

    // Append user input to file
    ofstream outFile("CSC450_CT5_mod5.txt", ios::app);
    outFile << userInput << endl;
    outFile.close();
    cout << "Text added to CSC450_CT5_mod5.txt" << endl;

    // Get command from user to reverse the file content
    cout << "Type \"Reverse\" to reverse the file content: ";
    string command;
    getline(cin, command);

    if (command == "Reverse") {
        // Read content from file
        ifstream inFile("CSC450_CT5_mod5.txt");
        string allContent = "";
        string line;
        while (getline(inFile, line)) {
            allContent += line + "\n";
        }
        inFile.close();

        // Reverse all characters
        string reversedContent = "";
        for (int i = allContent.length() - 1; i >= 0; i--) {
            reversedContent += allContent[i];
        }

        // Save reversed content to new file
        ofstream reverseFile("CSC450-mod5-reverse.txt");
        reverseFile << reversedContent;
        reverseFile.close();

        cout << "Reversed content saved to CSC450-mod5-reverse.txt" << endl;
    } else {
        cout << "Reversal command not provided. Skipping reversal." << endl;
    }

    cout << "Program finished!" << endl;
    return 0;
}