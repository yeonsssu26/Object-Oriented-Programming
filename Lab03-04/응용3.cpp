#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	double x, y;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "rounding up number of " << x << ": " << ceil(x) << endl;
	cout << "rounding down number of " << x << ": " << floor(x) << endl;
	cout << "rounding number of " << x << ": " << round(x) << endl;
	cout << "maximum number between " << x << " and " << y << ": " << max(x, y) << endl;
	cout << y << "-th root of " << x << ": " << pow(x,1/y) << endl;
	cout << "|" << x << " - " << y << "| = " << abs(x-y) << endl;
	return 0;
}