#include <iostream>
using namespace std;
int main() {
	int num1, num2, swap;
	cout<< "Enter Your First Number=" << endl;
	cin >> num1;
	cout<< "Enter Your Second Number=" <<endl;
	cin >> num2;
	swap = num1;
	num1 = num2;
	num2 = swap;
	cout <<"Values After Swapping.." << endl;
	cout <<"Num 1 =" << num1 <<"  Num 2 =" << num2 << endl;
	return 0;
}
