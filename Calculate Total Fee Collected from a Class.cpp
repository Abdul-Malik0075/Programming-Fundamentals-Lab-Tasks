#include <iostream>
using namespace std;

int main() {
	cout << "My Name Is AbdulMalik" << endl;
    // This Is My Name..
    cout << "My Sap-iD Is 72511.." << endl;
    int totalStudents;
    float feePerStudent, totalFee;
	cout << "Enter total number of students in the class: ";
    cin >> totalStudents;
    cout << "Enter fee per student: ";
    cin >> feePerStudent;
    totalFee = totalStudents * feePerStudent;
	cout << endl;
    cout << "Total number of students: " << totalStudents << endl;
    cout << "Fee per student: " << feePerStudent << endl;
    cout << "Total fee collected from the class is: " << totalFee << endl;
    return 0;
}

