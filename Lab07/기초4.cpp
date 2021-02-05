#include <iostream>
#include <fstream> //ifstream ofstream
#include <iomanip>
using namespace std;
bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3) {
	fin >> id >> exam1 >> exam2 >> exam3;
	if (!fin)
		return false;
	return true;
}
void calcAvgGrade(int exam1, int exam2, int exam3, int& avg, char& grade) {
	avg = (exam1 + exam2 + exam3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else
		grade = 'F';
}
void writeStu(ofstream& fout, int id, int avg, char grade) {
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(4) << avg;
	fout << setw(4) << grade << endl;
}
int main() {
	//반복: 모든 학생을 읽고 저장할 때까지
	//getStu 함수 = ch7STUFL.DAT에서 파일 읽기: id, exam1, exam2, exam3
	//calcAvgGrade 함수 = 평균,grade 계산: exam1, exam2, exam3 -> avg, grade
	//writeStu 함수 = grade.txt 저장: id, avg, grade
	ifstream fin("ch7STUFL.DAT"); // 강의 사이트에서 다운로드 가능
	ofstream fout("grade.txt");
	int id, exam1, exam2, exam3, avg;
	char grade;
	while (getStu(fin, id, exam1, exam2, exam3)) { // getStu함수 사용 // getStu가 true일 때까지 반복
		calcAvgGrade(exam1, exam2, exam3, avg, grade); // calcAvgGrade함수 사용
		writeStu(fout, id, avg, grade); // writeStu함수 사용
	}
	fin.close();
	fout.close();
	cout << "end";
	return 0;
}