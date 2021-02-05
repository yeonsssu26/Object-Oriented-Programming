#include <iostream>
using namespace std;
int get_data();
void swap_call_by_value(int num1, int num2);
void swap_call_by_reference(int &num1, int &num2);
int main() {
	int x, y;
	cout << "x �Է� : ";
	x = get_data();
	cout << "y �Է� : ";
	y = get_data();
	cout << "swap_call_by_value�Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x,y);
	cout << "swap_call_by_value�Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	cout << "swap_call_by_referencee�Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x,y);
	cout << "swap_call_by_reference�Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	return 0;
}
int get_data() {
	int input;
	cin >> input;
	return input;
}
void swap_call_by_value(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void swap_call_by_reference(int &num1, int &num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}