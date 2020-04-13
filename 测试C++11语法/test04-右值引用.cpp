#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
using namespace std;
/*================================================
 * description��
����⣺
	��ֵ�� ���Գ����ڸ�ֵ���ŵ�����
	��ֵ�� ֻ���Գ����ڸ�ֵ���ŵ��ұ�
		1�� ����
		2�� ����ֵ�� ������������Ҫ������ֵ
=================================================*/
int fun() {
	int a = 10;
	return a;
}

void test1() {
	//fun() = 2;	//�����ʱ�����ǲ��ܸ�ֵ�ģ�����ǽ���ֵ
}

/*================================================
 * description��
	��ֵ���ã� ������������ֵ��Ҳ����������ֵ(��Ҫ��const)
	��ֵ����&&�� ֻ��������ֵ		//Ϊ�����Ч��
=================================================*/
void test2() {
	int a = 10;
	int& ra = a;
	const int& ra2 = 10;
	const int& f22 = fun();

	int&& rra = 10;
	int&& f2 = fun();
	//int&& rra2 = a;  //��ֵ���ò���������ֵ
}

/*================================================
 * description��ʵ��string����ƶ�����		���Ҿ���ԭ�߼���û�иı䣬ֻ���ж��Ƿ������������ֵ���Ҿ��ڿ�����ʱ�����ֽţ�
		��һ����������string���͵�ʱ����ô��������Ǹ�����ֵ�������ʹ����ֵ���õ��ƶ���������ô������һ�ο���������ֵ��Ȼ��������
		���ʹ����ֵ���ã��͵����ƶ��������ƶ������������ռ俽���ˣ����ǽ���Ŀռ������ã������ÿգ�������ʱ���ѿռ��ͷ��ˣ�ֱ�Ӱ����ԭ�ռ䷵��
		
		����Ǹ�ֵ����ֵ����ʱ��������ͬ�ĵ�������Ҫ�ٿ�����ʱ���󣬶���ֱ��ʹ����ʱ�����Խ�ʡ����
=================================================*/
class String {
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
		cout << "String(char*)" << endl;
	}

	String(const String& s) : _str(new char[strlen(s._str) + 1]) {
		strcpy(_str, s._str);
		cout << "String (const String&)" << endl;
	}
	//�ƶ�����
	String(String&& s)
		:_str(s._str) {	//ֱ��������Դ��ʹ��
		s._str = nullptr;
		cout << "String (String&&)" << endl;
	}
	
	String& operator=(const String& s) {
		if (this != &s) {
			if (_str)
				delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		cout << "operator=(const String&)" << endl;
		return *this;
	}
	//�ƶ���ֵ
	String& operator=(String&& s) {
		if (this != &s) {
			char* tmp = _str;
			_str = s._str;
			s._str = tmp;
		}
		cout << "operator=(String&&)" << endl;

		return *this;
	}

	char* c_str() {
		return _str;
	}
	
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
		cout << "��������" << endl;
	}
private:
	char* _str;
};

String getString(const char* str) {
	String strOut(str);	//����ù���
	return strOut;		//����֮ǰ����һ����ʱ���󷵻أ����������ֵ����ֱ��ʹ�ã���һ������ֵ
}

void test3() {
	const char* str = "123";
	String copy = getString(str);  //ִ��һ�ι��� + 2�ο������� ---> �������Ż�--> 1�ι��� + 1�ο�������
									//������ƶ����죬������ƶ�����
	cout << copy.c_str() << endl;
}

void test4() {
	String str("123");
	String str2("456");
	String str3("-10");
	str3 = str2;  // ��ֵ
	str2 = String("789");  // ���� +  �ƶ���ֵ + ����
	cout << str2.c_str() << endl;
}

/*================================================
 * description���ƶ�����, Ψһ�Ĺ��ܾ��ǽ�һ����ֵǿ��ת��Ϊ��ֵ���ã�ͨ����ֵ����ʹ�ø�ֵ��ʵ���ƶ�����
				�����str��ת����ֵ�����ǲ������������Ͼ����Ǹ��������ڽϳ��ı�����ֻ���õ���ֵ��str2����ʹ�õ�ֵ
=================================================*/
void test5() {
	String str("123");
	String str2("456");
	String str3("-10");
	cout << str.c_str() << endl;
	str3 = str2;  // ��ֵ
	//�ƶ�����move: ����ʹ�ó����� str����Ϊ��ֵ����str�ں��汻��������
	// ֻ����ȫȷ����ֵ�ں���Ĵ����в����ٱ�ʹ�õ����ſ��԰���ֵͨ���ƶ�����ת����ֵ
	str2 = move(str);  // move: �ı�str�����ԣ� str-->��ֵ��  �ƶ���ֵ
	cout << str.c_str() << endl;
	str2 = String("789");  // ���� +  �ƶ���ֵ + ����
}

/*================================================
 * description�� move����ȷʹ�ã���E���ƶ�������ƶ���ֵ�����У�Ҫ����ʱ�����е�String�����ƶ���ֵ����Ҫʹ��move�ƶ����壬����ʵ��������
				��Ϊ��ʱ�Ķ����е�String����Ҳ����ʱ��Ҳ�ǲ���Ҫ�����ˣ����Կ���ת��Ϊ��ֵ����String�����ĵ����ƶ�������ƶ���ֵ����
=================================================*/
class E {
public:
	E(const String& name, const String& id) : _name(name)), _id(id) {
		cout << "E(const String& name, const String& id)" << endl;
	}

	//�ƶ�������ʵ��String ���ƶ�����
	E(E&& e) : _name(move(e._name)), _id(move(e._id)) {
		cout << "E(E&&)" << endl;
	}

	E(E& e) : _name(e._name), _id(e._id) {
		cout << "E(E& e)" << endl;
	}

	E& operator=(const E& e) {
		cout << "E& operator=(const E& e)" << endl;
		if (this != &e) {
			_name = e._name;
			_id = e._id;
		}
		
		return *this;
	}

	//�ƶ���ֵ��ʵ��String���ƶ���ֵ
	E& operator=(E&& e) {
		cout << "E& operator=(E&& e)" << endl;
		if (this != &e) {
			_name = move(e._name);
			_id = move(e._id);
		}
		
		return *this;
	}

private:
	String _name;
	String _id;
};

void test6() {
	E e("123", "46");
	E copy(e);
	E copy2 = E("999", "999");
	cout << "=" << endl;
	e = copy;
	copy2 = E("1000", "1000");
}

/*================================================
 * description������ת��, ����ģ�����������������������β�ʱ�������Ӧʵ������ֵ������Ӧ�ñ�ת��Ϊ��ֵ�������Ӧʵ������ֵ������Ӧ�ñ�ת��Ϊ��ֵ��
=================================================*/
void Fun(int &x) { cout << "lvalue ref" << endl; }
void Fun(int &&x) { cout << "rvalue ref" << endl; }
void Fun(const int &x) { cout << "const lvalue ref" << endl; }
void Fun(const int &&x) { cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward0(T t) {
	Fun(t);
}
// �������ͣ� ��������&&  ��ֵ����
// ���ͣ� T&&  δ���������ͣ� ����ʵ����������ȷ���� ��ֵ/��ֵ����
// ����ת��
template<typename T>
void PerfectForward(T &&t) {
	//C++11ͨ��forward������ʵ������ת��
	Fun(std::forward<T>(t));
}

void test7() {
	PerfectForward(10); // rvalue ref

	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref

	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
}

int main() {
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
	test6();

	return 0;
}
#endif