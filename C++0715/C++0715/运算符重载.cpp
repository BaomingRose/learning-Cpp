#include<iostream>
using namespace std;
#include<assert.h>
#include<malloc.h>

//����������Ǿ������⺯�����ĺ�����Ҳ�����䷵�ص����ͣ�
//��������Ϊ���ؼ���operator �������Ҫ���ص����������
//����ԭ�ͣ�����ֵ���� operator�������������б�
//���ز�����������һ�������ͻ���ö�����͵Ĳ�����
//.*	::	sizeof	?:	.	��5���������������
//����ͨ���������������������µĲ�����������@

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

	//const��Ա�����в����޸ĳ�Ա����
	//const����thisָ�룬��������ǰ�����е����ݲ������޸�
	//const Date* const		this�Ȳ��ܸı�ָ��Ҳ�����޸�����
	void PrintDate()const
	{
		//_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//����������������
	//Date* const	this�����޸�ָ��
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
//��Ϊ���Ա�����غ���ʱ�����βο������Ȳ�������Ŀ��1��Ա�����Ĳ�������һ��Ĭ�ϵ��β�this��
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

	//�����������͵Ĳ��������京�岻�ܸı䣬���磺���õ�����+�� ���ܸı��京��
	//d1 + 10 ��d1���޸ģ���+�ĺ������
	/*Date operator+(int days)
	{
		_day += days;
		return *this;
	}*/

	//�޸�
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

//��������� ---> ����
//������˽�б���
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
		cout << "ͬ��ͬ��ͬ����" << endl;
	}

	if (d1 == d2)
	{
		cout << "ͬ��ͬ��ͬ����" << endl;
	}

	if (d3 != d1) {
		cout << "��ͬ" << endl;
	}
	d2.PrintDate();
	d2 = d1 + 10;
	d2.PrintDate();

	d2 = d1 = d3;

	Date& d4 = d1;
	d4 = d1;

	return 0;

}