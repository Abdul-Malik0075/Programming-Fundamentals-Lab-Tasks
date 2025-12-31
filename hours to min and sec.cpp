#include <iostream>
using namespace std;

int main() {
    cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-ID Is 72511" << endl;
    // This Is My Sap-ID..
    float hours, minutes, seconds;
    //Declare variables
    cout << "Enter time duration in hours: ";
    cin >> hours;
    //Get input from user
    minutes = hours * 60;
    seconds = hours * 3600;
    //Convert hours to minutes and seconds
    cout << "--------------------------------------" << endl;
    cout << "Time in Minutes = " << minutes << " minutes" << endl;
    cout << "Time in Seconds = " << seconds << " seconds" << endl;
    //Display result
    return 0;
}

