#include<iostream>
using namespace std;
#include<assert.h>
#include<malloc.h>

//运算符重载是具有特殊函数名的函数，也具有其返回的类型，
//函数名字为：关键字operator 后面接需要重载的运算符符号
//函数原型：返回值类型 operator操作符（参数列表）
//重载操作符必须有一个类类型或者枚举类型的操作数
//.*	::	sizeof	?:	.	这5个运算符不能重载
//不能通过连接其他符号来创建新的操作符：比如@

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{
		_year = 2000;
		_month = 1;
		_day = 1;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//const成员函数中不能修改成员变量
	//const修饰this指针，表明：当前对象中的内容不允许修改
	//const Date* const		this既不能改变指向，也不能修改内容
	void PrintDate()const
	{
		//_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//两个函数构成重载
	//Date* const	this不可修改指向
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool IsSame(const Date& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}
//作为类成员的重载函数时，其形参看起来比操作数数目少1成员函数的操作符有一个默认的形参this，
//
	bool operator==(const Date& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;

	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//用于内置类型的操作符，其含义不能改变，例如：内置的整型+， 不能改变其含义
	//d1 + 10 把d1给修改，将+的含义改了
	/*Date operator+(int days)
	{
		_day += days;
		return *this;
	}*/

	//修改
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}


private:
	int _year;
	int _month;
	int _day;
};

//运算符重载 ---> 函数
//访问了私有变量
/*bool operator==(const Date& left, const Date& right)
{
	return left._year == right._year &&
		left._month == right._month &&
		left._day == right._day;
}*/

int main()
{
	Date d1(2019, 7, 15);
	Date d2(2019, 7, 15);
	Date d3(2019, 7, 16);
	if (d1.IsSame(d2))
	{
		cout << "同年同月同日生" << endl;
	}

	if (d1 == d2)
	{
		cout << "同年同月同日生" << endl;
	}

	if (d3 != d1) {
		cout << "不同" << endl;
	}
	d2.PrintDate();
	d2 = d1 + 10;
	d2.PrintDate();

	d2 = d1 = d3;

	Date& d4 = d1;
	d4 = d1;

	return 0;

}