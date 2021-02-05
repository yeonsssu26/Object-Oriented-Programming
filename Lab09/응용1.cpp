/*
행렬 두 개의 크기를 입력하여 생성된 두 행렬의 곱을 출력하는 프로그램을 작성하시오
	- 행렬은 2D Vector 를 이용하여 선언함
	- 행렬의 요소는 -9 이상 9 이하의 정수 중 하나를 랜덤으로 설정함
	- 행렬을 초기화하는 함수, 행렬을 출력하는 함수, 행렬을 곱하는 함수를 구현함
	- 행렬을 생성할 수 없으면 오류메시지를 출력하고 종료함
	- 두 행렬을 곱할 수 없으면 오류메시지를 출력하고 종료함
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void setMatrix(string name, vector<vector<int>>& mat, int row, int col);
void printMatrix(const vector<vector<int>>& mat, int row, int col);
void multMatrix(vector<vector<int>> &mulmat, vector<vector<int>> matA, vector<vector<int>> matB, int rowA, int colA, int rowB, int colB);
int main() {
	int rowA, colA, rowB, colB;
	cout << "A의 행, 열의 크기를 입력해주세요 : "; cin >> rowA >> colA;
	cout << "B의 행, 열의 크기를 입력해주세요 : "; cin >> rowB >> colB;
	if (rowA < 1 || colA < 1 || rowB < 1 || colB < 1) cout << "행렬을 생성할 수 없습니다." << endl;
	else {
		vector<vector<int>> matA(rowA, vector<int>(colA));
		vector<vector<int>> matB(rowB, vector<int>(colB));
		setMatrix("A", matA, rowA, colA);
		setMatrix("B", matB, rowB, colB);
		cout << "A행렬 :" << endl;	printMatrix(matA, rowA, colA);
		cout << "B행렬 :" << endl;	printMatrix(matB, rowB, colB);
		if (colA != rowB) cout << "두 행렬을 곱할 수 없습니다." << endl;
		else {
			vector<vector<int>> mulMat(rowA, vector<int>(colB));
			multMatrix(mulMat, matA, matB, rowA, colA, rowB, colB);
			cout << "AB곱행렬 : " << endl; printMatrix(mulMat, rowA, colB);
		}
	}
	return 0;
}
void setMatrix(string name, vector<vector<int>>& mat, int row, int col) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			mat[i][j] = rand() % 19 - 9;
	}
}
void printMatrix(const vector<vector<int>>& mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << setw(6) << mat[i][j];
		cout << endl;
	} cout << endl;
}
void multMatrix(vector<vector<int>> &mulmat, vector<vector<int>> matA, vector<vector<int>> matB, int rowA, int colA, int rowB, int colB) {
	for (int i = 0; i < rowA; i++) { // 초기화
		for (int j = 0; j < colB; j++)
			mulmat[i][j] = 0;
	}
	for (int row = 0; row < rowA; row++) { // 행렬곱
		for (int col = 0, i = 0; col < colB; col++, i++) {
			for (int i = 0; i < colA; i++)
				mulmat[row][col] += matA[row][i] * matB[i][col];
		}
	}
}