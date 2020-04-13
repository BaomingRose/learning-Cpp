#if 0
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*================================================
 * description：几个构造函数之间实现复用，下面一个参数的构造调用无参构造，两个参数的构造调用一个参数的构造
				构造函数不能同时委派，和使用初始化列表，也就是委派的列表只有一个其他的构造函数，不要循环调用
=================================================*/
class B {
public:
	B()	:_a(1), _b(2), _c(3) {}

	B(int a) : B() {
		_a = a;
	}

	B(int a, int b) : B(a) {
		_b = b;
	}

	B& operator=(const B& b) = delete;

private:
	int _a;
	int _b;
	int _c;
};
/*等号运算符重载被删除，不能实现
B& B::operator=(const B& b) {
	return B();
}
*/

void test1() {
	B b;
	B b2(10);
	B b3(10, 20);
	//b = b2;
}

/*================================================
 * description：默认函数控制	上面的测试删除了对赋值重载的函数
 必要时需要定义不带参数的版本以实例化无参的对象，而有时编译器会生成，有时又不生成，容易造成混乱，于是C++11让程序员可以控制是否需要编译器生成。
 使用=default显式缺省函数
=================================================*/
class C {
public:
	C(int c) :_c(c) {}

	C() = default;  //显示指定生成一个无参默认构造函数

	//函数体内声明，函数外赋为default
	C(const C& cc);

	C& operator=(const C& c) {
		cout << "C& operator=" << endl;
		return *this;
	}
private:
	int _c;
};
C::C(const C& cc) = default;

void test2() {
	C c;
	C d = c;
}

int main() {
	test1();
	test2();

	return 0;
}
#endif
