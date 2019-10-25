#include<iostream>
using namespace std;

//主要通过适当的类名限定来消除二义性

#if 0
//派生类多个基类中调用其同名成员是可能出现二义性
class A {
public:
	void f() {
		cout << "A.f()" << endl;
	}
};

class B {
public:
	void f() {
		cout << "B.f()" << endl;
	}
	void g() {
		cout << "B.g()" << endl;
	}
};

class C : public A, public B{
public:
	void g() {
		cout << "C.g()" << endl;
	}

	void h() {
		//f();		//不知道是A的还是B的，会有二义性
		cout << "C.h() :";
		cout << " ______h(0)" << endl;
		A::f();
		B::f();
		cout << " ______h(1)" << endl;
	}
};

int main() {
	C c;
//	c.f();		//会有二义性，不知道调用A的还是B的
	c.A::f();	//成员限定发消除二义性
	c.B::f();
	c.h();
}
#endif

#if 0
//派生类有公共基类时访问公共基类成员可能出现二义性

class A {
public:
	int a;
	A(int i = 10) : a(i) {
	}
};

class B1 : public A {
private:
	int b1;
public:
	B1(int i = 10, int j = 101) : A(i), b1(j){}
};

class B2 : public A {
private:
	int b2;
public:
	B2(int i = 10, int j = 110) : A(i), b2(j){}
};

//C是孙子，B1，B2是父亲，C是爷爷, C继承了A里的两个a
class C : public B1, public B2 {
public:
	C(int i = 10, int j = 111, int k = 10, int l = 1111) : B1(i, j), B2(k, l) {}
	int f() {
		return B1::a + B2::a;		//通过类名限定消除二义性
	}
private:
	int c;
};

int main() {
	C c;
	//cout << c.a << endl;	//这里的a不明确是B1还是B2的，具有二义性
	//cout << c.A::a;			//这里对A的访问也不明确，二义性
	//消除二义性的最好方法是通过适当的类名限定
	cout << "B1::a = " << c.B1::a << endl << "B2::a = " <<  c.B2::a << endl;
}
#endif