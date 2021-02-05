#include <iostream>
#include <vector> // 빠른 search, 느린 pop/push
#include <list> // 느린 search, 빠른 pop/push
using namespace std;
int main() {
	list<int> myList{ 1, 2, 3, 4 };
	char command;
	int inputVal;
	bool finished = false;
	while (!finished) {
		//command를 입력받음
		cout << "I)nput, P)rint, L)ength, E)mpty, Q)uit>>";
		cin >> command;
		//command에따라 기능 수행
		switch (command) {
		case 'I':
		case 'i':
			cin >> inputVal;
			myList.push_back(inputVal); // push_back 구현
			break;
		case 'P':
		case 'p':
			for (int elem : myList) // simplified for로 list출력 구현
				cout << elem << ' ';
			cout << endl;
			break;
		case 'L':
		case 'l':
			cout << "Number of items: " << myList.size() << endl;
			break;
		case 'E':
		case 'e':
			myList.empty();
			break;
		case 'Q':
		case 'q':
			finished = true;
			cout << "Exit the program" << endl;
			break;
		default:
			cout << "Wrong command" << endl;
			break;
		}
	}
	return 0;
}