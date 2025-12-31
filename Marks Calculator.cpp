#include <iostream>
using namespace std;

int main() {
    cout << "My Name Is Muhammad Saif" << endl;
    // This Is My Name..
    cout << "My Sap-ID Is 72395" << endl;
    // This Is My Sap-ID..
    float sub1, sub2, sub3, sub4, sub5, total, percentage;
    // Step 1: Declare variables for marks
    cout << "Enter marks of Subject 1: ";
    cin >> sub1;
    cout << "Enter marks of Subject 2: ";
    cin >> sub2;
    cout << "Enter marks of Subject 3: ";
    cin >> sub3;
    cout << "Enter marks of Subject 4: ";
    cin >> sub4;
    cout << "Enter marks of Subject 5: ";
    cin >> sub5;
    total = sub1 + sub2 + sub3 + sub4 + sub5;
    // Step 2: Calculate total marks
    percentage = (total / 500) * 100;
    // Step 3: Calculate percentage (assuming each subject is out of 100 marks)
    cout << "Total Marks = " << total << " out of 500" << endl;
    cout << "Percentage  = " << percentage << "%" << endl;
    // Step 4: Display results
    return 0;
}

