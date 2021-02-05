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
	//�ݺ�: ��� �л��� �а� ������ ������
	//getStu �Լ� = ch7STUFL.DAT���� ���� �б�: id, exam1, exam2, exam3
	//calcAvgGrade �Լ� = ���,grade ���: exam1, exam2, exam3 -> avg, grade
	//writeStu �Լ� = grade.txt ����: id, avg, grade
	ifstream fin("ch7STUFL.DAT"); // ���� ����Ʈ���� �ٿ�ε� ����
	ofstream fout("grade.txt");
	int id, exam1, exam2, exam3, avg;
	char grade;
	while (getStu(fin, id, exam1, exam2, exam3)) { // getStu�Լ� ��� // getStu�� true�� ������ �ݺ�
		calcAvgGrade(exam1, exam2, exam3, avg, grade); // calcAvgGrade�Լ� ���
		writeStu(fout, id, avg, grade); // writeStu�Լ� ���
	}
	fin.close();
	fout.close();
	cout << "end";
	return 0;
}