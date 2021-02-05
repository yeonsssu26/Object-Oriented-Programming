#include<iostream>
#include<vector>
using namespace std;
void print(const vector<int>& v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}
int main() {
	// 인덱스 0 1 2
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100; // vector 인덱스 0번에 직접 대입
	vec.at(1) = 200; // vector의 at() 함수 이용
	print(vec);

	vec.push_back(400); // vector의 push_back() 함수 이용
	print(vec);

	vec.pop_back(); // vector의 pop_back() 함수 이용
	print(vec);
	cout << endl;

	// 범위기반 for문을 이용한 vector 원소값 바꾸기 (슬라이드 p.26 참고)
	for (int& elem : vec) {
		cout << "enter an element of vector v: ";
		cin >> elem;
	}
	cout << endl << "[ vector v ]" << endl;
	// 범위기반 for문을 이용한 화면 출력하기 (슬라이드 p.26 참고)
	for (int elem : vec)
		cout << elem << "\t";
	cout << endl;
	return 0;
}