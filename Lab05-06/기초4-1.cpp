#include<iostream>
using namespace std;
int main() {
	int num;
	while (true) {
		cout << "Enter the number (0, 10]: ";
		cin >> num;
		if (num > 0 && num <= 10) break;
	}
	cout << "Success!" << endl;
	return 0;
}