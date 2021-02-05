#include <iostream>
using namespace std;
/*
sizeof()의 기능
메모리 공간에서 소모하는 메모리의 크기를 바이트 단위로 계산하여 반환합니다
*/
int main() {
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
	return 0;
}