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
		name = "홍길동";
		major = "컴퓨터공학과";
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
		cout << "학번 : " << studNum << endl;
		cout << "이름 : " << name << endl;
		cout << "전공 : " << major << endl << endl;
	}
};
int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	while (1) {
		if (length >= 3) {
			cout << "----모든 입력이 완료되었습니다---" << endl;
			for (int i = 0; i < 3; i++) s[i].Display();
			break;
		}
		cout << length + 1 << "번째 학생 입력" << endl;
		cout << "학번 : ";	cin >> inputNumber;		s[length].setNumber(inputNumber);
		cout << "이름 : ";	cin >> inputName;		s[length].setName(inputName);
		cout << "전공 : ";	cin >> inputMajor;		s[length].setMajor(inputMajor);

		if (length == 0) {
			cout << "※입력완료" << endl << endl;
			length++;
			continue;
		}

		for (int i = 0; i < length; i++) {
			if (s[i].getNumber() == inputNumber) {
				cout << "※중복된 학번이 존재합니다" << endl << endl;
				break;
			}
			if (i == length - 1 && s[i].getNumber() != inputNumber) {
				cout << "※입력완료" << endl << endl;
				length++;
				break;
			}
		}
	}
	return 0;
}