#include<iostream>
#include<iomanip> // setw등 cout 표현을 멋지게
using namespace std;
int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale("")); // 세 자리(1,000)마다 쉼표 찍기위함.
	while (count <= 20) {
		num *= 2;
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}
	return 0;
}