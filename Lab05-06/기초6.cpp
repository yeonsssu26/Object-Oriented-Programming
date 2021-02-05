#include <iostream>
using namespace std;
int main() {
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch (key) {
	case 'p' :
	case 'P' : 
		cout << "Pause" << endl; break;
	case 'q' : 
	case 'Q' : 
		cout << "Quit" << endl; break;
	default:
		cout << "Default" << endl;
	}
	return 0;
}