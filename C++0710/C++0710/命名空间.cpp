#include<stdio.h>

//C���ԣ�������ͻ
namespace N1		//�����ռ䣺������
{
	int a = 10;
	int add(int left, int right)
	{
		return left + right;
	}
}
//�����ռ����Ƕ��
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
//���һ�������ж�������ͬ���Ƶ������ռ䣬�������Ὣ��ͬ���������ռ������ݺϲ���һ��
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
	printf("%d \n", a);		//�ֲ�����a
	printf("%d \n", ::a);	//ȫ�ֱ���a
	printf("%d \n", N1::a);	//�����ռ�N1��a
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