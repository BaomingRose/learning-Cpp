#include<iostream>
using namespace std;


#if 0
//泛型编程：编写与类型无关的通用代码， 是代码复用的一种手段。模板是泛型编程的基础。
//多个类型在参数列表都要声明，每个前面都要有typename或class

//函数模板不是真正的函数，是编译器生成代码的模具
template<typename T>	//模板参数列表
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}
//非模板函数可以和一个同名的函数模板同时存在
int Add(int left, int right)
{
	return left + right;
}

//编译阶段	模板参数推演 ---> T的实际类型 --->	生成代码


int main()
{
	cout << Add(1, 2) << endl;	//优先调用用户写的int
	cout << Add(1.0, 2.0) << endl;
	cout << Add<>(1, 2) << endl;	//显式实例化
	cout << Add<>(1, 2) << endl;	//隐式实例化 优先调用模板生成函数
	cout << Add<double>(1, 2.0) << endl;	//显试实例化-->直接将T的类型实力化为参数类型，不需要对实参的类型进行推演
					//在代码执行时，可能会实参做隐式类型转化


	return 0;
}
#endif


#if 0
template<typename T1, typename T2>	//模板参数列表
T1 Add(T1 left, T2 right)
{
	cout << typeid(T1).name() << endl;
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;		//调用用户写的
	cout << Add(1, 2.0) << endl;	//如果模板可以产生一个具有更好匹配的函数，那么选择模板
	return 0;
}
#endif
//模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
