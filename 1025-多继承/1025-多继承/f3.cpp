#include<iostream>
#include<string>
using namespace std;

//Ϊ�˱�������ԣ��ù�������ֵ����һ�γ�ʼ����������������Ϊ�����

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

	//��һ�����������ʱ������ϵͳ��Ϊ����Ķ�����һ��ָ���Ա������ָ���������Ӷ���
	//��ָ���Ϊ�����ָ�롣
	
	D dd;
	A *pA;
	pA = &dd;
	pA->f();
	return 0;
}
#endif


//����������������Ĺ��캯��
//�������������Ϊ��������
//ֻ����������Ĺ��캯�����������Ĺ��캯���������B��C��A�Ĺ���ͻᱻ����
//�м���������Ĺ���ᱻ���ԡ�����
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
class 5		//����D�ȹ������A
class 2		//����B�У���A�Ĺ��챻����
class 4		//����C�У���A�Ĺ��챻����
class 5		//���ִ��D��������
*/