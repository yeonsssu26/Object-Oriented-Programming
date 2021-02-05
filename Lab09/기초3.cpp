#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
//�Ҽ� : 1�� �ڱ��ڽ��� �����ϰ�� ����� ���� 1���� ū ����
bool is_prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
		if (n%i == 0)
			return false;// n�� i�� ���� �������� 0�̸� false�� ����
		return true;
}
vector<int> primes(int low, int high) {
	vector<int> result;
	for (int i = low; i <= high; i++)
		if (is_prime(i)) // �Ҽ��̸� (is_prime�� ���̸�) �ڿ� push
			result.push_back(i);
		return result;
}
void print(const vector<int>& v) {
	for (int elem : v) //vector index�� �ƴ� ���Ҹ� �̿��� for��
		cout << setw(4) << elem;
	cout << endl;
}
int main() {
	int low, high;
	cin >> low >> high;
	vector<int> vec = primes(low, high);
	print(vec);
	return 0;
}