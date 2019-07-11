#include<iostream>
using namespace std;

//编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	int c;
	c = Add(a, b);
	cout << c << endl;
	return 0;
}

//C++有哪些技术替代宏
//常量定义 换用 const
//函数定义 换用内联函数