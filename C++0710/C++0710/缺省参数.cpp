#include<iostream>
using namespace std;

#if 0

//缺省参数（备胎）， 必须是常量或者全局变量
//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}

//全缺省参数：每个参数都带默认值
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

//半缺省参数：部分参数带有缺省值
//规则：只能从右往左一次给出，不能从左给，也不能跳着给
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(100, 100, 200);
	TestFunc(100, 200);
	TestFunc();
	return 0;
}

#endif

//缺省参数声明和定义两个位置都可以给，但只能在一个位置给出， 不能两个位置同时给
//在声明位置好	（声明在头文件，给你看的是头文件，需要知道有没有缺省参数）
void TestFunc(int a = 10);

void TestFunc(int a)
{

}

//  .lib 静态库文件		.dll 动态库文件