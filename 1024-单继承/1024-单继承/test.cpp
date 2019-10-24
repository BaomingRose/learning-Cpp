#if 1
#include<iostream>
using namespace std;

/**����Ĺ�����̣�
  *����Ĺ���
  *�������������ĳ�Ա�����Ĺ��죨����У�
  *����Ĺ���
  */
/*�����պú͹�������෴*/

class A {
private:
	int a;
public:
	A() {
		a = 100000;
		cout << "AĬ�Ϲ���" << endl;
	}

	A(int i) {
		a = i;
		cout << "A�вι���" << endl;
	}

	~A() {
		cout << "A����" << endl;
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
		cout << "BĬ�Ϲ���" << endl;
	}

	B(int i) {
		b = i;
		cout << "B���ι���" << endl;
	}

	B(int i, int j, int k) : A(i), aa(j), b(k) {
		cout << "B��ι���" << endl;
	}

	~B() {
		cout << "B����" << endl;
	}

	void print() {
		A::print();
		aa.print();
		cout << "B::b =" << b << endl;
	}
};

int main() {
	//������������Ĭ�Ϲ��캯��
	B bb[2];
	//��ֵ�����л�����µ��вι���
	//֮ǰĬ�Ϲ���Ķ���ᱻ����
	//����������ֵ����ʱ����
	bb[0] = B(1, 2, 4);
	bb[1] = B(3, 4, 7);
	bb[0].print();
	bb[1].print();

	//�������������

	return 0;
}
#endif

/*���н����
AĬ�Ϲ���
AĬ�Ϲ���
BĬ�Ϲ���
AĬ�Ϲ���
AĬ�Ϲ���
BĬ�Ϲ���
A�вι���
A�вι���
B��ι���
B����
A����
A����
A�вι���
A�вι���
B��ι���
B����
A����
A����
A::a = 1
A::a = 2
B::b =4
A::a = 3
A::a = 4
B::b =7
B����
A����
A����
B����
A����
A����
*/