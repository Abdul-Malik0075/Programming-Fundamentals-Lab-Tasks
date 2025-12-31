#include<iostream>
#include<cmath>
using namespace std;
int main () {
	cout<<"My Name Is Abdul Malik.."<<endl;
	//This Is My Name..
	cout<<"My Sap-ID is 72511.."<<endl;
	//This Is My Sap-ID..
	int choice;
	int num1,num2;
	float num3,num4;
	double num;
	cout << "<<<<< Scientific Calculator >>>>>"<<endl;
    cout << "1. Addition of two Integers"<<endl;
    cout << "2. Subtraction of two Integers"<<endl;
    cout << "3. Multiplication of two Integers"<<endl;
    cout << "4. Division of two Integers"<<endl;
    cout << "5. Addition of two Floating Numbers"<<endl;
    cout << "6. Subtraction of two Floating Numbers"<<endl;
    cout << "7. Multiplication of two Floating Numbers"<<endl;
    cout << "8. Division of two Floating Numbers"<<endl;
    cout << "9. Sine (sin)"<<endl;
    cout << "10. Cosine (cos)"<<endl;
    cout << "11. Tangent (tan)"<<endl;
    cout << "12. Square Root"<<endl;
    cout << "13. Square"<<endl;
    cout << "14. Cube"<<endl;
    cout << "Enter your choice From 1-14:"<<endl;
    cin  >>  choice;
    switch (choice)
    {
    case 1 :
    	cout << "Enter Two Integers.. " <<endl;
    	cin  >> num1>>num2;
    	cout << "Result = " << num1+num2<<endl;
    	break;
    case 2 :
    	cout << "Enter Two Integers.. " <<endl;
    	cin  >> num1>>num2;
    	cout << "Result = " << num1-num2 <<endl;
    	break;
    case 3 :
    	cout << "Enter Two Integers.. " <<endl;
    	cin  >> num1>>num2;
    	cout << "Result = " << num1*num2 <<endl;
    	break;
    case 4 :
    	cout << "Enter Two Integers.. " <<endl;
    	cin  >> num1>>num2;
    	if (num2 == 0)
    	{
    		cout << " The Number Should Not Be Divided By 0 .. " << endl;
		}
		else 
    	cout << "Result = " << num1/num2;
    	break;
    case 5 :
    	cout << "Enter Two Floating Numbers.. " <<endl;
    	cin  >> num3>>num4;
    	cout << "Result = " << num3+num4;
    	break;
    case 6 :
    	cout << "Enter Two Floating Numbers.. " <<endl;
    	cin  >> num3>>num4;
    	cout << "Result = " << num3-num4;
    	break;
    case 7 :
    	cout << "Enter Two Floating Numbers.. " <<endl;
    	cin  >> num3>>num4;
    	cout << "Result = " <<num3*num4;
    	break;
    case 8 :
    	cout << "Enter Two Floating Numbers.. " <<endl;
		cin  >>	num3>>num4;
		if (num4 == 0)
		{
			cout << "The Number Should Not Be Divided By 0 .." <<endl;
		}
		else
		cout << "Result = " <<num3/num4;
		break;
	case 9 :
		cout << "Enter Angle In Degrees.. " <<endl;
		cin  >> num;
		cout << "sin(" << num << ") = " << sin(num*M_PI/180) <<endl;
		break;
	case 10 :
		cout << "Enter Angle In Degrees.. " <<endl;
		cin  >> num;
		cout << "cos(" << num << ") = " << cos(num*M_PI/180) <<endl; 
		break;
	case 11 :
		cout << "Enter Angle In Degrees.. " <<endl;
		cin  >> num;
		cout << "Tan(" << num << ") = " << tan (num*M_PI/180) <<endl;
		break;
	case 12 :
		cout << "Enter Your Number.. " <<endl;
		cin  >> num;
		if (num >=0 )
		{
		cout << "Square Root = " <<sqrt(num) ;
        }
	    else 
	    cout << "Error: Cannot take square root of a negative number.. " <<endl;
		break;
	case 13 :
		cout << "Enter Your Number.. " <<endl;
		cin  >> num;
		cout << "Square Of Number is = " << num*num <<endl;
		break;
	case 14 :
		cout << "Enter Your Number.. " <<endl;
		cin  >> num;
		cout << "Cube Of Number is = " << num*num*num <<endl;
		break;
	default :
		cout << " Error! Enter A Valid Number.. " << endl;
    }
    return 0;
}
