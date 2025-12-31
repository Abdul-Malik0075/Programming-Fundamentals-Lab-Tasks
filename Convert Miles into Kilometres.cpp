#include <iostream>
using namespace std;

int main() {
    cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-iD Is 72511.." << endl;
    // This is My Sap-iD..
	double miles, kilometres;
    cout << "Please enter the distance in miles: ";
    cin >> miles;
    kilometres = miles * 1.069;
    cout << endl;
    cout << "You entered " << miles << " miles." << endl;
    cout << "That is equal to " << kilometres << " kilometres." << endl;
    return 0;
}

