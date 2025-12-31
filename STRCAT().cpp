#include <iostream>
#include <cstring>
using namespace std;
int main() {
	cout<<"NAME : ";
	cout<<"\n    ABDUL MALIK\n";
	cout<<"Sap-ID:";
	cout<<"\n     72511\n";
	cout<<endl;
    char str1[7] = "Hello ";
    char str2[6] = "World";
    strcat(str1, str2);
    cout << "strcat: " << str1 << endl;
    return 0;
}
