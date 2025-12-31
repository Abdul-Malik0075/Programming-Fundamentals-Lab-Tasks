#include <iostream>
using namespace std;

int main() {
	cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-iD Is 72511.." << endl;
    // This is My Sap-iD..
    float num1, num2, num3, num4;
    cout << "Enter four numbers: ";
    cin >> num1 >> num2 >> num3 >> num4;
    float sum = num1 + num2 + num3 + num4;
    float avg = sum / 4;
    float product = num1 * num2 * num3 * num4;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;
    cout << "Product = " << product << endl;

    return 0;
}

