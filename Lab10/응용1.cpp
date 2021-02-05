/*
�־��� main �Լ��� �й�, �̸�, ������ �Է¹޾� ����Ѵ�.
�־��� �ڵ带 ������� �Ʒ��� ���ǿ� �°� CStudent Ŭ������ �ۼ��Ͻÿ�.
A. �⺻ �����ڴ� initialization list�� �̿��Ͽ� �ʱ�ȭ��.
B. �й�, �̸�, ������ �Ķ���ͷ� �޾� �ʱ�ȭ�ϴ� �����ڵ� �ۼ���.
C. �й�, �̸�, ���� ������ ���� �Ķ���ͷ� �޾Ƽ� �����ϴ� ����Լ� �� Ŭ���� �ܺη�
�ش� ��� �������� ������ �� �ֵ��� �ϴ� ����Լ� ����.
D. ����Լ� Display�� ���ȭ��� ���� ȭ�鿡 ����ؾ� ��.
E. �й�(int), �̸�(string), ����(string) ���� ��������� �����ϰ� private���� ����.
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
	CStudent s1; // A
	s1.Display();
	CStudent s2(1999000000, "����ö", "���ؿ�ȭ��"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("�ΰ���");
	s1.setMajor("����Ʈ���");
	cout << "�й� :" << s1.getNumber() << endl;
	cout << "�̸� :" << s1.getName() << endl;
	cout << "���� :" << s1.getMajor() << endl;
	return 0;
}