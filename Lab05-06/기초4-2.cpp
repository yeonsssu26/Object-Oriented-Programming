#include<iostream>
using namespace std;
int main() {
	int num;
	do {
		cout << "Enter the number (0,10]: ";
		cin >> num;
		if (num > 0 && num <= 10) break;
	} while (true); //¹Ýµå½Ã ¼¼¹ÌÄÝ·Ð Âï¾îÁÜ
	cout << "Success!" << endl;
	return 0;
}