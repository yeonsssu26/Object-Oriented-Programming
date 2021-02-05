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
	cout << "아이디 : "; string id; cin >> id;
	return id;
}

string getInputPassword() {
	cout << "비밀번호 : "; string pw; cin >> pw;
	return pw;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	/* 내부 호출 함수: getInputId(), getInputPassword()*/
	string _id = getInputId(), _pw = getInputPassword();
	int _std_idx = findStudentById(studentIds, _id);
	if (_std_idx != -1) {
		if (find(passwords.begin(), passwords.end(), _pw) != passwords.end()) return _std_idx; // 패스워드 일치
		else return -999;
	}
	else return -999;
}

bool adminLogin() {
	/* 내부 호출 함수: getInputId(), getInputPassword()*/
	string _id = getInputId(), _pw = getInputPassword();
	if (_id == "admin") {
		if (_pw == "admin") return true;
	}
	else return false;
}
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	/* 내부 호출 함수: studentLogin(), adminLogin()*/
	cout << "--------------------------------------------------------" << endl;
	cout << "1. 학생 로그인" << endl;
	cout << "2. 관리자 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "--------------------------------------------------------" << endl;
	int num; cin >> num;
	switch (num) {
	case 1:
		for (int chk = 1; chk <= 3; chk++) {
			int _id = studentLogin(studentIds, passwords);
			if (_id != -999) return _id;
			else {
				if (chk == 3) {
					cout << "3회 실패하여 종료합니다." << endl; return -999;
				}
				else cout << "로그인 " << chk << "회 실패 (3회 실패시 종료)" << endl;
			}
		}
		break;
	case 2:
		for (int chk = 1; chk <= 3; chk++) {
			if (adminLogin() == true) return -100;
			else {
				if (chk == 3) {
					cout << "3회 실패하여 종료합니다." << endl; return -999;
				}
				else cout << "로그인 " << chk << "회 실패 (3회 실패시 종료)" << endl;
			}
		}break;
	case 3: cout << "로그인을 종료합니다" << endl; return -1;
	}
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "과목코드" << "\t\t" << "강의명" << "\t\t" << "학점" << "\t" << "수강가능인원" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	if (user == -100) { // 개설된 강의들을 목록을 출력
		for (int i = 0; i < lectureCodes.size(); i++) {
			cout << lectureCodes.at(i) << "\t\t" << lectureNames.at(i) << "\t" << lectureCredits.at(i) << "\t" << limits.at(i) << endl;
		}
	}
	else { // 현재 사용자가 신청한 수강과목 목록을 출력
		for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
			int _idx = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
			cout << appliedLectureCodes[user][i] << "\t\t" << lectureNames[_idx] << '\t' << lectureCredits[_idx] << '\t' << limits[_idx] << endl;
		}
	}cout << endl;
}

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string _studentIds, _passwords, _name;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "학번 : "; cin >> _studentIds;
	cout << "비밀번호 : "; cin >> _passwords;
	cout << "학생이름 : "; cin >> _name;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < studentIds.size(); i++) {
		if (_studentIds == studentIds.at(i)) {
			cout << "이미 존재하는 학번입니다" << endl; break;
		}
		else {
			if (i == studentIds.size() - 1) {
				cout << "성공적으로 등록되었습니다" << endl;
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
	cout << "과목코드 : "; cin >> _lectureCode;
	cout << "과목명 : "; cin >> _lectureName;
	cout << "학점 : "; cin >> _lectureCredit;
	cout << "수강인원 : "; cin >> _lectureLimit;
	if (findLectureByCode(lectureCodes, _lectureCode) != -1) cout << "이미 존재하는 과목코드 입니다" << endl;
	else {
		cout << "성공적으로 강의가 개설되었습니다" << endl;
		lectureCodes.push_back(_lectureCode);
		lectureNames.push_back(_lectureName);
		lectureCredits.push_back(_lectureCredit);
		limits.push_back(_lectureLimit);
	}
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* 내부 호출 함수: printLectures*/
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); // default : user = -100 // 개설강좌전체출력
	string _dltLecCode; cout << "삭제할 강의 코드 (0: 뒤로가기) >> "; cin >> _dltLecCode;

	if (find(lectureCodes.begin(),lectureCodes.end(),_dltLecCode) != lectureCodes.end()) {
		cout << "성공적으로 강의가 폐쇄되었습니다." << endl;

		// 학생 개개인의 수강강의 벡터
		int _dltLecIdx = findLectureByCode(lectureCodes, _dltLecCode), _credit_tmp, _indiv_dltLecIdx;
		for (int i = 0; i < appliedLectureCodes.size(); i++) { // i : 몇 번째 학생인지
			if (find(appliedLectureCodes[i].begin(),appliedLectureCodes[i].end(),_dltLecCode) != appliedLectureCodes[i].end()) {
				// 개개인의 벡터에 존재해지 학점증가하고 강제철회함
				// 학생 개개인의 수강가능 학점 증가
				_credit_tmp = credits.at(i) + lectureCredits.at(_dltLecIdx); // 현재학점 + 추가될학점
				credits.at(i) = _credit_tmp;

				// 학생 개개인의 수강강의 벡터에서 강제철회
				_indiv_dltLecIdx = findLectureByCode(appliedLectureCodes[i], _dltLecCode);
				deleteElement(appliedLectureCodes[i], _indiv_dltLecIdx);
			}
		}

		// 전체강의벡터
		deleteElement(lectureCodes, _dltLecIdx); // 강의코드벡터
		deleteElement(lectureNames, _dltLecIdx); // 강의명벡터
		lectureCredits.erase(lectureCredits.begin() + _dltLecIdx); // 학점벡터
		limits.erase(limits.begin() + _dltLecIdx); // 수강인원벡터
	}
	else {
		cout << "일치하는 코드가 없습니다." << endl;
	}
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	/* 내부 호출 함수: addStudent, addLecture, deleteLecture*/
	while (true) {
		cout << "1. 학생추가" << endl;
		cout << "2. 강의개설" << endl;
		cout << "3. 강의삭제" << endl;
		cout << "4. 로그아웃" << endl;
		cout << "5. 종료" << endl;
		int num; cin >> num;
		switch (num) {
		case 1: addStudent(studentIds, passwords, names, credits, appliedLectureCodes); break;
		case 2: addLecture(lectureCodes, lectureNames, lectureCredits, limits); break;
		case 3: deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes); break;
		case 4: return -1; // runAdmin()함수에서 main으로 -1을 반환한다.
		case 0: return 1; // runAdmin()함수에서 main으로 1을 반환한다.
		}
	}
}

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "--------------------------------------------------------" << endl;
	cout << "학번 : " << studentIds.at(user) << "\t" << "이름 : " << names.at(user) << "\t" << "수강가능학점 : " << "\t" << credits.at(user) << endl;
	cout << "--------------------------------------------------------" << endl << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); // default : user = -100 // 개설강좌전체출력
		string applyLecCode; cout << "신청할 과목코드(0: 뒤로가기) : "; cin >> applyLecCode;

		if (applyLecCode == "0") return; // 0 : 뒤로가기

		int applyLecIdx = findLectureByCode(lectureCodes, applyLecCode);
		if (applyLecIdx != -1 || appliedLectureCodes[user].size() == 0) {
			if (limits.at(applyLecIdx) <= 0) cout << "수강 인원이 꽉 찼습니다" << endl;
			else {// 수강학점 충분여부
				if (credits.at(user) < lectureCredits.at(applyLecIdx)) cout << "수강가능 학점이 부족합니다" << endl;
				else {// 과목코드 중복여부
					if (find(appliedLectureCodes[user].begin(), appliedLectureCodes[user].end(), applyLecCode) != appliedLectureCodes[user].end())
						cout << "이미 해당과목을 신청했습니다" << endl;
					else {// 과목명 중복여부
						int chkIdx;

						if (appliedLectureCodes[user].size() == 0) {
							appliedLectureCodes[user].push_back(applyLecCode);
							credits.at(user) -= lectureCredits.at(applyLecIdx); // 수강가능 학점은 수강신청한 과목의 학점만큼 감소

							int limit_tmp = limits.at(applyLecIdx);
							limits.at(applyLecIdx) = limit_tmp - 1; // 수강가능인원은 1감소
						}
						else {
							for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
								chkIdx = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
								if (lectureNames[chkIdx] == lectureNames[applyLecIdx]) {
									cout << "이미 동일명의 과목을 신청했습니다" << endl; break;
								}
								else {
									if (i == appliedLectureCodes[user].size() - 1) {
										cout << "[" << applyLecCode << "]" << lectureNames.at(applyLecIdx) << "을(를) 성공적으로 신청하였습니다." << endl;

										appliedLectureCodes[user].push_back(applyLecCode); // 해당학생의 수강과목vector에 추가
										credits.at(user) -= lectureCredits.at(applyLecIdx); // 수강가능 학점은 수강신청한 과목의 학점만큼 감소

										int limit_tmp = limits.at(applyLecIdx);
										limits.at(applyLecIdx) = limit_tmp - 1; // 수강가능인원은 1감소

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
			cout << "과목코드를 잘못 입력셨습니다." << endl;
			system("pause");
		}
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); // 로그인된 학생의 수강과목만 출력
		string disApLecCode; cout << "철회할 과목코드(0: 뒤로가기) : "; cin >> disApLecCode; // 0 : 뒤로가기 구현해야함

		if (disApLecCode == "0") return; // 0 : 뒤로가기

		for (int i = 0; i < appliedLectureCodes[user].size(); i++) {
			if (find(appliedLectureCodes[user].begin(), appliedLectureCodes[user].end(), disApLecCode) != appliedLectureCodes[user].end()) {
				int _idx = findLectureByCode(lectureCodes, disApLecCode);
				cout << disApLecCode << lectureNames[_idx] << "을(를) 성공적으로 철회하였습니다." << endl;

				int credit_tmp = lectureCredits.at(_idx) + credits.at(user); // 철회한 과목의 학점 + 로그인한 학생의 잔여학점
				credits.at(user) = credit_tmp; // 철회한 학생의 수강가능 학점을 철회한 과목의 학점만큼 증가시킴

				int limits_tmp = limits.at(_idx) + 1;
				limits.at(_idx) = limits_tmp; // 수강가능 인원은 1증가

				deleteElement(appliedLectureCodes[user], i); // 과목철회
				return;
			}
			else {
				cout << "과목 코드가 올바르지 않습니다" << endl;
				system("pause");
			}
		}
	}
}

void changePassword(vector<string>& passwords, const int& user) {
	string pw, new_pw;	cout << "본인 확인을 위해 비밀번호를 한 번 더 입력해주세요 : "; cin >> pw;
	if (passwords.at(user) == pw) {
		cout << "새로 설정할 비밀번호를 입력하세요" << endl;
		cout << "비밀번호 : "; cin >> new_pw; passwords.at(user) = new_pw;
	}
	else cout << "비밀번호가 일치하지 않습니다" << endl;
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	/* 내부 호출 함수: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	while (true) {
		cout << "1. 수강신청" << endl;
		cout << "2. 수강현황" << endl;
		cout << "3. 수강철회" << endl;
		cout << "4. 비밀번호 변경" << endl;
		cout << "5. 로그아웃" << endl;
		cout << "0. 종료" << endl;
		int num; cin >> num;
		switch (num) {
		case 1: applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); break;
		case 2:
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); // 로그인된 학생이 수강하는 과목만 출력
			break;
		case 3: disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user); break;
		case 4: changePassword(passwords, user); break;
		case 5: return -1; // runStudent()함수에서 main으로 -1을 반환한다.
		case 0: return 1;// runStudent()함수에서 main으로 1을 반환한다.
		}
	}
}