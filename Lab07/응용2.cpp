#include <iostream>
#include <string>
using namespace std;
int main() {
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	string keyword, tmp;
	int idx = 0, comma = 0;
	cout << "키워드 : "; cin >> keyword;
	while (true) {
		// comma전까지 단어를 자른다
		comma = data.find(",", idx);
		tmp = data.substr(idx, comma - idx);

		// 그 단어에 "사랑"이 포함되어 있는지 확인한다
		if (tmp.find(keyword) != string::npos)
			cout << tmp << '\t';

		// 뒤에 더이상 comma가 없으면 탈출한다
		if (data.find(",", comma) == string::npos)
			break;

		// 그 다음 comma로 넘어간다
		idx = comma + 1;
	}
	cout << endl;
	return 0;
}