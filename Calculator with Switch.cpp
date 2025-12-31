#include<iostream>
using namespace std;
int main () {
	double num1, num2;
	char operation;
	cout <<"Enter Your First Number.."<<endl;
	cin >> num1;
	cout <<"Enter Your Second Number.."<<endl;
	cin >>num2;
	cout <<"Choose Operator.."<<endl;
	cin >>operation;
	switch(operation) {
		case '+' :
			cout <<"Result =" << num1+num2 << endl;
			break;
		case '-' :
			cout <<"Result =" << num1-num2 << endl;
			break;
		case '*' :
			cout <<"Result =" << num1*num2 << endl;
			break;
		case '/' :
			if (num2==0)
			{
				cout<<"The Number Should nt be Divide By Zero.." << endl;
			}
			else {
			cout <<"Result =" << num1/num2 << endl;
	     	}
			break;
		default:
			cout <<"Invalid Operator !" <<endl;
	}
	return 0;
}
