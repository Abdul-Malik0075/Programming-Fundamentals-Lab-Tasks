#include<iostream>
using namespace std;
// Formal parameters
void greet(string name) {  // NAME is formal parameter
    cout << "Hello " << name << endl;
}

int main() {
	cout<<"ABDUL MALIK"<<endl;
	// This is My Name <..>
	cout<<"72511"<<endl;
	// This is My Sap-ID <..>
	cout<<"======================================"<<endl;
    string userName = "NAME";
    greet(userName);  // userName is actual parameter
    
    greet("ABDUL MALIK");    // ABDUL MALIK is actual parameter
    
    return 0;
}

