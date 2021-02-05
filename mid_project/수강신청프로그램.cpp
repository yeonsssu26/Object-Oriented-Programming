#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdlib>


using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			break;
		}
		else if (user == -1) { // Exit command
			break;
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}

	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (lectureCodes[i] == code)
			return i;
	}
	return -1;
}

void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin("students.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			vector<string> tmpVt; string tmpStr; int tmpInt;
			for (int idx = 0; idx < 6; idx++) {
				switch (idx) {
				case 0:
					fin >> tmpStr; if (fin.eof()) break;
					studentIds.push_back(tmpStr); break;
				case 1:
					fin >> tmpStr; if (fin.eof()) break;
					passwords.push_back(tmpStr); break;
				case 2:
					fin >> tmpStr; if (fin.eof()) break;
					names.push_back(tmpStr); break;
				case 3:
					fin >> tmpInt; if (fin.eof()) break;
					credits.push_back(tmpInt); break;
				case 4: fin >> tmpInt; if (fin.eof()) break;
					break;
				case 5:
					for (int i = 0; i < tmpInt; i++) {
						fin >> tmpStr; if (fin.eof()) break;
						tmpVt.push_back(tmpStr);
					}
					if (fin.eof()) break;
					appliedLectureCodes.push_back(tmpVt);
				}
			}
		}
	}
	fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin("lectures.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			string tmpStr; int tmpInt;
			if (fin.eof()) break;
			for (int idx = 0; idx < 4; idx++) {
				switch (idx) {
				case 0:
					fin >> tmpStr; if (fin.eof()) break;
					lectureCodes.push_back(tmpStr); break;
				case 1: fin >> tmpStr; if (fin.eof()) break;
					lectureNames.push_back(tmpStr); break;
				case 2: fin >> tmpInt; if (fin.eof()) break;
					lectureCredits.push_back(tmpInt); break;
				case 3: fin >> tmpInt; if (fin.eof()) break;
					limits.push_back(tmpInt);
				}
			}
		}
	}
	fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout("students.txt");
	for (int i = 0; i < studentIds.size(); i++) {
		fout << studentIds.at(i) << '\t' << passwords.at(i) << '\t' << names.at(i) << '\t';
		for (int j = 0; j < appliedLectureCodes[i].size(); j++) {
			fout << appliedLectureCodes[i][j];
			if (j != appliedLectureCodes[i].size() - 1) fout << '\t';
		}
		if (i != studentIds.size() - 1) fout << endl;
	}
	fout.close();
}

void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout("lectures.txt");
	for (int i = 0; i < lectureCodes.size(); i++) {
		fout << lectureCodes.at(i) << '\t' << lectureNames.at(i) << '\t' << lectureCredits.at(i) << '\t' << limits.at(i);
		if (i != lectureCodes.size() - 1) fout << endl;
	}
	fout.close();
}

string getInputId() {
	cout << "���̵� : "; string id; cin >> id;
	return id;
}

string getInputPassword() {
	cout << "��й�ȣ : "; string pw; cin >> pw;
	return pw;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	/* ���� ȣ�� �Լ�: getInputId(), getInputPassword()*/
	string _id = getInputId(), _pw = getInputPassword();
	int _std_idx = findStudentById(studentIds, _id);
	if (_std_idx != -1) {
		if (find(passwords.begin(), passwords.end(), _pw) != passwords.end()) return _std_idx; // �н����� ��ġ
		else return -999;
	}
	else return -999;
}

bool adminLogin() {
	/* ���� ȣ�� �Լ�: getInputId(), getInputPassword()*/
	string _id = getInputId(), _pw = getInputPassword();
	if (_id == "admin") {
		if (_pw == "admin") return true;
	}
	else return false;
}
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	/* ���� ȣ�� �Լ�: studentLogin(), adminLogin()*/
	cout << "--------------------------------------------------------" << endl;
	cout << "1. �л� �α���" << endl;
	cout << "2. ������ �α���" << endl;
	cout << "3. ����" << endl;
	cout << "--------------------------------------------------------" << endl;
	int num; cin >> num;
	switch (num) {
	case 1:
		for (int chk = 1; chk <= 3; chk++) {
			int _id = studentLogin(studentIds, passwords);
			if (_id != -999) return _id;
			else {
				if (chk == 3) {
					cout << "3ȸ �����Ͽ� �����մϴ�." << endl; return -999;
				}
				else cout << "�α��� " << chk << "ȸ ���� (3ȸ ���н� ����)" << endl;
			}
		}
		break;
	case 2:
		for (int chk = 1; chk <= 3; chk++) {
			if (adminLogin() == true) return -100;
			else {
				if (chk == 3) {
					cout << "3ȸ �����Ͽ� �����մϴ�." << endl; return -999;
				}
				else cout << "�α��� " << chk << "ȸ ���� (3ȸ ���н� ����)" << endl;
			}
		}break;
	case 3: cout << "�α����� �����մϴ�" << endl; return -1;
	}
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "�����ڵ�" << "\t\t" << "���Ǹ�" << "\t\t" << "����" << "\t" << "���������ο�" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	if (user == -100) { // ������ ���ǵ��� ����� ���
		for (int i = 0; i < lectureCodes.size(); i++) {
			cout << lectureCodes.at(i) << "\t\t" << lectureNames.at(i) << "\t" << lectureCredits.at(i) << "\t" << limits.at(i) << endl;
		}
	}
	else { // ���� ����ڰ� ��û�� �������� ����� ���
		for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
			int _idx = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
			cout << appliedLectureCodes[user][i] << "\t\t" << lectureNames[_idx] << '\t' << lectureCredits[_idx] << '\t' << limits[_idx] << endl;
		}
	}cout << endl;
}

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string _studentIds, _passwords, _name;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "�й� : "; cin >> _studentIds;
	cout << "��й�ȣ : "; cin >> _passwords;
	cout << "�л��̸� : "; cin >> _name;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < studentIds.size(); i++) {
		if (_studentIds == studentIds.at(i)) {
			cout << "�̹� �����ϴ� �й��Դϴ�" << endl; break;
		}
		else {
			if (i == studentIds.size() - 1) {
				cout << "���������� ��ϵǾ����ϴ�" << endl;
				studentIds.push_back(_studentIds);
				passwords.push_back(_passwords);
				names.push_back(_name);
				credits.push_back(18);
				vector<string> vt(0); appliedLectureCodes.push_back(vt);
				break;
			}
		}
	}
}

void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string _lectureCode, _lectureName; int _lectureCredit, _lectureLimit;
	cout << "�����ڵ� : "; cin >> _lectureCode;
	cout << "����� : "; cin >> _lectureName;
	cout << "���� : "; cin >> _lectureCredit;
	cout << "�����ο� : "; cin >> _lectureLimit;
	if (findLectureByCode(lectureCodes, _lectureCode) != -1) cout << "�̹� �����ϴ� �����ڵ� �Դϴ�" << endl;
	else {
		cout << "���������� ���ǰ� �����Ǿ����ϴ�" << endl;
		lectureCodes.push_back(_lectureCode);
		lectureNames.push_back(_lectureName);
		lectureCredits.push_back(_lectureCredit);
		limits.push_back(_lectureLimit);
	}
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* ���� ȣ�� �Լ�: printLectures*/
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); // default : user = -100 // ����������ü���
	string _dltLecCode; cout << "������ ���� �ڵ� (0: �ڷΰ���) >> "; cin >> _dltLecCode;

	if (find(lectureCodes.begin(),lectureCodes.end(),_dltLecCode) != lectureCodes.end()) {
		cout << "���������� ���ǰ� ���Ǿ����ϴ�." << endl;

		// �л� �������� �������� ����
		int _dltLecIdx = findLectureByCode(lectureCodes, _dltLecCode), _credit_tmp, _indiv_dltLecIdx;
		for (int i = 0; i < appliedLectureCodes.size(); i++) { // i : �� ��° �л�����
			if (find(appliedLectureCodes[i].begin(),appliedLectureCodes[i].end(),_dltLecCode) != appliedLectureCodes[i].end()) {
				// �������� ���Ϳ� �������� ���������ϰ� ����öȸ��
				// �л� �������� �������� ���� ����
				_credit_tmp = credits.at(i) + lectureCredits.at(_dltLecIdx); // �������� + �߰�������
				credits.at(i) = _credit_tmp;

				// �л� �������� �������� ���Ϳ��� ����öȸ
				_indiv_dltLecIdx = findLectureByCode(appliedLectureCodes[i], _dltLecCode);
				deleteElement(appliedLectureCodes[i], _indiv_dltLecIdx);
			}
		}

		// ��ü���Ǻ���
		deleteElement(lectureCodes, _dltLecIdx); // �����ڵ庤��
		deleteElement(lectureNames, _dltLecIdx); // ���Ǹ���
		lectureCredits.erase(lectureCredits.begin() + _dltLecIdx); // ��������
		limits.erase(limits.begin() + _dltLecIdx); // �����ο�����
	}
	else {
		cout << "��ġ�ϴ� �ڵ尡 �����ϴ�." << endl;
	}
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	/* ���� ȣ�� �Լ�: addStudent, addLecture, deleteLecture*/
	while (true) {
		cout << "1. �л��߰�" << endl;
		cout << "2. ���ǰ���" << endl;
		cout << "3. ���ǻ���" << endl;
		cout << "4. �α׾ƿ�" << endl;
		cout << "5. ����" << endl;
		int num; cin >> num;
		switch (num) {
		case 1: addStudent(studentIds, passwords, names, credits, appliedLectureCodes); break;
		case 2: addLecture(lectureCodes, lectureNames, lectureCredits, limits); break;
		case 3: deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes); break;
		case 4: return -1; // runAdmin()�Լ����� main���� -1�� ��ȯ�Ѵ�.
		case 0: return 1; // runAdmin()�Լ����� main���� 1�� ��ȯ�Ѵ�.
		}
	}
}

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "--------------------------------------------------------" << endl;
	cout << "�й� : " << studentIds.at(user) << "\t" << "�̸� : " << names.at(user) << "\t" << "������������ : " << "\t" << credits.at(user) << endl;
	cout << "--------------------------------------------------------" << endl << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); // default : user = -100 // ����������ü���
		string applyLecCode; cout << "��û�� �����ڵ�(0: �ڷΰ���) : "; cin >> applyLecCode;

		if (applyLecCode == "0") return; // 0 : �ڷΰ���

		int applyLecIdx = findLectureByCode(lectureCodes, applyLecCode);
		if (applyLecIdx != -1 || appliedLectureCodes[user].size() == 0) {
			if (limits.at(applyLecIdx) <= 0) cout << "���� �ο��� �� á���ϴ�" << endl;
			else {// �������� ��п���
				if (credits.at(user) < lectureCredits.at(applyLecIdx)) cout << "�������� ������ �����մϴ�" << endl;
				else {// �����ڵ� �ߺ�����
					if (find(appliedLectureCodes[user].begin(), appliedLectureCodes[user].end(), applyLecCode) != appliedLectureCodes[user].end())
						cout << "�̹� �ش������ ��û�߽��ϴ�" << endl;
					else {// ����� �ߺ�����
						int chkIdx;

						if (appliedLectureCodes[user].size() == 0) {
							appliedLectureCodes[user].push_back(applyLecCode);
							credits.at(user) -= lectureCredits.at(applyLecIdx); // �������� ������ ������û�� ������ ������ŭ ����

							int limit_tmp = limits.at(applyLecIdx);
							limits.at(applyLecIdx) = limit_tmp - 1; // ���������ο��� 1����
						}
						else {
							for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
								chkIdx = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
								if (lectureNames[chkIdx] == lectureNames[applyLecIdx]) {
									cout << "�̹� ���ϸ��� ������ ��û�߽��ϴ�" << endl; break;
								}
								else {
									if (i == appliedLectureCodes[user].size() - 1) {
										cout << "[" << applyLecCode << "]" << lectureNames.at(applyLecIdx) << "��(��) ���������� ��û�Ͽ����ϴ�." << endl;

										appliedLectureCodes[user].push_back(applyLecCode); // �ش��л��� ��������vector�� �߰�
										credits.at(user) -= lectureCredits.at(applyLecIdx); // �������� ������ ������û�� ������ ������ŭ ����

										int limit_tmp = limits.at(applyLecIdx);
										limits.at(applyLecIdx) = limit_tmp - 1; // ���������ο��� 1����

										break;
									}
								}
							}
						}
					}
				}
			}
			return;
		}
		else {
			cout << "�����ڵ带 �߸� �Է¼̽��ϴ�." << endl;
			system("pause");
		}
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); // �α��ε� �л��� �������� ���
		string disApLecCode; cout << "öȸ�� �����ڵ�(0: �ڷΰ���) : "; cin >> disApLecCode; // 0 : �ڷΰ��� �����ؾ���

		if (disApLecCode == "0") return; // 0 : �ڷΰ���

		for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
			if (find(appliedLectureCodes[user].begin(), appliedLectureCodes[user].end(), disApLecCode) != appliedLectureCodes[user].end()) {
				int _idx = findLectureByCode(lectureCodes, disApLecCode);
				cout << disApLecCode << lectureNames[_idx] << "��(��) ���������� öȸ�Ͽ����ϴ�." << endl;

				int credit_tmp = lectureCredits.at(_idx) + credits.at(user); // öȸ�� ������ ���� + �α����� �л��� �ܿ�����
				credits.at(user) = credit_tmp; // öȸ�� �л��� �������� ������ öȸ�� ������ ������ŭ ������Ŵ

				int limits_tmp = limits.at(_idx) + 1;
				limits.at(_idx) = limits_tmp; // �������� �ο��� 1����

				deleteElement(appliedLectureCodes[user], i); // ����öȸ
				return;
			}
			else {
				cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�" << endl;
				system("pause");
			}
		}
	}
}

void changePassword(vector<string>& passwords, const int& user) {
	string pw, new_pw;	cout << "���� Ȯ���� ���� ��й�ȣ�� �� �� �� �Է����ּ��� : "; cin >> pw;
	if (passwords.at(user) == pw) {
		cout << "���� ������ ��й�ȣ�� �Է��ϼ���" << endl;
		cout << "��й�ȣ : "; cin >> new_pw; passwords.at(user) = new_pw;
	}
	else cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	/* ���� ȣ�� �Լ�: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	while (true) {
		cout << "1. ������û" << endl;
		cout << "2. ������Ȳ" << endl;
		cout << "3. ����öȸ" << endl;
		cout << "4. ��й�ȣ ����" << endl;
		cout << "5. �α׾ƿ�" << endl;
		cout << "0. ����" << endl;
		int num; cin >> num;
		switch (num) {
		case 1: applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); break;
		case 2:
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); // �α��ε� �л��� �����ϴ� ���� ���
			break;
		case 3: disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); break;
		case 4: changePassword(passwords, user); break;
		case 5: return -1; // runStudent()�Լ����� main���� -1�� ��ȯ�Ѵ�.
		case 0: return 1;// runStudent()�Լ����� main���� 1�� ��ȯ�Ѵ�.
		}
	}
}