#include<iostream>
using namespace std;
int main () {
	char Grade;
	cout << "Enter Your Grade .."<< endl;
	cin >>Grade;
	switch(Grade) {
		case 'A' : case 'a' :
			cout <<"Score is greater than or Equal To 90.."<<endl;
			break;
		case 'B' : case 'b' :
			cout<<"Score is between 80-89.." << endl;
			break;
		case 'C' : case 'c' :
			cout<<"Score is Between 70-79.." <<endl;
			break;
		case 'D' : case 'd' :
			cout<<"Score is Between 60-69.." <<endl;
			break;
		case 'F' : case 'f' :
			cout<<"Score is Below 60.." <<endl;
			break;
		default:
			cout<<"Invalid Text.." <<endl;
	}
	return 0;
}
