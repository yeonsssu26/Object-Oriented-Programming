#include<iostream>
#include<iomanip> // setw�� cout ǥ���� ������
using namespace std;
int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale("")); // �� �ڸ�(1,000)���� ��ǥ �������.
	while (count <= 20) {
		num *= 2;
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}
	return 0;
}