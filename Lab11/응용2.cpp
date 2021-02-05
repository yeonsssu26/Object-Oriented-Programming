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
	Account operator+(Account a) { // 연산자오버로딩 +
		Account res(this->name, this->id, this->balance + a.balance);
		return res;
	}
	Account operator-(Account a) { // 연산자오버로딩 -
		Account res(this->name, this->id, this->balance - a.balance);
		return res;
	}
	friend ostream& operator<<(ostream& cout, Account a);;
	friend void print(Account acnt);
	friend void print(Account all_acnt[]);
};

ostream& operator<<(ostream& cout, Account a) { // 연산자오버로딩 <<
	cout << "학번 : " << a.id << "이름 : " << a.name << "잔액 : " << a.balance << endl; // endl필요없으면 빼기
	return cout;
}

// 함수오버로딩
void print(Account acnt) { // 특정학생 정보출력
	cout << "학번 : " << acnt.id << "\t이름 : " << acnt.name << "\t잔액 : " << acnt.balance << endl;
}
void print(Account all_acnt[]) { // 전체학생 정보출력
	for (int i = 0; i < 3; i++) {
		cout << "학번 : " << all_acnt[i].id << "\t이름 : " << all_acnt[i].name << "\t잔액 : " << all_acnt[i].balance << endl;
	}
}

int main() {
	Account acnt[3] = {
	Account("장윤호", "2014", 10000),
	Account("김유민", "2019", 0),
	Account("박진배", "2013", 5000),
	};
	while (true) {
		cout << "돈을 보낼 학생의 학번을 입력하세요 : "; string send; cin >> send;
		if (send == "종료") { // 종료조건
			cout << "종료합니다" << endl; break;
		}
		cout << "돈을 받은 학생의 학번을 입력하세요 : "; string take; cin >> take;
		
		int send_idx = -1, take_idx = -1, flag = 1;
		if (send == take) { // 조건검사1
			cout << "돈을 보낼 학생과 돈을 받을 학생의 학번이 동일합니다"; flag = 0;
		}
		else {
			for (int i = 0; i < 3; i++) { // find send_idx
				if (acnt[i].getId() == send) send_idx = i;
			}
			for (int i = 0; i < 3; i++) { // find take_idx
				if (acnt[i].getId() == take) take_idx = i;
			}
			if (send_idx == -1 || take_idx == -1) { // 조건검사2
				cout << "돈을 보낼 학생 혹은 돈을 받을 학생의 학번이 존재하지 않습니다"; flag = 0;
			}
			else {
				if (acnt[send_idx].getBalance() == 0) { // 조건검사3
					cout << "돈을 보내는 학생의 잔액이 부족합니다"; flag = 0;
				}
			}
		}
		if (flag == 0) { // 조건검사 실패
			cout << " 다시 입력해주세요" << endl;
		}
		else { // 조건검사 성공
			acnt[take_idx] = acnt[take_idx] + acnt[send_idx];
			acnt[send_idx] = acnt[send_idx] - acnt[send_idx];

			cout << "[보낸 학생의 잔액]  "; print(acnt[send_idx]); // 보낸학생 정보출력
			cout << "[받은 학생의 잔액]  "; print(acnt[take_idx]); // 받은학생 정보출력
		}cout << endl;
	}
	print(acnt); // 전체학생 정보출력
	return 0;
}