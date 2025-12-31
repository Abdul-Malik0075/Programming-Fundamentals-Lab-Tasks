#include<iostream>
using namespace std;
int main ()
{
	int sum =0;
	int a,b;
	cout<<"Enter Starting Range.. ";
	cin >>a;
	cout<<"Enter Your Ending Range.. ";
	cin >>b;
	for(int i=a;i<=b;i++)
	{
		cout<<i<<endl;
		sum+=i;
	}
	cout<<"Sum = "<<sum<<endl;
}
