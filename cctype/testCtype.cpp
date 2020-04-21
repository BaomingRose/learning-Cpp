#include <iostream>
#include <cctype>
using namespace std;

int main() {
	if (isalpha('a')) {
		cout << "a is alpha" << endl;
	}
	if (isalpha('0')) {
		cout << "a is 字母" << endl;
	} else {
		cout << "0 is not 字母" << endl;
	}

	if (isdigit('6')) {
		cout << "6 is digit" << endl;
	}
	if (isdigit('a')) {
		cout << "a is digit" << endl;
	} else {
		cout << "a is not digit" << endl;
	}

	if (isprint(255)) {
		cout << "255 可打印" << endl;
	} else {
		cout << "255 不可打印" << endl;
	}
	if (isprint(32)) {
		cout << "32 (空格)可打印" << endl;
	} else {
		cout << "32 不可打印" << endl;
	}
	if (isprint('\t')) {
		cout << "\\t 可打印" << endl;
	} else {
		cout << "\\t 不可打印" << endl;
	}

	if (isspace(' ')) {
		cout << "空格 is space " << endl;
	}
	if (isspace('\t')) {
		cout << "\\t is space " << endl;
	}
	if (isspace('\n')) {
		cout << "\\n is space " << endl;
	}

	char x = 'a';
	toupper(x);
	cout << toupper(x) << endl;		//65
	cout << x << endl;		//并没有真正改变字符的原值,只是返回临时变量

	char y = 'A';
	cout << tolower(y) << endl;		//97
	cout << y << endl;

	if (islower('a')) {
		cout << " a is lower" << endl;
	}
	if (isupper('a')) {
		cout << " a is upper" << endl;
	}

	return 0;
}