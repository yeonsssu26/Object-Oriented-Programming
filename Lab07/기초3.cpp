#include <iostream>
using namespace std;
int main() {
	double d1 = 1.23456789;
	cout << d1 << endl;
	cout.width(10); // ��°� ���� 10�� ����
	cout.precision(3); // �ֿ� �ڸ��� 3�ڸ��� ���
	cout << d1 << endl;
	char ch1;
	char ch2;
	// ch1, ch2 : enter �� z��. ( space + z )
	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;
	cin.ignore(); // enter�� ���� cin���� ���� �ʵ��� ����
	cin.unsetf(ios::skipws); // space�� �Է����� �����ϰ� ��
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;
	return 0;
}