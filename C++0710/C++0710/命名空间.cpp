#include<stdio.h>

//C语言：命名冲突
namespace N1		//命名空间：作用域
{
	int a = 10;
	int add(int left, int right)
	{
		return left + right;
	}
}
//命名空间可以嵌套
namespace N2
{
	int a = 10;
	int Sub(int left, int right)
	{
		return left - right;
	}
	namespace N3
	{
		int a = 20;
		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}
//如果一个工程中定义了相同名称的命名空间，编译器会将相同名称命名空间中内容合并到一起
namespace N1
{
	int c = 10;
	int d = 20;
	int Dic(int left, int right)
	{
		return left / right;
	}
}

//int a = 20;

#if 0
int main()
{
	int a = 30;
	printf("%d \n", a);		//局部变量a
	printf("%d \n", ::a);	//全局变量a
	printf("%d \n", N1::a);	//命名空间N1的a
	printf("%d \n", N2::a);
	printf("%d \n", N2::N3::a);
	printf("%d \n", N1::c);
	return 0;
}
#endif


#if 0
using N1::a;
using namespace N1;

int main()
{
	printf("%d \n", a);
	return 0;
}

#endif