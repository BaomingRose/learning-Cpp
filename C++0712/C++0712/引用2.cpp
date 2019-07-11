//引用在底层实际就是按照指针的方式进行处理的
//实际上：引用类型的变量也有空间，空间中实际存放的是引用实体的地址
//概念：引用与其实体公用同一块空间    引用--->实体的别名
//T& <==> T* const	(不能改变指向的指针)
//const T& <==> const T* const
#include<iostream>
#include<time.h>
using namespace std;

#if 0
void TestFunc1(int a)
{}

void TestFunc2(int & a)
{}

void TestFunc3(int * a)
{}

void TestRefAndValue()
{
	int a = 0;	
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);//以引用作为函数参数
	size_t end2 = clock();

	//分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int ) - time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int &) - time:" << end2 - begin2 << endl;
}
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

//引用和指针不同：
//1.引用在定义时必须初始化，指针没有要求
//2.引用在初始化时引用一个实体后，就不能在引用其他实体，而指针可以
//	在任何时候指向任何实体
//3.没有NULL引用，但有NULL指针
//4.在sizeof中含义不同：引用结果为引用类型的大小，
//	但指针始终是地址空间所占字节个数（32位平台下占4个字节）
//5.引用自加即引用的实体 + 1，指针自加即指针向后偏移一个类型的大小
//6.有多级指针，但是没有多级引用
//7.访问实体方式不同，指针需要显示解引用，引用编译器自己处理
//8.引用比指针用起来相对安全
