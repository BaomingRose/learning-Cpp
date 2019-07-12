#include<iostream>
using namespace std;

//auto修饰的变量，是具有自动存储器的局部变量（早期含义）
//C++11中，auto作为一个新的类型指示符来指示编译器
#if 0
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = 12.34;
	//auto声明的变量必须由编译器在编译时推导而得 (必须初始化)
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;	//double
	cout << typeid(c).name() << endl;	//char
	cout << typeid(d).name() << endl;	//int	
	return 0;
}
#endif

#if 0
int main()
{
	//声明指针的时候，auto和auto*没有任何区别
	int a = 10;
	auto pa1 = &a;		//int* ---> auto
	auto* pa2 = &a;		//int*   int --->auto

	auto& ra = a;		//必须有&
	ra = 100;

	auto rra = a;

	cout << typeid(pa1).name() << endl;		//int*
	cout << typeid(pa2).name() << endl;		//int*

	cout << typeid(ra).name() << endl;	
	cout << typeid(rra).name() << endl;	
	return 0;
}
#endif

int main()
{
	auto a = 10, b = 20;
	//auto c = 10, d = 12.34;	//所有初始化类型必须相同
	return 0;
}

//auto不能推导的场景
//1.不能作为函数参数	带有缺省值也不可以
//2.不能直接用来声明数组
//3.为了避免与C++98混淆，只保留了C++11作为类型指示符的用法
//4.新式for循环
//5.不能定义非静态成员变量
//6.实例化模板不能使用auto作为模板参数