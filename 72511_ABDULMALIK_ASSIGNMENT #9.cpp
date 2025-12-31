#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int main() 
{
	cout<<"My Name Is Abdul Malik <..>"<<endl;
	//This is my name <..>
	cout<<"My Sap-iD is 72511 <..>"<<endl;
	//This is my sap-id	<..>
    double num1, num2;
    int choice;
    cout<<setfill('=')<<setw(60)<<""<<endl;
    cout<<setfill(' ')<<setw(30)<<"CALCULATOR "<<endl;
    cout<<setfill('=')<<setw(60)<<""<<endl; 
    cout << "ENTER THE FIRST NUMBER : ";
    cin >> num1;
    cout << "ENTER THE SECOND NUMBER : ";
    cin >> num2;
    cout << "SELECT AN OPERATION"<<endl;
    cout << "1. (+)  ADDITION"<<endl;
    cout << "2. (-)  SUBTRACTION"<<endl;
    cout << "3. (*)  MULTIPLICATION"<<endl;
    cout << "4. (/)  DIVISION"<<endl;
    cout<<setfill('=')<<setw(60)<<""<<endl;
    cout <<setfill(' ')<<setw(30)<<"ENTER YOUR CHOICE"<<endl;
    cout<<setfill('=')<<setw(60)<<""<<endl;
    cin >> choice;
    switch (choice){
        case 1:
            cout<<"RESULT : "<<add(num1, num2);
            break;
        case 2:
            cout<<"RESULT : "<<subtract(num1,num2);
            break;
        case 3:
            cout<<"RESULT : "<<multiply(num1,num2);
            break;
        case 4:
            if (num2==0)
                cout <<"NUMBER SHOULD'NT BE DIVIDED BY ZERO";
            else
                cout<<"RESULT : "<<divide(num1,num2);
            break;
        default:
            cout<<"INVALID CHOICE!";
            break;
    }
    return 0;
}
double add(double a,double b){
    return a+b;
}
double subtract(double a,double b){
    return a-b;
}
double multiply(double a,double b){
    return a*b;
}
double divide(double a,double b){
    return a/b;
}

