// loops_project.cpp
// Interactive Utility Program
// This program demonstrates a menu-based utility including:
// 1. Factorial Calculator (using a while loop)
// 2. Number Pyramid (using nested for-loops)
// 3. Sum of Even or Odd Numbers (using a do-while loop)
// 4. Reverse a String (using a while loop)
// 5. Exit the program

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the factorial of a number using a while loop
void factorialCalculator() {
    int n;
    cout << "\nEnter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }

    long long factorial = 1;
    int temp = n;
    while (temp > 0) {
        factorial *= temp;
        temp--;
    }
    cout << "Factorial of " << n << " is: " << factorial << endl;
}

// Function to display a number pyramid using nested for-loops
void numberPyramid() {
    int rows;
    cout << "\nEnter number of rows: ";
    cin >> rows;

    // Outer loop for each row
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces for proper alignment
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        // Print numbers from 1 to the current row number
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Function to calculate the sum of even or odd numbers up to a given limit using a do-while loop
void sumEvenOdd() {
    int option;
    cout << "\nChoose the option for summing numbers:" << endl;
    cout << "1. Sum of Even Numbers" << endl;
    cout << "2. Sum of Odd Numbers" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> option;

    int N;
    cout << "Enter an upper limit: ";
    cin >> N;

    int sum = 0;
    int number;

    // Sum even numbers
    if (option == 1) {
        number = 0; // even numbers start at 0
        // Use do-while loop to sum even numbers up to N
        do {
            sum += number;
            number += 2;
        } while (number <= N);
        cout << "Sum of even numbers up to " << N << ": " << sum << endl;
    }
    // Sum odd numbers
    else if (option == 2) {
        number = 1; // odd numbers start at 1
        // Use do-while loop to sum odd numbers up to N
        do {
            // Only add if the number is <= N (handles edge cases)
            if(number <= N) {
                sum += number;
            }
            number += 2;
        } while (number - 2 < N);  // Ensure the loop runs while the last added number is less than N
        cout << "Sum of odd numbers up to " << N << ": " << sum << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

// Function to reverse a string using a while loop
void reverseString() {
    // Clear the input buffer before using getline
    cin.ignore();
    string input;
    cout << "\nEnter a string: ";
    getline(cin, input);

    string reversed = "";
    int index = input.size() - 1;
    // Reverse string using a while loop
    while (index >= 0) {
        reversed.push_back(input[index]);
        index--;
    }
    cout << "Reversed string: " << reversed << endl;
}

// Main function - displays the menu and processes user choices
int main() {
    int choice;

    do {
        cout << "\n========= Interactive Utility Program =========" << endl;
        cout << "1. Factorial Calculator" << endl;
        cout << "2. Number Pyramid" << endl;
        cout << "3. Sum of Even or Odd Numbers" << endl;
        cout << "4. Reverse a String" << endl;
        cout << "5. Exit Program" << endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                factorialCalculator();
                break;
            case 2:
                numberPyramid();
                break;
            case 3:
                sumEvenOdd();
                break;
            case 4:
                reverseString();
                break;
            case 5:
                cout << "\nGoodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
