#include <iostream>
using namespace std;
int main() {
	double d1 = 1.23456789;
	cout << d1 << endl;
	cout.width(10); // 출력값 길이 10로 지정
	cout.precision(3); // 주요 자리수 3자리만 출력
	cout << d1 << endl;
	char ch1;
	char ch2;
	// ch1, ch2 : enter “ z”. ( space + z )
	cin >> ch1;
	cout << "(" << ch1 << ")" << endl;
	cin.ignore(); // enter가 다음 cin으로 들어가지 않도록 해줌
	cin.unsetf(ios::skipws); // space도 입력으로 생각하게 함
	cin >> ch2;
	cout << "(" << ch2 << ")" << endl;
	return 0;
}