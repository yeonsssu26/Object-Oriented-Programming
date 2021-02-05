#include <iostream>
#include <string>
#include "CText.h"
#include "CFancyText.h"
#include "CFixedText.h"
using namespace std;
int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;
	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;
	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; // Base <- Derived 가능
	//t2 = t1; // Derived <- Base 불가능
	return 0;
}