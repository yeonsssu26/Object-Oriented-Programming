#include <iostream>
#include <vector>
using namespace std;
//���� �迭(static array):���α׷� ������ ũ�Ⱑ �����Ǿ� ���� �Ұ�
//���� �迭(dynamic array): ���α׷� ������(run time) �Ҵ�/������ ����
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };
	int length = 3;
	cin >> length; // Ű����κ��� �迭�� ũ�⸦ �Է¹���
	int* list2 = new int[length]; //���� �迭 ����
	// double* list2 = new double[length]
	int* begin = list2;
	int* end = list2 + length;
	for (int* curr = begin; curr != end; curr++)
		cin >> *curr;
	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;
	delete[] list2; //�Ҵ� ����
	return 0;
}