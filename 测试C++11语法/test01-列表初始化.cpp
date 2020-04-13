#if 0
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

/*================================================
 * description：C++11支持数组，stl容器的列表初始化
=================================================*/
void test1() {
	int iii(1);	//这个之前就是支持的构造
	int i{ 1 };
	int ii{ 1 + 2 };

	int a[3] = { 2, 3, 6 };
	int* pa = new int[3]{ 2, 3, 6 };	//C++11新的花括号初始化

	vector<int> vv = { 2, 3, 6 };
	vector<int> v{ 2, 3, 6 };

	//map支持花括号中的键值对也用花括号初始化
	map<int, int> m{ {1, 2}, {2, 3}, {5, 8} };
	for (const auto& e : m) {
		cout << e.first << "-" << e.second << endl;
	}

	list<int> l{ 2, 3, 6 };
	set<int> s{ 2, 3, 6 };
}

/*================================================
 * description：自定义类型的构造时可以把参数的小括号改成花括号
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
	A aaa = 10;	//这个是之前的隐式类型转化，单参构造才可以
	//以下是C++11的花括号构造	
	A aaaa = { 13, 'f' };
	A a{ 10, 'a' };
	A aa{ a };
	A* pa = new A{ 11, 'b' };
}

/*================================================
 * description：实现自定义类型支持列表初始化，构造的参数类型为initializer_list<T>
=================================================*/
template <class T>
class Vector {
	typedef T* iterator;
public:
	Vector() : _first(nullptr), _last(nullptr), _endOfStorage(nullptr) {}

	//通过initializer_list类模板，支持列表初始化，通过该类的size方法可以快速获取该列表中参数的个数
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