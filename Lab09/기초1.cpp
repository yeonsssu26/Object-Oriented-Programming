#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;
// �迭�� ��� �ּҰ�(�����ּ�, ���ּ�)�� ����
void print(int* begin, int* end) {
	for (int * curr = begin; curr != end; curr++) //�����ð��� ��� �ּҰ��� �������� for�� �ۼ�
		cout << setw(4) << *curr;
	cout << endl;
	// while�� ���� �κ� - �����ð��� ��� �ּҰ��� �������� while�� �ۼ�
	 int* curr = begin;
	 while (curr != end) {
	 cout << setw(4) << *curr;
	 curr++;
	 }
	cout << endl;
}
// (+, -) for pointer: �ּҰ��� ����/���� (���� ���� ��ġ)
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