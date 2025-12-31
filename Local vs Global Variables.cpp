#include<iostream>
using namespace std;

// Global variable
int score = 100;

void game() {
    // Local variable
    int points = 50;
    score = score + points;
    cout << "Points: " << points << endl;
}

int main() {
	cout<<"ABDUL MALIK"<<endl;
	// Name
	cout<<"72511"<<endl;
	// Sap-ID
	cout<<"====================================="<<endl;
    int age = 20;  // Local to main
    
    cout << "Age: " << age << endl;
    game();
    cout << "Score: " << score << endl;
    
    return 0;
}
