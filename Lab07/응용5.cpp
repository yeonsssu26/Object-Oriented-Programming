#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int length;
	char tmp;
	cout << "length = "; cin >> length;
	ifstream fin("paper.txt");
	ofstream fout("output.txt");
	if (!fin) { // ����ó��
		cout << "file input error" << endl;
		exit(100);
	}
	if (!fout) { // ����ó��
		cout << "file output error" << endl;
		exit(100);
	}
	while (fin) {
		for (int i = 0; i < length; i++) {
			if (!fin.get(tmp))
				break;
			if (tmp == '\n')
				tmp = ' ';
			fout.put(tmp);
		}
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}