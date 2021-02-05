#include <iostream>
#include <string>
using namespace std;
class CStudent {
private:
	int studNum;
	string name;
	string major;
public:
	CStudent() {
		studNum = 2018000000;
		name = "ȫ�浿";
		major = "��ǻ�Ͱ��а�";
	}
	CStudent(int _studNum, string _name, string _major) {
		studNum = _studNum;
		name = _name;
		major = _major;
	}
	void setNumber(int _studNum) { studNum = _studNum; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }
	int getNumber() { return studNum; }
	string getName() { return name; }
	string getMajor() { return major; }
	void Display() {
		cout << "�й� : " << studNum << endl;
		cout << "�̸� : " << name << endl;
		cout << "���� : " << major << endl << endl;
	}
};
int main() {
	CStudent s[3]; // 3���� �л������� ������ class �迭
	int inputNumber; // Ű����� �й��� �Է� ���� ����
	string inputName, inputMajor; // Ű����� �̸�, ������ �Է� ���� ����
	int length = 0; // ���� �Էµ� �л��� ��
	while (1) {
		if (length >= 3) {
			cout << "----��� �Է��� �Ϸ�Ǿ����ϴ�---" << endl;
			for (int i = 0; i < 3; i++) s[i].Display();
			break;
		}
		cout << length + 1 << "��° �л� �Է�" << endl;
		cout << "�й� : ";	cin >> inputNumber;		s[length].setNumber(inputNumber);
		cout << "�̸� : ";	cin >> inputName;		s[length].setName(inputName);
		cout << "���� : ";	cin >> inputMajor;		s[length].setMajor(inputMajor);

		if (length == 0) {
			cout << "���Է¿Ϸ�" << endl << endl;
			length++;
			continue;
		}

		for (int i = 0; i < length; i++) {
			if (s[i].getNumber() == inputNumber) {
				cout << "���ߺ��� �й��� �����մϴ�" << endl << endl;
				break;
			}
			if (i == length - 1 && s[i].getNumber() != inputNumber) {
				cout << "���Է¿Ϸ�" << endl << endl;
				length++;
				break;
			}
		}
	}
	return 0;
}