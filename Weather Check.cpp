#include<iostream>
using namespace std;
int main () 
{
	int temp;
	cout << "Enter Your Temperature .." << endl; 
	cin>> temp;
	if (temp > 35)
	{
		cout<<"It Is Hot Today.."<< endl;
	}
	else if (temp > 25 && temp < 35 )
	{
		cout << "It Is a Pleasant Day.."<<endl;
	}
	else if (temp < 25)
	{
		cout <<"It Is Cold Today.." << endl;
	}
	return 0;
}
