#include <iostream>
#include <cmath>
using namespace std;
int GCD(int num1, int num2);
int main() {
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "gcd(" << x << "," << y << ")" << " = " << GCD(x, y) << endl;
	return 0;
}
int GCD(int num1, int num2) {
	int res = abs(num1 - num2);
	if (res == 0)
		return num2;
	else {
		if (num1 > num2)
			return GCD(num2, res);
		else
			return GCD(num1, res);
	}
}