#include <iostream>
using namespace std;
void printmultTBL(int row);
int main() {
	int row = 0;
	while (1) {
		cout << "�� ���� �Է��ϼ��� : ";
		cin >> row;
		if (row == -1) {
			cout << "�����մϴ�" << endl;
			break;
		}
		else if (row >= 1 && row <= 9)
			printmultTBL(row);
		else {
			cout << "1���� 9������ ������ �Է����ּ���" << endl << endl;
			//continue; // continue���� �Ʒ��ڵ带 �������� �ʰ� �ݺ����� ù°�ٷ� jump�ϴ� ���̹Ƿ� �ش��ڵ忡�� �ʿ����
		}
	}
	return 0;
}
void printmultTBL(int row) {
	for (int i = 1; i <= 9; i++)
		cout << row << "*" << i << " = " << row * i << endl;
	cout << endl;
}