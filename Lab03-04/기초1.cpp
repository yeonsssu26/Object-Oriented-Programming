#include <iostream>
using namespace std;
int square(int input); // 함수선언
int main() {
	int x;
	x = 5;
	cout << square(x) << endl; // 결과출력
	return 0;
}
int square(int input) { // 함수정의
	int res = input * input;
	return res;
}