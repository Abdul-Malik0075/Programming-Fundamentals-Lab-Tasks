#include <iostream>
using namespace std;

int main() {
    cout << "My Name Is Muhammad Saif" << endl;
    //This Is My Name..
    cout << "My Sap-iD Is 72395" << endl;
    //This Is My Sap-iD..
    double fahrenheit, celsius;
    //Declaring Variables..
    cout << "Enter temperature in Fahrenheit: ";
    // Taking temperature in Fahrenheit from user..
    cin >> fahrenheit;
    celsius = (5.0 / 9.0) * (fahrenheit - 32);
    // Applying the formula: C = (5.0 / 9.0) * (F - 32)
    cout << "Temperature in Celsius is: " << celsius << " °C" << endl;
    // Displaying the result
    return 0;
}

