#pragma once
#include <string>
using namespace std;
class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	virtual string get();
	virtual void append(string _extra);
};