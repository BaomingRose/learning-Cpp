#include<iostream>
#include<cmath>
using namespace std;
const double PI = 4 * atan(1);

class point {
protected:
	int x, y;
public:
	point(int a = 0, int b = 0) : x(a), y(b) {
		cout << "点构造" << endl;
	}

	virtual ~point() {
		cout << "点析构" << endl;
	}

	virtual void print() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class line : public point {
public:
	line(int a, int b, int c, int d) : point(a, b), x1(c), y1(d) {
		cout << "线构造" << endl;
	}

	~line() {
		cout << "线析构" << endl;
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
		cout << "圆的构造" << endl;
	}

	double getLen() {
		return 2 * PI * r;
	}

	double getArea() {
		return PI * pow(r, 2);
	}

	void print() {
		cout << "圆心：" << '(' << x << ',' << y << ')' << endl;
		cout << "半径：" << r << endl;
	}	
};


int main() {
	//子类指针指向子类对象，将隐藏父类重名的print()函数
	line* l = new line(0, 0, 1, 3);
	cout << l->getLen() << endl;

	l->print();

	delete l;

	//父类指针指向子类对象,没有虚函数时，将对子类对象进行切割，调用父类print函数,析构也只调用父类析构
	//有虚函数时，动态联编，调用子类的print函数
	//对析构函数设为虚函数时，会动态联编，调用子类的析构，再调用父类的析构
	point* p = new line(0, 0, 10, 10);
	p->print();

	delete p;

	point* pc = new circle(0, 0, 10);
	pc->print();
	delete pc;
	return 0;
}

//总结：父类指针指向子类对象时，会进行切割，当有虚函数时会动态联编，否则仍然使用父类的函数定义
//		隐藏是针对子类对象的，line l = new line(1,2,3,4) 会隐藏父类的重名函数或变量