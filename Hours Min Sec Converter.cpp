#include<iostream>
using namespace std;
int main () 
{
	cout << "My Name Is Abdul Malik.. " << endl;
	//This Is My Name..
	cout << "My Sap-ID Is 72511.." << endl;
	//This Is My Sap-ID..
	int sec;
	cout << "Enter Your Total Seconds.." << endl;
	cin  >> sec;
	int hours = sec/3600;
	int remsec = sec%3600;
	int min = remsec/60;
	int seconds = remsec%60;
	cout << "Hours = " << hours << " Minutes = " << min << " Seconds = " << seconds << endl;
	return 0;
}

