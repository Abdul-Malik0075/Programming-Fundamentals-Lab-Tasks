#include<iostream>
using namespace std;

// Normal function
int add(int a, int b) {
    return a + b;
}

// Inline function
inline int multiply(int a, int b) {
    return a * b;
}

int main() {
	cout<<"ABDUL MALIK"<<endl;
	// NAME
	cout<<"72511"<<endl;
	// Sap-ID
	cout<<"============================================"<<endl;
    cout << "Add: " << add(5, 3) << endl;
    cout << "Multiply: " << multiply(5, 3) << endl;
    
    return 0;
}

