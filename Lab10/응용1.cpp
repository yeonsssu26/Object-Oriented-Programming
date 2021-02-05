/*
주어진 main 함수는 학번, 이름, 전공을 입력받아 출력한다.
주어진 코드를 기반으로 아래의 조건에 맞게 CStudent 클래스를 작성하시오.
A. 기본 생성자는 initialization list를 이용하여 초기화함.
B. 학번, 이름, 전공을 파라미터로 받아 초기화하는 생성자도 작성함.
C. 학번, 이름, 전공 각각에 대해 파라미터로 받아서 설정하는 멤버함수 및 클래스 외부로
해당 멤버 변수들을 가져올 수 있도록 하는 멤버함수 설정.
D. 멤버함수 Display는 출력화면과 같이 화면에 출력해야 함.
E. 학번(int), 이름(string), 전공(string) 각각 멤버변수가 존재하고 private으로 설정.
*/
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
	CStudent s1; // A
	s1.Display();
	CStudent s2(1999000000, "공지철", "연극영화과"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;
	return 0;
}