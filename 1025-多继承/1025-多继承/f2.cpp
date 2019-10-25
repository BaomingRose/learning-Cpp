#include<iostream>
using namespace std;

//��Ҫͨ���ʵ��������޶�������������

#if 0
//�������������е�����ͬ����Ա�ǿ��ܳ��ֶ�����
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
		//f();		//��֪����A�Ļ���B�ģ����ж�����
		cout << "C.h() :";
		cout << " ______h(0)" << endl;
		A::f();
		B::f();
		cout << " ______h(1)" << endl;
	}
};

int main() {
	C c;
//	c.f();		//���ж����ԣ���֪������A�Ļ���B��
	c.A::f();	//��Ա�޶�������������
	c.B::f();
	c.h();
}
#endif

#if 0
//�������й�������ʱ���ʹ��������Ա���ܳ��ֶ�����

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

//C�����ӣ�B1��B2�Ǹ��ף�C��үү, C�̳���A�������a
class C : public B1, public B2 {
public:
	C(int i = 10, int j = 111, int k = 10, int l = 1111) : B1(i, j), B2(k, l) {}
	int f() {
		return B1::a + B2::a;		//ͨ�������޶�����������
	}
private:
	int c;
};

int main() {
	C c;
	//cout << c.a << endl;	//�����a����ȷ��B1����B2�ģ����ж�����
	//cout << c.A::a;			//�����A�ķ���Ҳ����ȷ��������
	//���������Ե���÷�����ͨ���ʵ��������޶�
	cout << "B1::a = " << c.B1::a << endl << "B2::a = " <<  c.B2::a << endl;
}
#endif