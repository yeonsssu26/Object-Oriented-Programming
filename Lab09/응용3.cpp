#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void make_arr(int* arr, int size); // 배열생성함수
void print_arr(int* arr, int size); // 배열출력함수
bool check_dup(int* arr, int size); // 중복검사함수
int main() {
	int num, size;
	while (true) {
		cout << "please enter a number : ";
		cin >> num;
		if (num < 2) {
			cout << "wrong number" << endl;
			break;
		}
		else {
			size = num / 2;
			cout << "size of random array : " << size << endl;
			int* arr = new int[size];
			make_arr(arr, size);
			print_arr(arr, size);
			if(!check_dup(arr, size)) cout << "dupilicates not found." << endl;
			else cout << "duplicates found." << endl;
			delete[] arr;
		}
		cout << endl;
	}
	return 0;
}
void make_arr(int* arr, int size) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size + 1;
	}
}
void print_arr(int* arr, int size) {
	cout << "[ Array ]" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
bool check_dup(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] == arr[j]) return true; // 중복있음
		}
	}
	return false; // 중복없음
}