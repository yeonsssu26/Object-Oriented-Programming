#include<iostream>
#include<vector>
using namespace std;
void print(const vector<int>& v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}
int main() {
	// �ε��� 0 1 2
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100; // vector �ε��� 0���� ���� ����
	vec.at(1) = 200; // vector�� at() �Լ� �̿�
	print(vec);

	vec.push_back(400); // vector�� push_back() �Լ� �̿�
	print(vec);

	vec.pop_back(); // vector�� pop_back() �Լ� �̿�
	print(vec);
	cout << endl;

	// ������� for���� �̿��� vector ���Ұ� �ٲٱ� (�����̵� p.26 ����)
	for (int& elem : vec) {
		cout << "enter an element of vector v: ";
		cin >> elem;
	}
	cout << endl << "[ vector v ]" << endl;
	// ������� for���� �̿��� ȭ�� ����ϱ� (�����̵� p.26 ����)
	for (int elem : vec)
		cout << elem << "\t";
	cout << endl;
	return 0;
}