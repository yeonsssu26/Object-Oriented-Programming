#include <iostream>
#include <string>
using namespace std;
void changeString(string* str) {
	cout << "input> ";
	cin >> *str;
}
int main() {
	string str = "This is default value";
	cout << "�⺻�� ���> " << str << endl;
	changeString(&str);
	cout << "��ȯ�� �� ���> " << str << endl;
	return 0;
}