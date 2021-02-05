/*
0~100 사이의 정수를 랜덤하게 10x10 행렬로 만들고
txt파일을 생성해 그 결과를 확인할 수 있는 프로그램을 작성하라.
(예시출력에 중복허용함)
*/
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include <iomanip>
using namespace std;
int main() {
	ofstream fout("random integer.txt");
	int num;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			num = (rand() % 100) + 1;
			fout << setw(5) << num;
		}
		fout << endl;
	}
	return 0;
}