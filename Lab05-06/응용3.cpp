/*
����3���� 2���� ������� Ǯ��� �;
������ ���� �����߽��ϴ�.
*/
#include <iostream>
using namespace std;
int sum1(int num);
int sum2(int num);
int main() {
	cout << "number : ";
	int num;
	cin >> num;
	cout << "sum : " << sum1(num) << endl;
	cout << "sum : " << sum2(num) << endl;
	return 0;
}
int sum1(int num) { // AND������ �̿���
	int sum = 0;
	for (int i = 1; i <= num; i++) {
		if (i % 2 != 0 && i % 3 != 0)
			sum += i;
	}
	return sum;
}
int sum2(int num) { // continue���� �̿���
	int sum = 0;
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) continue;
		else if (i % 3 == 0) continue;
		else sum += i;
	}
	return sum;
}