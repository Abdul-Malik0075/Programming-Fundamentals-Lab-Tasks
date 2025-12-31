#include<iostream>
using namespace std;
int main ()
{
	cout<<"My Name Is AbdulMalik.. "<<endl;
	//This Is My Name..
	cout<<"My Sap-ID Is 72511.. "<<endl;
	//This Is My Sap-ID..
	int sallary[6];
	for(int i=0;i<6;i++)
	{
		cout<<"Enter The Sallary ("<<i+1<<") = ";
		cin >> sallary[i];
	}
	cout<<"Sallaries Are Listed Below .. "<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<"Sallary("<<i+1<<") = "<<sallary[i]<<endl;
	}
	return 0;
}
