#include<iostream>
#include<cstring>
using namespace std;

class String {
public :
	String(const char* str = "") {
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//���
	String(const String& s) : _str(new char[strlen(s._str) + 1]) {
		strcpy(_str, s._str);
	}
	
	//���
	String& operator= (const String& s) {
		if (this != &s) {
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}

	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};


//���ڱ����ڼ�ȷ������
//�������������Զ��������ֿ�
//ʹ��TrueType������������
struct TrueType {
	static bool Get() {
		return true;
	}
};
//ʹ��FalseType�����Զ�������
struct FalseType {
	static bool Get() {
		return false;
	}
};

template<class T>
struct TypeTraits {
	typedef FalseType PODTYPE;
};

template<>
struct TypeTraits<char> {
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<long> {
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short> {
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<int> {
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double> {
	typedef TrueType PODTYPE;
};

template<class T>
void Copy(T* dst, T* src, size_t size) {
	//�������ͺ��Զ�������
	//T�������������ͻ����Զ�������
	//typeid(T).name();	//"int" "class Date"
	if (TypeTraits<T>::PODTYPE::Get()) {
		memcpy(dst, src, sizeof(T) * size);
	}
	else {
		for (size_t i = 0; i < size; ++i) {
			dst[i] = src[i];
		}
	}
}

int main() {
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,0 };
	int array2[sizeof(array1) / sizeof(array1[0])];
	Copy(array2, array1, 10);

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);	
	return 0;
}