#include "CText.h"
#include "CFancyText.h"
string FancyText::get() { return left_brac + Text::get() + right_brac; }
void FancyText::append(string _extra) { Text::append(connector + _extra); }