//**************************************************************************************
// Author.....: Andrew Hathaway
// Assignment.: Loop Mastery – C++ Interactive Menu System
// Description: This program provides an interactive utility with various
//              functionalities including factorial calculation, number pyramid,
//              sum of even or odd numbers, string reversal, Fibonacci series,
//              and palindrome check. The user can choose from a menu of options
//              and the program will execute the selected function. Input validation
//              is implemented to ensure that the user provides valid data.
//              The program continues to run until the user chooses to exit.
//**************************************************************************************

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function prototypes
void factorialCalculator();
void numberPyramid();
void sumEvenOrOdd();
void reverseString();
void fibonacciSeries();
void palindromeCheck();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 7) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                factorialCalculator();
                break;
            case 2:
                numberPyramid();
                break;
            case 3:
                sumEvenOrOdd();
                break;
            case 4:
                reverseString();
                break;
            case 5:
                fibonacciSeries();
                break;
            case 6:
                palindromeCheck();
                break;
            case 7:
                cout << "Goodbye! Thanks for using the program.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    cout << "\n========= Interactive Utility Program =========\n";
    cout << "1. Factorial Calculator\n";
    cout << "2. Number Pyramid\n";
    cout << "3. Sum of Even or Odd Numbers\n";
    cout << "4. Reverse a String\n";
    cout << "5. Fibonacci Series\n";
    cout << "6. Palindrome Check\n";
    cout << "7. Exit\n";
    cout << "==============================================\n";
    cout << "Enter your choice: ";
}

void factorialCalculator() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    while (n < 0 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive integer: ";
        cin >> n;
    }

    unsigned long long factorial = 1;
    int i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    cout << "Factorial of " << n << " is: " << factorial << "\n";
}

void numberPyramid() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    while (rows <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number of rows: ";
        cin >> rows;
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
}

void sumEvenOrOdd() {
    int choice, limit;
    cout << "Choose an option:\n1. Sum of Even Numbers\n2. Sum of Odd Numbers\nChoice: ";
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter 1 for even or 2 for odd: ";
        cin >> choice;
    }

    cout << "Enter upper limit: ";
    cin >> limit;

    while (limit < 0 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a non-negative integer: ";
        cin >> limit;
    }

    int sum = 0, i = 0;
    do {
        if (choice == 1 && i % 2 == 0) sum += i;
        if (choice == 2 && i % 2 != 0) sum += i;
        i++;
    } while (i <= limit);

    if (choice == 1)
        cout << "Sum of even numbers up to " << limit << ": " << sum << endl;
    else
        cout << "Sum of odd numbers up to " << limit << ": " << sum << endl;
}

void reverseString() {
    string input;
    cout << "Enter a string: ";
    cin.ignore(); // clear buffer
    getline(cin, input);

    string reversed = "";
    int i = input.length() - 1;
    while (i >= 0) {
        reversed += input[i];
        i--;
    }

    cout << "Reversed string: " << reversed << endl;
}

void fibonacciSeries() {
    int terms;
    cout << "Enter number of terms for Fibonacci series: ";
    cin >> terms;

    while (terms <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive integer: ";
        cin >> terms;
    }

    int a = 0, b = 1, count = 0;
    cout << "Fibonacci Series: ";
    while (count < terms) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
        count++;
    }
    cout << endl;
}

void palindromeCheck() {
    string input;
    cout << "Enter a string to check for palindrome: ";
    cin.ignore();
    getline(cin, input);

    string cleaned = "";
    for (char c : input) {
        if (isalnum(c)) cleaned += tolower(c);
    }

    int start = 0;
    int end = cleaned.length() - 1;
    bool isPalindrome = true;

    while (start < end) {
        if (cleaned[start] != cleaned[end]) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome)
        cout << "'" << input << "' is a palindrome.\n";
    else
        cout << "'" << input << "' is not a palindrome.\n";
}
