#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*================================================
 * description：像sort函数，自定义类型需要传入自定义排序方法，如果每个类都要有一个仿函数，需要写很多，名字也不好命名，所以需要Lamda表达式
			Lamda表达式：匿名函数	基本格式 ：[捕捉列表](参数)->返回类型{ 函数体 };
 =================================================*/
struct Com {
	bool operator()(int a, int b) {
		return a < b;
	}
};
void testSort() {
	vector<int> a = { 10, 1, 3, 9, 2, 0, -1, 30 };
	sort(a.begin(), a.end(), Com());

	sort(a.begin(), a.end(), [](int a, int b){ return a > b; });

	//最简单的labmda表达式
	[]{};
}

void testLamdaList() {
	//捕捉列表： 捕捉父作用域(祖先作用域)中的变量，供lambda表达式的函数体使用
	int a = 10;
	int b = 1;

	// [a,b]: 以传值的形式捕捉父作用域中的变量a,b
	[a, b]()->int{ return a + b; };

	// [=]: 以传值的形式捕捉父作用域中的所有变量(已经声明或定义的)
	[=]()->int{return a + b; };

	//c变量在表达式之前没有定义，故不能用
	//[=]()->int{return a + b + c; };
	int c = 100;

	// [&a,&b]: 以传引用的形式捕捉父作用域中的变量a,b
	[&a, &b]()->int{ return a + b; };

	// [&]: 以传引用的形式捕捉父作用域中的所有变量(已经声明或定义的)
	[&]()->int{ return a + b; };

	// [=, &b]: 以传值的形式捕捉父作用域中的除b之外的所有变量(已经声明或定义的)， b以引用的方式捕捉
	[=, &b]()->int{ return a + b; };

	// [&, b]: 以传引用的形式捕捉父作用域中的除b之外的所有变量(已经声明或定义的)， b以传值的方式捕捉
	[&, b]()->int{ return a + b; };

	// [=, b]: 此种写法不对，捕捉方式不能重复
	// [&, &b]: 不对， 同上
	//[=, b]()->int{ return a + b; };
}

void testMutable() {
	int a = 10, b = 20;

/*
	[=]()->int {
		//a, b都为const变量, 不能修改a，b的值
		a = 100;
		b = 20;
		return a + b; 
	};
*/

	// mutable: 改变从捕捉列表中捕获的变量的常性， 即变量可以修改
	[=]()mutable->int {
		//mutable使a, b都为非const变量， 可以修改
		a = 100;
		b = 20;
		return a + b; 
	};
}

/*================================================
 * description：对捕捉列表和mutable进一步
			//lamda表达式只是一个函数，可以理解为一个声明，没有调用时不会改变的
=================================================*/
int g_globle = 1000;

int main() {

	int a = 10, b = 100;

	//lamda表达式只是一个函数，可以理解为一个声明，没有调用时不会改变的
#if 0	//这个是将父作用域的变量全部值传递，不能修改其中的值，像a = 1000是错误的
	[=]()->int {
		//a = 1000;
		g_globle = 10;
		return 0;
	};
	cout << g_globle << endl;
#endif

#if 0	//mutable只是去掉常性，没有真正改变父类作用域的变量值，毕竟是值传递
	for (int i = 0; i < 1; ++i) {
		//这个等号也有将爷爷作用域的变量全部捕捉进来了, 
		[=]()mutable->int {
			//a = 1000;
			a = 1000;
			return a + b;
		};
	}
	cout << a << endl;	// 并没有调用函数，只是声明了，a仍然是10
#endif

	auto fun = [=]()mutable->int {
		g_globle = 10;
		a = 100000;
		return a + b;
	};
	int c = fun();
	cout << "c:" << c << endl;
	cout << "g_globle:" << g_globle << endl;
	cout << a << endl;	//这里的a仍然是10,毕竟传的值，mutable只是在函数体内可以修改，并不是改真正的父作用域的变量

	return 0;
	}

/*================================================
 * description：Lamda表达式之间的赋值
=================================================*/
void(*ptr)();

void testLam() {
	auto fun = [](){int a = 10; int b = 20;  return a + b; };
	cout << fun() << endl;
	auto fun2 = [](){int a = 10; int b = 20;  return a + b; };
	//lambda表达式之间不能赋值
	//fun = fun2;

	auto fun3 = [](){int a = 10; int b = 20; cout << a << " " << b << endl; };
	//函数指针和lambda表达式之间可以赋值
	ptr = fun3;
	fun3();
	ptr();
}

/*================================================
 * description：测试Lamda表达式实现原理，对比仿函数和Lamda表达式的反汇编代码，
				可以得到结论：Lamda表达式实现是通过仿函数类实现，重载了（）运算符函数
=================================================*/
void testLam2() {
	Com com;
	int a = 1;
	int b = 2;
	com(a, b);

	auto fun = [](int a, int b)->bool{
		return a > b;
	};

	fun(a, b);
}

#endif
