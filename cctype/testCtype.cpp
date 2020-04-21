#include <iostream>
#include <cctype>
using namespace std;

int main() {
	if (isalpha('a')) {
		cout << "a is alpha" << endl;
	}
	if (isalpha('0')) {
		cout << "a is ��ĸ" << endl;
	} else {
		cout << "0 is not ��ĸ" << endl;
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
		cout << "255 �ɴ�ӡ" << endl;
	} else {
		cout << "255 ���ɴ�ӡ" << endl;
	}
	if (isprint(32)) {
		cout << "32 (�ո�)�ɴ�ӡ" << endl;
	} else {
		cout << "32 ���ɴ�ӡ" << endl;
	}
	if (isprint('\t')) {
		cout << "\\t �ɴ�ӡ" << endl;
	} else {
		cout << "\\t ���ɴ�ӡ" << endl;
	}

	if (isspace(' ')) {
		cout << "�ո� is space " << endl;
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
	cout << x << endl;		//��û�������ı��ַ���ԭֵ,ֻ�Ƿ�����ʱ����

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