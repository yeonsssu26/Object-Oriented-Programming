#include <iostream>
#include <string> //string��ü ���
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
using namespace std;
int main() {
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl; //s1�� length, size ���
	cout << s1.empty() << endl;
	s1.clear();// s1 = "";
	cout << s1.empty() << endl;
	s1 = "Good";
	s1 = s1 + "-bye";
	// Good-bye (string)
	// 01234567 (index)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl; // �ΰ��� ������� index 4 �� ���
	cout << (s1=="Good-bye") << endl; // s1�� Good-bye �� (bool �� ���)
	cout << (s1 == "good-bye") << endl; // s1�� good-bye �� (bool �� ���)
	cout << (s1 >= "z") << endl << endl; // s1�� ��z������ ũ�ų� ������ �� (bool �� ���)
	cout << s1.substr(5,3) << endl; // s1�� index 5���� 3���� ���
	cout << s1.substr(2,2) << endl; // s1�� index 2���� 2���� ���
	cout << s1.find("od") << endl; // od ��ġ ���
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2);
	cout << (s1.find("korea") == string::npos) << endl;
	return 0;
}