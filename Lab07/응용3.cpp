/*
0~100 ������ ������ �����ϰ� 10x10 ��ķ� �����
txt������ ������ �� ����� Ȯ���� �� �ִ� ���α׷��� �ۼ��϶�.
(������¿� �ߺ������)
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