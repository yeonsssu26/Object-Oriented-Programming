#include <iostream>
using namespace std;
void checkOddEven(int num);
int main() {
	int num;
	for (int cnt = 1; cnt <= 5; cnt++) {
		cout << cnt << "��° ���� : ";
		cin >> num;
		checkOddEven(num);
	}
	return 0;
}
void checkOddEven(int num) {
	if (num % 2 == 0)
		cout << num << "��(��) ¦���Դϴ�." << endl;
	else
		cout << num << "��(��) Ȧ���Դϴ�." << endl;
}