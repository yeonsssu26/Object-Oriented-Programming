#include <iostream>
#include <string>
using namespace std;
int main() {
	string data = "���,���α׷���,����,����ǹٺ�,���뿪,õ���ǻ��,�����,��ü����";
	string keyword, tmp;
	int idx = 0, comma = 0;
	cout << "Ű���� : "; cin >> keyword;
	while (true) {
		// comma������ �ܾ �ڸ���
		comma = data.find(",", idx);
		tmp = data.substr(idx, comma - idx);

		// �� �ܾ "���"�� ���ԵǾ� �ִ��� Ȯ���Ѵ�
		if (tmp.find(keyword) != string::npos)
			cout << tmp << '\t';

		// �ڿ� ���̻� comma�� ������ Ż���Ѵ�
		if (data.find(",", comma) == string::npos)
			break;

		// �� ���� comma�� �Ѿ��
		idx = comma + 1;
	}
	cout << endl;
	return 0;
}