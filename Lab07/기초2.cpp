#include <iostream>
#include <string> //string��ü ���
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
using namespace std;
int main() {
	ofstream fout; // processor->file ����
	fout.open("example.txt"); // example.txt ����
	string s2 = "Objective Oriented Programming";
	fout << s2 << endl;
	fout << "Random Variables" << endl;
	fout << "Linear Algebra" << endl;
	fout.close(); // fout �ݱ�

	ifstream fin;
	string s1;
	fin.open("example.txt"); // example.txt ����
	if (!fin) {
		cout << "error, no such file exists" << endl;
		exit(100);
	}
	while (getline(fin, s1)) { // line by line���� example.txt���� �о�ͼ� ���
		cout << s1 << endl;
	}

	//�ѹ��� ������� �ʱ� ������ �ּ�ó�� �س���
	while (1) { // ���� ������ example.txt���� �о�ͼ� ���
		fin >> s1;
		if (!fin) break;
		cout << s1 << endl;
	}
	fin.close();
}