//函数重载：C++允许在（前提）用一作用域声明几个功能类似的同名函数，
//这些函数的形参列表必须不同: 参数个数、类型、顺序
//函数如果仅仅只是返回值类型不同，是不能构成重载的
//常用来处理功能类似数据类型不同的问题

#include<iostream>
using namespace std;

//C语言不支持重载
//为什么不支持（将源文件改成.c文件，分别对两个相同名字函数（只声明不定义）编译，观察结果)
//因为C语言中编译器对函数名字的修饰规则非常简单：只是函数名字前增加一个下划线
//如果工程中存在同名的寒素时，编译器就无法区分哪个函数
//C++编译器对函数名字修饰规则：
//将参数的类型编译到最终的函数名字
int add(int left, int right)
{
	return left + right;
}

double add(double left, double right)
{
	return left + right;
}

int main()
{
	//编译器在编译期间，必须对实参的类型进行推演，
	//根据推演的结果选择调用具体的函数
	cout << add(1, 2) << endl;
	cout << add(1.0, 2.0) << endl;
	cout << add('1', '2') << endl;	//char --> int
	//add(1, 2.0)	报错
	return 0;
}


//无参函数与同名的全缺省函数不能同时存在
#if 0
void TestFunc()
{}

void TestFunc(int a = 10)
{}

int main()
{
	TestFunc(100);
	TestFunc();		//报错 不知道调用哪个函数 第二个会默认a=10做参数
	return 0;
}

#endif


//C语言写的库
int Add(int left, int right);			//_Add

//C++
//Add(1, 2);				//?Add?@@YAHHH@Z
//两个编译器不同
extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}