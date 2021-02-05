#include <iostream>
using namespace std;
void checkOddEven(int num);
int main() {
	int num;
	for (int cnt = 1; cnt <= 5; cnt++) {
		cout << cnt << "번째 정수 : ";
		cin >> num;
		checkOddEven(num);
	}
	return 0;
}
void checkOddEven(int num) {
	if (num % 2 == 0)
		cout << num << "은(는) 짝수입니다." << endl;
	else
		cout << num << "은(는) 홀수입니다." << endl;
}