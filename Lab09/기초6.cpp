# include <iostream>
# include <vector>
using namespace std;
bool found_char(const char* s, char ch) {
	while (*s != '\0') { // s�� ch ������ (s,s+1, ...)�� ch�� �ִ��� true/false return
		if (*s == ch) return true;
		s++;
	}
	return false;
}
int main() {
	const char* phrase = "phrase"; // ch[] // ���ڿ����� �ι��� �����
	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 65, 'z' == 97
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}
	return 0;
}