#include <iostream>
#include <iomanip>  // for formatting output
#include <string>   // for using strings
using namespace std;

// Function to calculate grade based on percentage
char calculateGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else
        return 'F';
}

// Function to display a line (for decoration)
void printLine(char symbol, int count) {
    for (int i = 0; i < count; i++)
        cout << symbol;
    cout << endl;
}

int main() {
    // Title Section
    printLine('=', 50);
    cout << setw(30) << "STUDENT REPORT CARD SYSTEM" << endl;
    printLine('=', 50);
    cout << endl;

    // Variables
    string name;
    int rollNo;
    float subject1, subject2, subject3;
    float total, average, percentage;
    char grade;

    // Input Section
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << endl;

    cout << "Enter marks for Subject 1 (out of 100): ";
    cin >> subject1;
    cout << "Enter marks for Subject 2 (out of 100): ";
    cin >> subject2;
    cout << "Enter marks for Subject 3 (out of 100): ";
    cin >> subject3;

    cout << endl;

    // Processing Section
    total = subject1 + subject2 + subject3;
    average = total / 3;
    percentage = (total / 300) * 100;
    grade = calculateGrade(percentage);

    // Output Section
    printLine('-', 50);
    cout << setw(28) << "REPORT CARD" << endl;
    printLine('-', 50);

    cout << "Name       : " << name << endl;
    cout << "Roll No    : " << rollNo << endl;
    cout << endl;

    cout << fixed << setprecision(2);
    cout << "Subject 1  : " << subject1 << " / 100" << endl;
    cout << "Subject 2  : " << subject2 << " / 100" << endl;
    cout << "Subject 3  : " << subject3 << " / 100" << endl;
    cout << endl;

    cout << "Total Marks: " << total << " / 300" << endl;
    cout << "Average    : " << average << endl;
    cout << "Percentage : " << percentage << " %" << endl;
    cout << "Grade      : " << grade << endl;
    printLine('-', 50);

    // Comment based on Grade
    switch (grade) {
        case 'A':
            cout << "Excellent Performance! Keep it up!" << endl;
            break;
        case 'B':
            cout << "Very Good! You can do even better." << endl;
            break;
        case 'C':
            cout << "Good Effort. Try to improve next time." << endl;
            break;
        case 'D':
            cout << "You passed, but work harder!" << endl;
            break;
        case 'F':
            cout << "Failed. Don’t give up, study more!" << endl;
            break;
        default:
            cout << "Invalid Grade!" << endl;
    }

    printLine('=', 50);
    cout << setw(30) << "End of Report" << endl;
    printLine('=', 50);

    // Wait for user before exit
    cout << "\nPress any key to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
