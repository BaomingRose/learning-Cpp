#include<iostream>
using namespace std;

//����ʱC++���������ڵ������������ĵط�չ����û�к���ѹջ�Ŀ���
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

//C++����Щ���������
//�������� ���� const
//�������� ������������