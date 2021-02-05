#include <iostream>
using namespace std;
void square(int* num);
int main() {
	int num;
	cout << "input> ";
	cin >> num;
	square(&num);
	cout << "Á¦°ö°ª> " << num << endl;
	return 0;
}
void square(int* num) {
	*num = (*num) * (*num);
}