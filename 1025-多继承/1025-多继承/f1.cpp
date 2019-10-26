#include<iostream>
using namespace std;

#if 0
//多继承构造顺序和单继承顺序类似

class B1 {
private:
	int b1;
public :
	B1() {
		cout << "构造 B1" << endl;
	}
	B1(int i) {
		b1 = i;
		cout << "构造 B1" << endl;
	}
	void print() {
		cout << b1 << endl;
	}
	~B1(){
		cout << "B1析构" << endl;
	}
};

class B2 {
private:
	int b2;
public:
	B2() {
		cout << "构造 B2" << endl;
	}
	B2(int i) {
		b2 = i;
		cout << "构造 B2" << endl;
	}
	void print() {
		cout << b2 << endl;
	}
	~B2() {
		cout << "B2 析构" << endl;
	}
};

class B3 {
private:
	int b3;
public:
	B3() {
		cout << "构造 B3" << endl;
	}
	B3(int i) {
		b3 = i;
		cout << "构造 B3" << endl;
	}
	void print() {
		cout << b3 << endl;
	}
	int getb3() {
		return b3;
	}
	~B3() {
		cout << "B3 析构" << endl;
	}
};

//构造B1，B2的顺序按照下面定义派生类的顺序
class A : public B2, public B1 {
private:
	int a;
	B3 bb;
public:
	A() {
		cout << "A构造" << endl;
	}
	A(int i, int j, int k, int l) : B1(i), B2(j), bb(k) {
		a = l;
		cout << "构造 A" < c< endl;
	}
	void print() {
		B1::print();
		B2::print();
		cout << a << "," << bb.getb3() << endl;
	}
	~A() {
		cout << "A 析构" << endl;
	}
};

int main() {
	A aa;// (1, 2, 3, 4);

	aa.print();
	
	return 0;
}
#endif

/*
构造 B2
构造 B1
构造 B3
构造 A
1
2
4,3
A 析构
B3 析构
B1析构
B2 析构
*/

/*
当默认构造时：
构造 B2
构造 B1
构造 B3
A构造
-858993460
-858993460
-858993460,-858993460
A 析构
B3 析构
B1析构
B2 析构

*/
