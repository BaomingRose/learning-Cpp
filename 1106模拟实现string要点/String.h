#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class String {
public:
#if 0
	//�޲ι���Ҫ��һ���ַ�"\0"
	String() : _str(new char[1]) {
		*_str = '\0';
	}
	
	String(char* str) //: _str(str) 
	 : _str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
	}
#endif
	//���Խ����������ϳ�һ��ȱʡ����
	String(const char* str = "") : _str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
	}

#if 0
	String(const String& str) : _str(new char[strlen(str._str) + 1]) {
		strcpy(_str, str._str);
	}
#endif

	//����������д��
	String(const String& str) : _str(nullptr){
		String tmp(str._str);	//tmp��������_str�����ֵ��������������	,����Ҫ��_str�գ��м�ֵ��
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

	//�Ⱥ�������д��,�Ѳ����ĳ����棬���ʡ����
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