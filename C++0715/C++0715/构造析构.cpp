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


//Ĭ�ϵĹ��캯����
//1.����û�û����ʾʵ���κι��캯������������������Ĭ�Ϲ��캯��
//2.�û������޲εĹ��캯��
//3.�û�����ȫȱʡ�����Ĺ��캯��
class Date
{
public:
	//���캯��:������������ͬ�����������Ͷ����ɱ������Զ���ɣ�û�з���ֵ
	//��������
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�޲ι��캯����ȫȱʡ�Ĺ��캯������ͬʱ����
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
	//Time _t;			//����Time��Ĺ��캯��
};
						//ֻҪ��������ɹ���Ҫ���ù��캯��

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

	//��������, û�в���ԭ������������������ȥ
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

	// d --> t --> ����ʱ����Ĺ��캯��
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
	//��ʼ���б�
	Date(int year = 2000, int month = 1, int day 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		//һ�����뵽���캯�����У������Ѿ������ɹ�
		//��ֵ�����ǳ�ʼ��
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
