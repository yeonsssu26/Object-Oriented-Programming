#include <iostream>
#include <string>
using namespace std;
class Account {
	string name;
	string id;
	int balance;
public:
	Account(string _name, string _id, int _balance) : name(_name), id(_id), balance(_balance){}
	string getId() { return this->id; }
	int getBalance() { return this->balance; }
	Account operator+(Account a) { // �����ڿ����ε� +
		Account res(this->name, this->id, this->balance + a.balance);
		return res;
	}
	Account operator-(Account a) { // �����ڿ����ε� -
		Account res(this->name, this->id, this->balance - a.balance);
		return res;
	}
	friend ostream& operator<<(ostream& cout, Account a);;
	friend void print(Account acnt);
	friend void print(Account all_acnt[]);
};

ostream& operator<<(ostream& cout, Account a) { // �����ڿ����ε� <<
	cout << "�й� : " << a.id << "�̸� : " << a.name << "�ܾ� : " << a.balance << endl; // endl�ʿ������ ����
	return cout;
}

// �Լ������ε�
void print(Account acnt) { // Ư���л� �������
	cout << "�й� : " << acnt.id << "\t�̸� : " << acnt.name << "\t�ܾ� : " << acnt.balance << endl;
}
void print(Account all_acnt[]) { // ��ü�л� �������
	for (int i = 0; i < 3; i++) {
		cout << "�й� : " << all_acnt[i].id << "\t�̸� : " << all_acnt[i].name << "\t�ܾ� : " << all_acnt[i].balance << endl;
	}
}

int main() {
	Account acnt[3] = {
	Account("����ȣ", "2014", 10000),
	Account("������", "2019", 0),
	Account("������", "2013", 5000),
	};
	while (true) {
		cout << "���� ���� �л��� �й��� �Է��ϼ��� : "; string send; cin >> send;
		if (send == "����") { // ��������
			cout << "�����մϴ�" << endl; break;
		}
		cout << "���� ���� �л��� �й��� �Է��ϼ��� : "; string take; cin >> take;
		
		int send_idx = -1, take_idx = -1, flag = 1;
		if (send == take) { // ���ǰ˻�1
			cout << "���� ���� �л��� ���� ���� �л��� �й��� �����մϴ�"; flag = 0;
		}
		else {
			for (int i = 0; i < 3; i++) { // find send_idx
				if (acnt[i].getId() == send) send_idx = i;
			}
			for (int i = 0; i < 3; i++) { // find take_idx
				if (acnt[i].getId() == take) take_idx = i;
			}
			if (send_idx == -1 || take_idx == -1) { // ���ǰ˻�2
				cout << "���� ���� �л� Ȥ�� ���� ���� �л��� �й��� �������� �ʽ��ϴ�"; flag = 0;
			}
			else {
				if (acnt[send_idx].getBalance() == 0) { // ���ǰ˻�3
					cout << "���� ������ �л��� �ܾ��� �����մϴ�"; flag = 0;
				}
			}
		}
		if (flag == 0) { // ���ǰ˻� ����
			cout << " �ٽ� �Է����ּ���" << endl;
		}
		else { // ���ǰ˻� ����
			acnt[take_idx] = acnt[take_idx] + acnt[send_idx];
			acnt[send_idx] = acnt[send_idx] - acnt[send_idx];

			cout << "[���� �л��� �ܾ�]  "; print(acnt[send_idx]); // �����л� �������
			cout << "[���� �л��� �ܾ�]  "; print(acnt[take_idx]); // �����л� �������
		}cout << endl;
	}
	print(acnt); // ��ü�л� �������
	return 0;
}