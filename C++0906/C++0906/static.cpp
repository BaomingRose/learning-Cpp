#include <iostream>
using namespace std;

/*静态成员

静态成员跟类走不跟对象走，类在他在，而一般成员是对象在他才在。
所以静态成员可以通过类名直接调用，而普通成员必须通过对象调用。

静态成员也有private，public，protected之分
一、静态成员变量
1、所有对象共享，无论谁改了，所有的一起改
2、存储在全局区，不占用类的空间，所以取sizeof的时候不算在内
3、赋初值只能在类外，赋值时不加static，用“类型 类名::变量名 = n” 直接赋值
二、静态成员函数
只能直接访问静态成员变量，无法访问其他的普通成员，因为他没有this指针
*/
class TestSt {
public:
	int a;
	static int m_s_i;

	TestSt() {
		m_s_i++;
	}

	static void testst() {
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;

int main() {
	/*	TestSt t1;
		cout << t1.m_s_i << endl;
		TestSt t2;
		cout << t1.m_s_i << endl;
		cout << t2.m_s_i << endl;
		TestSt t3;
		cout << t1.m_s_i << endl;
		cout << t2.m_s_i << endl;
		cout << t3.m_s_i << endl;
		*/
	TestSt::testst();
	cout << TestSt::m_s_i << endl;		//4
	return 0;
}