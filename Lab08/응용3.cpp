#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
void backward(vector<int>& vec);
int main() {
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "기본 vector 값 : ";
	for (int elem : vec)
		cout << setw(3) << elem;
	cout << endl;
	backward(vec);
	cout << "함수 실행 후 vector 값 : ";
	for (int elem : vec)
		cout << setw(3) << elem;
	cout << endl;
	return 0;
}
void backward(vector<int>& vec) {
	; int tmp, half = vec.size() / 2;
	if (vec.size() % 2 == 0) {
		for (int i = 0; i < half; i++) {
			tmp = vec.at(half + i);
			vec.at(half + i) = vec.at(half - (i+1));
			vec.at(half - (i+1)) = tmp;
		}
	}
	else {
		for (int i = 1; i <= half; i++) {
			tmp = vec.at(half + i);
			vec.at(half + i) = vec.at(half - i);
			vec.at(half - i) = tmp;
		}
	}
}