#include <iostream>
using namespace std;
void printmultTBL(int row);
int main() {
	int row = 0;
	while (1) {
		cout << "단 수를 입력하세요 : ";
		cin >> row;
		if (row == -1) {
			cout << "종료합니다" << endl;
			break;
		}
		else if (row >= 1 && row <= 9)
			printmultTBL(row);
		else {
			cout << "1부터 9까지의 정수를 입력해주세요" << endl << endl;
			//continue; // continue문은 아래코드를 실행하지 않고 반복문의 첫째줄로 jump하는 것이므로 해당코드에서 필요없음
		}
	}
	return 0;
}
void printmultTBL(int row) {
	for (int i = 1; i <= 9; i++)
		cout << row << "*" << i << " = " << row * i << endl;
	cout << endl;
}