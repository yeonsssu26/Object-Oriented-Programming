#include <iostream>
using namespace std;
int square(int input); // �Լ�����
int main() {
	int x;
	x = 5;
	cout << square(x) << endl; // ������
	return 0;
}
int square(int input) { // �Լ�����
	int res = input * input;
	return res;
}