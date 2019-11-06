#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class String {
public:
#if 0
	//无参构造要有一个字符"\0"
	String() : _str(new char[1]) {
		*_str = '\0';
	}
	
	String(char* str) //: _str(str) 
	 : _str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
	}
#endif
	//可以将上面两个合成一个缺省构造
	String(const char* str = "") : _str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
	}

#if 0
	String(const String& str) : _str(new char[strlen(str._str) + 1]) {
		strcpy(_str, str._str);
	}
#endif

	//拷贝构造新写法
	String(const String& str) : _str(nullptr){
		String tmp(str._str);	//tmp被交换的_str是随机值，析构会有问题	,所以要给_str空（中间值）
		swap(_str, tmp._str);
	}

#if 0
	String& operator=(const String& str) {
		if (this != &str) {
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
		}
		return *this;
	}
#endif

	//等号重载新写法,把参数改成下面，会节省代码
	String& operator=(String str) {
		//String tmp(str._str);
		swap(_str, str._str);
		return *this;
	}

	const char* c_str() const {
		return _str;
	}

	~String() {
		if (_str) {
			delete[] _str;
		}
	}

private:
	char* _str;
};