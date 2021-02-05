#include <iostream>
using namespace std;
void swap(int *A,int *B);
int main() {
	cout << "Please enter two integer values:" << endl;
	int A, B;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	swap(&A, &B);
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
	return 0;
}
void swap(int *A, int *B) {
	int tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}