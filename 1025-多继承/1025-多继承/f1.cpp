#include<iostream>
using namespace std;

#if 0
//��̳й���˳��͵��̳�˳������

class B1 {
private:
	int b1;
public :
	B1() {
		cout << "���� B1" << endl;
	}
	B1(int i) {
		b1 = i;
		cout << "���� B1" << endl;
	}
	void print() {
		cout << b1 << endl;
	}
	~B1(){
		cout << "B1����" << endl;
	}
};

class B2 {
private:
	int b2;
public:
	B2() {
		cout << "���� B2" << endl;
	}
	B2(int i) {
		b2 = i;
		cout << "���� B2" << endl;
	}
	void print() {
		cout << b2 << endl;
	}
	~B2() {
		cout << "B2 ����" << endl;
	}
};

class B3 {
private:
	int b3;
public:
	B3() {
		cout << "���� B3" << endl;
	}
	B3(int i) {
		b3 = i;
		cout << "���� B3" << endl;
	}
	void print() {
		cout << b3 << endl;
	}
	int getb3() {
		return b3;
	}
	~B3() {
		cout << "B3 ����" << endl;
	}
};

//����B1��B2��˳�������涨���������˳��
class A : public B2, public B1 {
private:
	int a;
	B3 bb;
public:
	A() {
		cout << "A����" << endl;
	}
	A(int i, int j, int k, int l) : B1(i), B2(j), bb(k) {
		a = l;
		cout << "���� A" < c< endl;
	}
	void print() {
		B1::print();
		B2::print();
		cout << a << "," << bb.getb3() << endl;
	}
	~A() {
		cout << "A ����" << endl;
	}
};

int main() {
	A aa;// (1, 2, 3, 4);

	aa.print();
	
	return 0;
}
#endif

/*
���� B2
���� B1
���� B3
���� A
1
2
4,3
A ����
B3 ����
B1����
B2 ����
*/

/*
��Ĭ�Ϲ���ʱ��
���� B2
���� B1
���� B3
A����
-858993460
-858993460
-858993460,-858993460
A ����
B3 ����
B1����
B2 ����

*/
