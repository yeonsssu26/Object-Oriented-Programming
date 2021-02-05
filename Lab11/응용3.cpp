/*
�л� ���� ������ �Է¹ް� �л� ���� �������� ��� �����Ͽ� ������ ���µ��� �ܾ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 - �� �л� ���� ����ڷκ��� �Է¹���.
 - �л� ���� ���� Account class�� �й�, �̸�, �ܾ��� ��� ������ ������ ����.
 - Account Ŭ���� �迭�� �������� ������.
 - �� �л��� �й�, �̸�, �ܾ��� �Է¹���. �� ��, �ߺ��� �й��� �Է¹����� ���α׷��� ������.
 - ��� �Է� ���� ��, Account Ŭ���� �迭�� delete�Ͽ� ��� �л� ������ �ܾ� ������ �����.
 Hint) Account class �� ��� �������� static ������ ���, Account Ŭ������ �Ҹ��ڸ� ������ �̿�.
*/
#include <iostream>
#include <string>
using namespace std;
class Account {
	Account *ap;
	string id;
	string name;
	int balance;
	static int sum;
	static int cnt;
public:
	~Account() { 
		for (int i = 0; i < cnt; i++) {
			delete[] ap;
		}
	}
	void makeAccount(int size) {
		this->cnt = size; 
		Account* ap = new Account[cnt];
	}
	void setAccount(string _id, string _name, int _balance) {
		this->id = _id; this->name = _name; this->balance = _balance;
	}
	void calcSum(int _balance) { this->sum += _balance; }
	string getId() { return this->id; }
	int getSum() { return this->sum; }
	bool chk_duplication(string curr_id) {
		if (cnt > 1) {
			for (int i = 0; i < cnt; i++) {
				if (this->ap[i].id == curr_id) return false;
			}
		}
		return true;
	}
};
int Account::sum = 0;
int Account::cnt = 0;
int main() {
	cout << "�� �л��� �Է� : "; int size; cin >> size;
	Account a;
	a.makeAccount(size);
	for (int i = 0; i < size; i++) {
		string id, name; int balance;
		cout << "�й��Է� :  "; cin >> id;
		cout << "�̸� �Է� : "; cin >> name;
		cout << "�ܾ� �Է� : "; cin >> balance;
		a.setAccount(id, name, balance);
		// �й��ߺ��˻翡�� ������ �߻��Ͽ� �ּ�ó�� �մϴ�.
		/*if (a.chk_duplication(id) == false) {
			cout << "�ߺ��� �й��Դϴ�. ���α׷��� �����մϴ�." << endl; return 0;
		}
		else {
			a.calcSum(balance);
		}*/
		a.calcSum(balance);
	}
	cout << "ȸ���� �ݾ� : " << a.getSum() << endl;
	a.~Account();
	return 0;
}