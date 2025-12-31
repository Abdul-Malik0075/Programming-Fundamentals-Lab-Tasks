#include<iostream>
using namespace std;
int main () {
	char character;
	cout<<"Enter Your Character " ;
	cin >> character;
	if (character == 'a' || character == 'A' ||
        character == 'e' || character == 'E' ||
        character == 'i' || character == 'I' ||
        character == 'o' || character == 'O' ||
        character == 'u' || character == 'U') 
	{
		cout<< "The Given Character iS Vowel .."<< endl;
	}
	else 
	{
		cout<<"The Given Character iS Not Vowel .." << endl;
	}
	return 0;
}
