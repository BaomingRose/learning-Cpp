#if 0
#include <iostream>
using namespace std;

/*
赋值运算符重载
operator=
运算符重载：
将运算符看成函数，把他的几目当成参数，通过参数的类型识别出对应的操作方法，相当于函数重载。
运算符重载有指定的规则，规则根据运算符来制定。
类会自动提供一个赋值运算符的重载(4)，执行的是浅拷贝，跟拷贝构造相同

const成员函数
const加在成员函数的末尾，代表这个函数中的this是const修饰的
如果一个对象是const对象，那么它不能调用非const的成员函数

取地址运算符重载
类会自动提供两个取地址运算符重载，一个是针对普通对象的(5)，一个是针对const对象的(6)
*/

class Testop {
public:
	int m_a;
	int m_b;

	Testop() :
		m_a(0),
		m_b(0)
	{}

	Testop(int a, int b) :
		m_a(a),
		m_b(b)
	{}

	void test1(int a, int b) {
		test2(2, 4);
	}

	void test2(int a, int b) const {
		//test1(2, 4);
	}

	Testop operator + (const Testop &s) const {
		Testop res;
		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;
		return res;
	}

	Testop & operator = (const Testop &s) {
		m_a = s.m_a;
		m_b = s.m_b;
		return *this;
	}
};

int main() {
	Testop a(3, 5);
	Testop b(2, 7);

	Testop c;
	const Testop d;
	c = c = a + b;

	cout << c.m_a << ' ' << c.m_b << endl;		//5 12
	return 0;
}
#endif