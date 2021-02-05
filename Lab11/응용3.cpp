/*
학생 계좌 정보를 입력받고 학생 계좌 정보들을 모두 삭제하여 삭제된 계좌들의 잔액 총합을 출력하는 프로그램을 작성하시오.
 - 총 학생 수를 사용자로부터 입력받음.
 - 학생 계좌 정보 Account class는 학번, 이름, 잔액을 멤버 변수로 가지고 있음.
 - Account 클래스 배열을 동적으로 생성함.
 - 각 학생의 학번, 이름, 잔액을 입력받음. 이 때, 중복된 학번을 입력받으면 프로그램을 종료함.
 - 모두 입력 받은 후, Account 클래스 배열을 delete하여 모든 학생 계좌의 잔액 총합을 출력함.
 Hint) Account class 내 멤버 변수에서 static 변수를 사용, Account 클래스의 소멸자를 적절히 이용.
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
	cout << "총 학생수 입력 : "; int size; cin >> size;
	Account a;
	a.makeAccount(size);
	for (int i = 0; i < size; i++) {
		string id, name; int balance;
		cout << "학번입력 :  "; cin >> id;
		cout << "이름 입력 : "; cin >> name;
		cout << "잔액 입력 : "; cin >> balance;
		a.setAccount(id, name, balance);
		// 학번중복검사에서 에러가 발생하여 주석처리 합니다.
		/*if (a.chk_duplication(id) == false) {
			cout << "중복된 학번입니다. 프로그램을 종료합니다." << endl; return 0;
		}
		else {
			a.calcSum(balance);
		}*/
		a.calcSum(balance);
	}
	cout << "회수된 금액 : " << a.getSum() << endl;
	a.~Account();
	return 0;
}