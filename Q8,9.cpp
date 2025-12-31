#include <iostream>
using namespace std;
int main() {
    //Q8
	cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-ID Is 72511" << endl;
    // This Is My Sap-ID..
    cout << "Q8: Convert Hours into Minutes and Seconds" << endl;
    float hours, minutes, seconds;
    cout << "Enter time duration in hours: ";
    cin >> hours;
    // Step 1: Input hours
	minutes = hours * 60;
    seconds = hours * 3600;
    // Step 2: Apply conversion formulas
    cout << "Time in Minutes = " << minutes << " minutes" << endl;
    cout << "Time in Seconds = " << seconds << " seconds" << endl;
    // Step 3: Display results
    //Q9
    cout << "Q9: Convert Days into Weeks and Remaining Days" << endl;
    int totalDays, weeks, remainingDays;
    cout << "Enter total number of days: ";
    cin >> totalDays;
    // Step 1: Input total days
    weeks = totalDays / 7;
    remainingDays = totalDays % 7;
    // Step 2: Apply conversion logic
    cout << "Weeks = " << weeks << endl;
    cout << "Remaining Days = " << remainingDays << endl;
    // Step 3: Display results
    cout << "--------------------------------------" << endl;
    cout << "Program completed successfully!" << endl;
    return 0;
}

