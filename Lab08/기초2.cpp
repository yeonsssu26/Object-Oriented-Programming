#include<iostream>
using namespace std;
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
// �Լ� func�� �����Ϳ� �Ķ���� x, y�� �޾ƿͼ� �Լ� func�� ���ప�� �������ִ� �Լ�
int evaluate(int(*func)(int, int), int x, int y){
	return func(x, y);
}
int main() {
	int(*func)(int, int);
	func = &sum; // sum �Լ� �ּҰ� ����
	cout << func(10, 20) << endl;
	func = &mult; // mult �Լ� �ּҰ� ����
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;
	return 0;
}