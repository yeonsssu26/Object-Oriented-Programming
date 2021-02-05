#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Avengers {
protected:
	string name; // 캐릭터 이름
	int attack_point; // 공격력
	int defense_point; // 방어력
	int health; // 체력
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	virtual void set(string _name, int _attack, int _defense, int _health) {} // 캐릭터 설정 함수
	virtual int attack() { return 0; } // 공격 함수
	virtual void defense(int _attack_point) {} // 방어 함수
	virtual void print_info() {} // 캐릭터 정보 출력 함수
};

class Character : public Avengers {
public:
	Character(){}
	~Character() {}
	
	void set(string _name, int _attack, int _defense, int _health) {
		Avengers::name = _name;					Avengers::attack_point = _attack;
		Avengers::defense_point = _defense;		Avengers::health = _health;
	}
	int attack() { return Avengers::attack_point;}
	void defense(int _attack_point) {
		int diff = _attack_point - Avengers::defense_point;
		Avengers::health -= diff;
	}
	void print_info() { 
		cout << Avengers::name << endl;
		cout << Avengers::attack_point << endl;
		cout << Avengers::defense_point << endl;
		cout << Avengers::health << endl;
	}
	int get_health() { return health; }
};

int main() {
	Character my_char;
	Character enemy_char;
	
	cout << "Choose your character [IronMan/CaptinAmerica/Thor] >> "; string name_my; cin >> name_my;
	
	srand((unsigned int)time(NULL)); // random
	int tmp; string name_enemy;
	
	if (name_my == "IronMan") {
		my_char.set("IronMan", 70, 40, 100);
		tmp = rand() % 2;
		if (tmp == 0) name_enemy = "CaptinAmerica";
		else if (tmp == 1) name_enemy = "Thor";
	}
	else if (name_my == "CaptinAmerica") {
		my_char.set("CaptinAmerica", 60, 50, 100);
		tmp = rand() % 2;
		if (tmp == 0) name_enemy = "IronMan";
		else if (tmp == 1) name_enemy = "Thor";
	}
	else if (name_my == "Thor") {
		my_char.set("Thor", 80, 30, 100);
		tmp = rand() % 2;
		if (tmp == 0) name_enemy = "IronMan";
		else if (tmp == 1) name_enemy = "CaptinAmerica";
	}

	if (name_enemy == "IronMan") { enemy_char.set("IronMan", 70, 40, 100); }
	else if (name_enemy == "CaptinAmerica") { enemy_char.set("CaptinAmerica", 60, 50, 100); }
	else if (name_enemy == "Thor") { enemy_char.set("Thor", 80, 30, 100); }

	cout << "--My Character--" << endl; my_char.print_info();
	cout << "--Enemy Character--" << endl; enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life:" << enemy_char.get_health() << endl;

	int my_win = -1, cnt = 0;
	cout << my_char.get_health() << '\t' << enemy_char.get_health() << endl;
	while (1) {
		if (my_char.get_health() <= 0) { my_win = 0; break; }
		else if (enemy_char.get_health() <= 0) { my_win = 1; break; }
		else {
			if (cnt % 2 == 0) { enemy_char.defense(my_char.attack()); }
			else { my_char.defense(enemy_char.attack()); }
			cout << my_char.get_health() << '\t' << enemy_char.get_health() << endl;
		}
		cnt++;
	}

	if (my_win == 0) { cout << "Enemy Win" << endl; }
	else if (my_win == 1) { cout << "You Win" << endl; }

	return 0;
}