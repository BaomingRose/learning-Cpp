#include<iostream>
using namespace std;

#if 0
//����ֵ�ķ�ʽ���Σ�����������������һ��ʵ�εĿ���
//��ֵ���ŵ�--> �����ĸ����ò���Ӱ���ⲿ��ʵ��
//		ȱ��--> ����Ч�ʵͣ�����ͨ���βθı�ʵ��
void Swap(int left, int right)
{
	cout << &left << " " << &right << endl;
	int temp = left;
	left = right;
	right = temp;
}

//����ַ���ŵ�--> ����Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ��
//			ȱ��--> ����ȫ���ɶ��Բ�
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//���ã�ͨ����ֵ�ķ�ʽ�������𵽽���������

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
	int& ra = a;		//�������ͱ��������ʵ��������ͬ
	ra = 100;
	const int b = 10;
	const int& rb = b;

	double d = 12.34;
	const int& rd = d;		//�����const����ͨ������
	d = 23.34;		//rd����12	d �� rd ����ͬһ���ڴ�ռ䣬rd���õĲ�����d
					//rd��d���Ͳ�ͬ����ǿתint�����µ���ʱ�ռ�
					//�¿��ٵĿռ��û��������û�е�ַ����ʱ�ռ���г��ԣ�����Ҫ��const

	return 0;
}
#endif

//�����ڶ���ʱ�����ʼ��
//һ�����������ж������
//����һ������һ��ʵ�壬�ٲ�����������ʵ��

//ʹ�ó�����1.������������ã�����õ��Ǹ��ṹ��ĳ�Ա�������������д��
//			2.�������Ĳ���
//			3.������ֵ---һ�����ܷ��غ���ջ�ϵĿռ䣬���ؽ�����������ڲ��ܺ������ƾͿ��ԣ�ʵ����������ڱȺ�������

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
	Add(3, 4);				//��Ȼʹ����һ��Add�����Ŀռ�
	printf("%d", ret);		//ret = 7
	printf("%d", ret);		//-858993460
							//�ռ��Ѿ����޸�
							//�������ù��̣�Add�������ý�������ջ�ռ䱻����ϵͳ����
	return 0;
}
