#if 0
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
	/*	_year = year;
		_month = month;
		_day = day;*/
		cout << "Date()" << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	void PrintDate()const
	{
		//_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}


private:
	int _year;
	int _month;
	int _day;
};

//C++动态内存管理
int main()
{
	//在C++中，使用malloc申请内置类型空间 没有任何问题
	Date* pd = (Date*)malloc(sizeof(Date));
	free(pd);

	//new 类型
	Date* pd2 = new Date;
	delete pd2;
	//调用构造和析构函数

	//new[]:申请连续空间
	Date* pd3 = new Date[10];	//调用10次构造函数
	delete[] pd3;

	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];
	int* p4 = new int[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;


	return 0;
}
#endif