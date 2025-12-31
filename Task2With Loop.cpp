#include<iostream>
using namespace std;
int main ()
{
	cout<<"My Name Is Abdul Malik.. "<<endl;
	//This Is My Name..
	cout<<"My Sap-ID Is 72511.. "<<endl;
	//This Is My Sap-ID..
	int marks[10];
	int total=0;
	float avg;
	for(int i=0;i<10;i++)
	{
		cout<<"Enter The Marks Of Quiz ("<<i+1<<") = ";
		cin >>marks[i];
	}
	for(int i=0;i<10;i++)
	{
		total +=marks[i];
	}
	avg = total/10.0;
	cout<<"Total = "<<total<<endl;
	cout<<"Average = "<<avg<<endl;
	return 0;
}
