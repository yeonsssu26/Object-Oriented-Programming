#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
bool is_prime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++) {
		if (num%i == 0) // num을 i로 나눈 나머지가 0이면 false 리턴
			return false;
	}
	return true;
}
vector<int> primes(int lower, int upper) {
	vector<int> v;
	for (int i = lower; i <= upper; i++) {
		if (is_prime(i) == true) // 소수이면(is_prime이 참이면) 뒤에 push
			v.push_back(i);
	}
	return v;
}
int main() {
	int lower = 10, upper = 100;
	vector<int> vec = primes(lower, upper); // 벡터 vec 선언 및 primes로 대입
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;
	return 0;
}