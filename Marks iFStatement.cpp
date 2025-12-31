#include <iostream>
using namespace std;
int main () {
	int english, urdu, math, total;
	cout << "Enter Marks of English.. " << endl;
	cin >> english;
	cout << "Enter Marks Of Urdu.. " << endl;
	cin >> urdu;
	cout <<"Enter Marks Of Maths..  " << endl;
	cin >>math;
	total = english + urdu + math ;
	if (total>80)
	{
		cout << "You Are Above Standard.." << endl;
		cout << "Admission Granted.." << endl;
	}
	else
	cout<<"You Need To Improve";
	return 0;
	
}
