#include<iostream>
using namespace std;
int main() {
	cout <<"My Name Is Abdul Malik.." << endl;
	//This is My name..
	cout <<"My Sap-iD is 72511.." << endl;
	//This is My Sap-iD..
	int num1,num2,num3 ;
	cout << "enter first number " ;
	cin >> num1 ;
	cout << "enter second number " ;
	cin >> num2 ;
	cout << "enter third number " ;
	cin >> num3 ;
	
	if (num1 >= num2 && num1 >= num3)
	{
		cout << "number 1 is maximum " ;
	}
	else if (num2>= num1 && num2>= num3)
	{
		cout << "number 2 is maximum";
	}
	else {
		   cout <<"number 3 is maximum" ;
	}
	return 0 ;
}
	
