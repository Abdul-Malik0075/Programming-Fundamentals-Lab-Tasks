#include<iostream>
using namespace std;
int main() {
	cout <<"My Name Is Abdul Malik.." << endl;
	cout <<"My Sap-iD is 72511.." << endl;
	int english, urdu, math, total;
	cout<< "Enter Your English Marks = " ;
	cin >> english;
	cout <<"Enter Your Urdu Marks = ";
	cin >>urdu;
	cout << "Enter Your Maths Marks =";
	cin >> math;
	total=english+urdu+math;
	if (total/3 >=80)
	{
		cout<<"You are above Standard.."<< endl <<"Admission Granted.." << endl;
	} 
	return 0;
}
	
