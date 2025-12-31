#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	string msg = "My Name iS Abdul Malik..";
	double value = 123.456789;
	cout << setfill('*') << setw(25) << msg << endl;
	cout << setfill('@') << setw(20) << msg << endl;
	cout << setfill('=') << setw(16)<< msg << endl;
	cout << endl << "Using setprecision:" << endl;
	cout << fixed << setprecision(2);
	cout << "Value with 2 decimal:" << value << endl;
	cout << fixed << setprecision(4);
	cout << "Value with 4 decimal places: " << value << endl;
	return 0;
}
