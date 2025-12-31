#include <iostream>
#include <cctype>
using namespace std;
int main()
{
cout<<"My Name Is Abdul Malik <..>"<<endl;
//This is my name <..>
cout<<"My Sap-iD is 72511 <..>"<<endl;
//This is my sap-id	<..>
char messyString[] = "t6H0i9s6.is.999a9.STRING";
char current = messyString[0];
for(int i = 0; current != '\0'; current = messyString[++i]) {
if(isalpha (current))
cout << (char) (isupper (current) ? tolower(current): current);
else if (ispunct (current))
cout<<' ';
}
cout << endl;
return 0;
}
