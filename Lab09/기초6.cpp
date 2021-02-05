# include <iostream>
# include <vector>
using namespace std;
bool found_char(const char* s, char ch) {
	while (*s != '\0') { // s와 ch 만으로 (s,s+1, ...)에 ch가 있는지 true/false return
		if (*s == ch) return true;
		s++;
	}
	return false;
}
int main() {
	const char* phrase = "phrase"; // ch[] // 문자열끝에 널문자 저장됨
	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 65, 'z' == 97
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}
	return 0;
}