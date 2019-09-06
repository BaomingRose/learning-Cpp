#if 0
#include <iostream>
using namespace std;

/*
初始化列表
1、狭义初始化
在定义变量的时候直接进行初始化的这种行为叫做狭义初始化：
int a = 3;
2、广义初始化
第一次给变量赋值就叫做初始化的情况叫广义初始化
int a;
...//跟a无关的代码
a = 3

初始化列表相当于狭义初始化，而构造函数内部相当于广义初始化

所以初始化列表可以解决一些只能用狭义初始化进行初始化的变量，例如：
const变量
引用
没有无参构造的类的对象
*/

/*
explicit：阻止单参构造的不规范调用

单参数的构造函数，可以用=直接调用，例如：
假设CT类中有一个单参数的构造函数，参数类型为int或int相关类型，那么，“CT a = 3;” 
这种写法就是被允许的，但是这种写法十分别扭，看上去好像直接把3赋给了a，为了避免这种写法，
可以在构造函数加explicit，使得这样的写法变得无效。
*/

class Test2 {
public:
	int b;
	explicit Test2(int a) :b(a) {}

	Test2(Test2 & t) {
		b = t.b;
	}

};

class Test {
public:
	int a = 5;
	const int i = 3;
	int &ri;
	Test2 t2;

	Test(int &a) : ri(a), t2(a) {}
};


int main() {
	int i = 8;
	int j = 9;
	Test2 a(i);
	Test2 b = a;
	Test2 c(j);
	//Test2 d = 1;
	c = b;

	cout << c.b << endl;		//8

	return 0;
}
#endif