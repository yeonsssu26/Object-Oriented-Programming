/*
��� �� ���� ũ�⸦ �Է��Ͽ� ������ �� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
	- ����� 2D Vector �� �̿��Ͽ� ������
	- ����� ��Ҵ� -9 �̻� 9 ������ ���� �� �ϳ��� �������� ������
	- ����� �ʱ�ȭ�ϴ� �Լ�, ����� ����ϴ� �Լ�, ����� ���ϴ� �Լ��� ������
	- ����� ������ �� ������ �����޽����� ����ϰ� ������
	- �� ����� ���� �� ������ �����޽����� ����ϰ� ������
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
	cout << "A�� ��, ���� ũ�⸦ �Է����ּ��� : "; cin >> rowA >> colA;
	cout << "B�� ��, ���� ũ�⸦ �Է����ּ��� : "; cin >> rowB >> colB;
	if (rowA < 1 || colA < 1 || rowB < 1 || colB < 1) cout << "����� ������ �� �����ϴ�." << endl;
	else {
		vector<vector<int>> matA(rowA, vector<int>(colA));
		vector<vector<int>> matB(rowB, vector<int>(colB));
		setMatrix("A", matA, rowA, colA);
		setMatrix("B", matB, rowB, colB);
		cout << "A��� :" << endl;	printMatrix(matA, rowA, colA);
		cout << "B��� :" << endl;	printMatrix(matB, rowB, colB);
		if (colA != rowB) cout << "�� ����� ���� �� �����ϴ�." << endl;
		else {
			vector<vector<int>> mulMat(rowA, vector<int>(colB));
			multMatrix(mulMat, matA, matB, rowA, colA, rowB, colB);
			cout << "AB����� : " << endl; printMatrix(mulMat, rowA, colB);
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
	for (int i = 0; i < rowA; i++) { // �ʱ�ȭ
		for (int j = 0; j < colB; j++)
			mulmat[i][j] = 0;
	}
	for (int row = 0; row < rowA; row++) { // ��İ�
		for (int col = 0, i = 0; col < colB; col++, i++) {
			for (int i = 0; i < colA; i++)
				mulmat[row][col] += matA[row][i] * matB[i][col];
		}
	}
}