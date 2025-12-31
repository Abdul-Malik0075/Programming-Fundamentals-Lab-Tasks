#include <iostream>
using namespace std;
int main() {
    int age;
    cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-iD Is 72511.." << endl;
    // This is My Sap-iD..
    cout << "Enter your age in years: ";
    cin >> age;

    int months = age * 12;
    int days = age * 365;

    cout << "Your age in months is: " << months << endl;
    cout << "Your age in days is: " << days << endl;

    return 0;
}

