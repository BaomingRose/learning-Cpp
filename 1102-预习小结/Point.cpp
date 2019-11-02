#include<iostream>
#include<cmath>
using namespace std;
const double PI = 4 * atan(1);

class point {
protected:
	int x, y;
public:
	point(int a = 0, int b = 0) : x(a), y(b) {
		cout << "�㹹��" << endl;
	}

	virtual ~point() {
		cout << "������" << endl;
	}

	virtual void print() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class line : public point {
public:
	line(int a, int b, int c, int d) : point(a, b), x1(c), y1(d) {
		cout << "�߹���" << endl;
	}

	~line() {
		cout << "������" << endl;
	}

	double getLen() {
		int dx = x1 - x;
		int dy = y1 - y;
		return sqrt(pow(dx, 2) + pow(dy, 2));
	}

	virtual void print() {
		cout << '(' << x << ',' << y << ')' << "-(" << x1 << ',' << y1 << ')' << endl;
		cout << "len:" << getLen() << endl;
	}

private:
	int x1, y1;
};

class circle : public point {
private:
	int r;
public:
	circle(int a, int b, int R) : point(a, b), r(R) {
		cout << "Բ�Ĺ���" << endl;
	}

	double getLen() {
		return 2 * PI * r;
	}

	double getArea() {
		return PI * pow(r, 2);
	}

	void print() {
		cout << "Բ�ģ�" << '(' << x << ',' << y << ')' << endl;
		cout << "�뾶��" << r << endl;
	}	
};


int main() {
	//����ָ��ָ��������󣬽����ظ���������print()����
	line* l = new line(0, 0, 1, 3);
	cout << l->getLen() << endl;

	l->print();

	delete l;

	//����ָ��ָ���������,û���麯��ʱ�����������������и���ø���print����,����Ҳֻ���ø�������
	//���麯��ʱ����̬���࣬���������print����
	//������������Ϊ�麯��ʱ���ᶯ̬���࣬����������������ٵ��ø��������
	point* p = new line(0, 0, 10, 10);
	p->print();

	delete p;

	point* pc = new circle(0, 0, 10);
	pc->print();
	delete pc;
	return 0;
}

//�ܽ᣺����ָ��ָ���������ʱ��������и�����麯��ʱ�ᶯ̬���࣬������Ȼʹ�ø���ĺ�������
//		����������������ģ�line l = new line(1,2,3,4) �����ظ�����������������