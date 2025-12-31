#include <iostream>
using namespace std;

int main() {
    cout << "My Name Is Muhammad Saif" << endl;
    // This Is My Name..
    cout << "My Sap-iD Is 72395" << endl;
    // This Is My Sap-iD..
    float length, width, height, volume;
    // Step 1: Declare variables
	cout << "Enter length of the cube (in cm): ";
    cin >> length;
    // Step 2: Ask user for input
	cout << "Enter width of the cube (in cm): ";
    cin >> width;
    cout << "Enter height of the cube (in cm): ";
    cin >> height;
    volume = length * width * height;
    // Step 3: Apply formula
    cout << "The volume of the cube is: " << volume << " cm³" << endl;
    // Step 4: Display the result
    return 0;
}

