#include <iostream>
using namespace std;
void print_DOB(int year = 1990, int month = 1, int day = 1);
int main() {
	print_DOB();
	int year, month, day;
	cout << "year �Է� : ";
	cin >> year;
	cout << "month �Է� : ";
	cin >> month;
	cout << "day �Է� : ";
	cin >> day;
	print_DOB(year, month, day);
	return 0;
}
void print_DOB(int year, int month, int day) {
	cout << "��������� " << year << "�� " << month << "�� " << day << "�� �Դϴ�" << endl;
}