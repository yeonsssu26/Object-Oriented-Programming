#include <iostream>
using namespace std;
int main() {
	cout << "Please enter Fahrenheit value : ";
	double F, C;
	cin >> F;
	C = 5.0 / 9.0 * (F - 32);
	cout << "Celsius value is " << C << endl;
	return 0;
}