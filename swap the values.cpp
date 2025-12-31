#include<iostream>
using namespace std;
int main() {
	cout <<"My Name Is Abdul Malik.." << endl;
	cout <<"My Sap-iD is 72511.." << endl;
	int num1, num2, swap;
	cout<<"Enter Your First Number= " ;
	cin>>num1;
	cout<<"Enter Your Second Number= ";
	cin >> num2;
	swap=num1;
	num1=num2;
	num2=swap;
	cout<<"Values After Swapping.." << endl;
	cout<<"First Number=" << num1 << endl;
	cout<<"Second Number=" << num2 << endl;
	return 0;
}
