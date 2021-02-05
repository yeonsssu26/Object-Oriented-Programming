#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;
// 배열의 경우 주소값(시작주소, 끝주소)을 전달
void print(int* begin, int* end) {
	for (int * curr = begin; curr != end; curr++) //수업시간에 배운 주소값을 기준으로 for문 작성
		cout << setw(4) << *curr;
	cout << endl;
	// while문 구현 부분 - 수업시간에 배운 주소값을 기준으로 while문 작성
	 int* curr = begin;
	 while (curr != end) {
	 cout << setw(4) << *curr;
	 curr++;
	 }
	cout << endl;
}
// (+, -) for pointer: 주소값을 증가/감소 (다음 변수 위치)
int main() {
	int list[3] = { 10, 20, 30 };
	cout << list << '\t' << *list << endl;
	cout << list + 1 << '\t' << *(list + 1) << endl;
	cout << list + 2 << '\t' << *(list + 1) << endl;
	int *begin = list;
	int* end = list + 3;
	print(begin, end);
	return 0;
}