#include<iostream>
using namespace std;

#if 0
//按照值的方式传参，将来编译器会生成一份实参的拷贝
//传值：优点--> 函数的副作用不会影响外部的实参
//		缺点--> 传参效率低，不能通过形参改变实参
void Swap(int left, int right)
{
	cout << &left << " " << &right << endl;
	int temp = left;
	left = right;
	right = temp;
}

//传地址：优点--> 传参效率高，可以通过形参改变外部的实参
//			缺点--> 不安全，可定性差
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//引用；通过传值的方式，可以起到交换的作用

int main()
{
	int a = 10;
	int b = 20;
	cout << &a << " " << &b << endl;
	Swap(a, b);
	Swap(&a, &b);
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	int& ra = a;		//引用类型必须和引用实体类型相同
	ra = 100;
	const int b = 10;
	const int& rb = b;

	double d = 12.34;
	const int& rd = d;		//必须加const才能通过编译
	d = 23.34;		//rd还是12	d 和 rd 不在同一块内存空间，rd引用的并不是d
					//rd与d类型不同，将强转int开辟新的临时空间
					//新开辟的空间既没有名字已没有地址，临时空间具有常性，所以要加const

	return 0;
}
#endif

//引用在定义时必须初始化
//一个变量可以有多个引用
//引用一旦引用一个实体，再不能引用其他实体

//使用场景：1.起别名（不常用）（最常用的是给结构体的成员起别名，更容易写）
//			2.作函数的参数
//			3.作返回值---一定不能返回函数栈上的空间，返回结果的生命周期不受函数控制就可以（实体的生命周期比函数长）

#if 0
void Swap(int& left, int& right)
{
	cout << &left << " " << &right << endl;
	int temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << endl << b << endl;
	return 0;
}
#endif

int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}

int main3()
{
	int& ret = Add(1, 2);
	Add(3, 4);				//仍然使用上一次Add函数的空间
	printf("%d", ret);		//ret = 7
	printf("%d", ret);		//-858993460
							//空间已经被修改
							//函数调用过程：Add函数调用结束后函数栈空间被操作系统回收
	return 0;
}
