#if 0
#include<iostream>
#include<assert.h>
#include<malloc.h>
using namespace std;


class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
		cout << "Time::Time(int, int, int):" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};


//默认的构造函数：
//1.如果用户没有显示实现任何构造函数，编译器将会生成默认构造函数
//2.用户定义无参的构造函数
//3.用户定义全缺省参数的构造函数
class Date
{
public:
	//构造函数:名字与类名相同，创建类类型对象由编译器自动完成，没有返回值
	//可以重载
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//无参构造函数和全缺省的构造函数不能同时存在
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

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	//Time _t;			//调用Time类的构造函数
};
						//只要创建对象成功就要调用构造函数

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 3)
	{
		cout << "SeqList(int):" << this << endl;
		_array = (DataType*)malloc(sizeof(DataType));
		if (nullptr == _array)
		{
			assert(0);
			return;
		}

		_capacity = capacity;
		_size = 0;
	}

	//析构函数, 没有参数原因：生不带来，死不带去
	~SeqList()
	{
		cout << "~SeqList():" << this << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqList()
{
	SeqList s;
}
#endif

#if 0
int main()
{
	//Date d(2019, 7, 14);
	////d.SetDate(2019, 7, 15);
	//d.PrintDate();

	// d --> t --> 调用时间类的构造函数
	//Date d1;
	//d1.PrintDate();

	//Date d2(2019, 7, 14);
	//d2.PrintDate();

	TestSeqList();
	return 0;
}
#endif

#if 0
class Date
{
public:
	//初始化列表
	Date(int year = 2000, int month = 1, int day 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		//一旦进入到构造函数体中，对象已经创建成功
		//赋值，不是初始化
		_year = year;
		_month = month;
		_day = day;
	}
	private:
	int _year;
	int _month;
	int _day;
};
#endif
