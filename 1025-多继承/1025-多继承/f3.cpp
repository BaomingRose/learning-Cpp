#include<iostream>
#include<string>
using namespace std;

//为了避免二义性，让公共基类值进行一次初始化，将公共基类设为虚基类

#if 0
class A {
public:
	void f() {
		cout << "A::f()" << endl;
	}
protected:
	int a;
};

class B : virtual public A {
protected:
	int b;
};

class C : virtual public A {
protected:
	int c;
};

class D : public B, public C {
public:
	void g() {
		cout << "D::g():";
		f();
	}
private:
	int d;
};

int main() {
	D d;
	d.f();
	d.g();
	cout << endl << endl;

	//当一个类有虚基类时，编译系统将为该类的对象定义一个指针成员，让它指向虚基类的子对象。
	//该指针称为虚基类指针。
	
	D dd;
	A *pA;
	pA = &dd;
	pA->f();
	return 0;
}
#endif


//含有虚基类的派生类的构造函数
//最后建立对象的类称为最派生类
//只有最派生类的构造函数调用虚基类的构造函数，这里的B，C对A的构造就会被忽略
//中间类对虚基类的构造会被忽略※※※
class A {
public:
	A(string a) {
		cout << a << endl;
	}
};

class B : virtual public A{
public:
	B(string s1, string s2) : A(s1) {
		cout << s2 << endl;
	}
};

class C : virtual public A {
public:
	C(string s1, string s2) : A(s1) {
		cout << s2 << endl;
	}
};

class D : public B, public C {
public:
	D(string s1, string s2, string s3, string s4, string s5) : B(s1, s2), C(s3, s4), A(s5) {
		cout << s5 << endl;
	}
};

int main() {
	D d("class 1", "class 2", "class 3", "class 4", "class 5");
	return 0;
}

/*
class 5		//构造D先构造基类A
class 2		//构造B中，而A的构造被忽略
class 4		//构造C中，而A的构造被忽略
class 5		//最后执行D其他构造
*/