#if 0
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

/*================================================
 * description��C++11֧�����飬stl�������б��ʼ��
=================================================*/
void test1() {
	int iii(1);	//���֮ǰ����֧�ֵĹ���
	int i{ 1 };
	int ii{ 1 + 2 };

	int a[3] = { 2, 3, 6 };
	int* pa = new int[3]{ 2, 3, 6 };	//C++11�µĻ����ų�ʼ��

	vector<int> vv = { 2, 3, 6 };
	vector<int> v{ 2, 3, 6 };

	//map֧�ֻ������еļ�ֵ��Ҳ�û����ų�ʼ��
	map<int, int> m{ {1, 2}, {2, 3}, {5, 8} };
	for (const auto& e : m) {
		cout << e.first << "-" << e.second << endl;
	}

	list<int> l{ 2, 3, 6 };
	set<int> s{ 2, 3, 6 };
}

/*================================================
 * description���Զ������͵Ĺ���ʱ���԰Ѳ�����С���Ÿĳɻ�����
=================================================*/
class A {
public:
	A(int a = 10) : _a(a) {}
	A(int a, char c) : _a(a), _c(c) {}
private:
	int _a;
	char _c;
};

void test2() {
	A aaa = 10;	//�����֮ǰ����ʽ����ת�������ι���ſ���
	//������C++11�Ļ����Ź���	
	A aaaa = { 13, 'f' };
	A a{ 10, 'a' };
	A aa{ a };
	A* pa = new A{ 11, 'b' };
}

/*================================================
 * description��ʵ���Զ�������֧���б��ʼ��������Ĳ�������Ϊinitializer_list<T>
=================================================*/
template <class T>
class Vector {
	typedef T* iterator;
public:
	Vector() : _first(nullptr), _last(nullptr), _endOfStorage(nullptr) {}

	//ͨ��initializer_list��ģ�壬֧���б��ʼ����ͨ�������size�������Կ��ٻ�ȡ���б��в����ĸ���
	Vector(initializer_list<T> il) : _first(new T[il.size()]), _last(_first) {
		for (auto e : il) {
			*_last++ = e;
		}
		_endOfStorage = _last;
	}

	T* begin() {
		return _first;
	}

	T* end() {
		return _last;
	}
private:
	T* _first;
	T* _last;
	T* _endOfStorage;
};

void test3() {
	Vector<int> v1{ 1, 2, 3, 4, 5, 6 };
	for (const auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	test1();
	test2();
	test3();

	return 0;
}
#endif