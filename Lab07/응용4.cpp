#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream fout1("txt1.txt");
	fout1 << "On its 60th anniversary in 2009, Kyung" << endl;
	fout1 << "Hee University prepared for a second leap" << endl;
	fout1 << "forward while seeking a new paradigm of" << endl;
	fout1 << "future university development." << endl;

	ofstream fout2("txt2.txt");
	fout2 << "In this paper, we explore the feasibility of a" << endl;
	fout2 << "medical training system for breast tumor palpation" << endl;
	fout2 << "based on haptic augmented reality (AR) technology." << endl;

	string tmp;
	ofstream fout3("res.txt", ios::app);

	ifstream fin1("txt1.txt");
	while (getline(fin1, tmp))
		fout3 << tmp << endl;
	fout3 << endl;

	ifstream fin2("txt2.txt");
	while (getline(fin2, tmp))
		fout3 << tmp << endl;

	fout1.close();
	fout2.close();
	fout3.close();
	fin1.close();
	fin2.close();
	return 0;
}