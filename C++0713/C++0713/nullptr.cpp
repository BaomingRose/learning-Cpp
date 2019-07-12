#include<iostream>
using namespace std;

void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}
void TestFunc(int* a)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int a = 10;
	int* pa1 = &a;
	int* pa2 = NULL;

	TestFunc(0);
	TestFunc(NULL);		//NULL是宏定义 是0 将当作int调用， 并不是当作指针调用
		//C++11 用nullptr表示空指针	是新的关键字
	TestFunc(nullptr);	//将被视为指针调用
	return 0;
}