#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
private:
	int stdNum;
	string name;
	string major;
	vector<string> att_lec;
	vector<char> grade;
public:
	Student(){
		name = "default";
		stdNum = 0;
		major = "default";
	}
	Student(string _name, int _stdNum, string _major){
		name = _name;
		stdNum = _stdNum;
		major = _major;
	}
	void setName(string _name) { name = _name; }
	void setID(int _stdNum){ stdNum = _stdNum; }
	void setDpt(string _major){ major = _major; }
	void print() {
		cout << name << ' ' << stdNum << ' ' << major << endl;
	}
	void addGrade(string _lec, char _grade) {
		att_lec.push_back(_lec);
		grade.push_back(_grade);
	}
	void printGrades() {
		for (int i = 0; i < att_lec.size(); i++)
			cout << att_lec.at(i) << " : " << grade.at(i) << endl;
		cout << "GPA : " << getGPA() << endl;
	}
	float getGPA() {
		int sum = 0;
		for (int i = 0; i < grade.size(); i++) {
			switch (grade[i]) {
			case 'A': sum += 4; break;
			case 'B': sum += 3; break;
			case 'C': sum += 2; break;
			case 'D': sum += 1; break;
			case 'F': sum += 1;
			}
		}
		float avg = (float)sum / grade.size();
		return avg;
	}
	void getYear(int currYear) {
		int admYear = stdNum / 1000000;
		int diff = currYear - admYear + 1;
		if (diff == 1) cout << "Freshmen(1학년)" << endl;
		else if (diff == 2) cout << "Sophomore(2학년)" << endl;
		else if (diff == 3) cout << "Junior(3학년)" << endl;
		else if (diff == 4) cout << "Senior(4학년)" << endl;
		else if (diff > 4) cout << "About to graduate(5학년 이상)" << endl;
	}
};
int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";
	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";
	return 0;
}