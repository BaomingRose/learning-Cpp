#if 1
#include<iostream>
using namespace std;

/**子类的构造过程：
  *基类的构造
  *基类对象作子类的成员变量的构造（如果有）
  *子类的构造
  */
/*析构刚好和构造过程相反*/

class A {
private:
	int a;
public:
	A() {
		a = 100000;
		cout << "A默认构造" << endl;
	}

	A(int i) {
		a = i;
		cout << "A有参构造" << endl;
	}

	~A() {
		cout << "A析构" << endl;
	}

	void print() {
		cout << "A::a = " << a << endl;
	}
};

class B : public A {
private:
	int b;
	A aa;

public:
	B() {
		b = 0;
		cout << "B默认构造" << endl;
	}

	B(int i) {
		b = i;
		cout << "B单参构造" << endl;
	}

	B(int i, int j, int k) : A(i), aa(j), b(k) {
		cout << "B多参构造" << endl;
	}

	~B() {
		cout << "B析构" << endl;
	}

	void print() {
		A::print();
		aa.print();
		cout << "B::b =" << b << endl;
	}
};

int main() {
	//数组会调用两个默认构造函数
	B bb[2];
	//赋值过程中会调用新的有参构造
	//之前默认构造的对象会被析构
	//下面两个赋值是临时对象
	bb[0] = B(1, 2, 4);
	bb[1] = B(3, 4, 7);
	bb[0].print();
	bb[1].print();

	//会调用两个析构

	return 0;
}
#endif

/*运行结果：
A默认构造
A默认构造
B默认构造
A默认构造
A默认构造
B默认构造
A有参构造
A有参构造
B多参构造
B析构
A析构
A析构
A有参构造
A有参构造
B多参构造
B析构
A析构
A析构
A::a = 1
A::a = 2
B::b =4
A::a = 3
A::a = 4
B::b =7
B析构
A析构
A析构
B析构
A析构
A析构
*/