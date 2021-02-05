#include <iostream>
#include <string> //string객체 사용
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
using namespace std;
int main() {
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl; //s1의 length, size 출력
	cout << s1.empty() << endl;
	s1.clear();// s1 = "";
	cout << s1.empty() << endl;
	s1 = "Good";
	s1 = s1 + "-bye";
	// Good-bye (string)
	// 01234567 (index)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl; // 두가지 방법으로 index 4 값 출력
	cout << (s1=="Good-bye") << endl; // s1과 Good-bye 비교 (bool 값 출력)
	cout << (s1 == "good-bye") << endl; // s1과 good-bye 비교 (bool 값 출력)
	cout << (s1 >= "z") << endl << endl; // s1이 “z”보다 크거나 같은지 비교 (bool 값 출력)
	cout << s1.substr(5,3) << endl; // s1의 index 5부터 3글자 출력
	cout << s1.substr(2,2) << endl; // s1의 index 2부터 2글자 출력
	cout << s1.find("od") << endl; // od 위치 출력
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2);
	cout << (s1.find("korea") == string::npos) << endl;
	return 0;
}