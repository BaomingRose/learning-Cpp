#include<iostream>
using namespace std;

//子类和父类有同名变量m_a, 隐藏父类的成员变量和成员函数
//子类指针可以转化为父类指针，反之不行
//只要名字相同就隐藏，而不是构成重载比如：
//void TestBase::func(int i)并不是和子类的func构成重载

//访问父类被隐藏成员方式：
/*
1.将子类对象的指针转化为父类的指针
2.可以用 父类类名：：成员 的方式直接访问
*/
class TestBase {
public:
	int m_a;
	TestBase(int i) : m_a(i) {

	}

	void func() {
		cout << "我是父类的函数" << endl;
	}
};

class Test : public TestBase {
public:
	int m_a;
	//
	Test(int a, int b) : TestBase(a), m_a(b) {

	}

	void func() {
		cout << "我是子类的函数" << endl;
	}
};

int main() {
#if 0
	Test t(1, 2);
	//父类的m_a被隐藏
	cout << t.m_a << endl;	//2
#endif

#if 0
	Test* pt = new Test(5, 6);	//子类指针
	TestBase* ptb = pt;			//把子类切割赋给父类指针
	cout << pt->m_a << endl;	//6
	cout << ptb->m_a << endl;	//5
#endif

#if 0
	Test t(5, 6);
	//父类方法被隐藏
	t.func();

	Test* pt = new Test(5, 6);	
	TestBase* ptb = pt;		//仍然将子类切割赋给父类指针
	pt->func();		//调用子类方法
	ptb->func();	//调用父类
#endif


	return 0;
}

//建议：
/*
1.不要在派生类中定义根基类成员同名的成员
2.继承一般只采用public方式
*/