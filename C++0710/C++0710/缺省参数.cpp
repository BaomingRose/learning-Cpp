#include<iostream>
using namespace std;

#if 0

//ȱʡ��������̥���� �����ǳ�������ȫ�ֱ���
//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}

//ȫȱʡ������ÿ����������Ĭ��ֵ
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

//��ȱʡ���������ֲ�������ȱʡֵ
//����ֻ�ܴ�������һ�θ��������ܴ������Ҳ�������Ÿ�
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(100, 100, 200);
	TestFunc(100, 200);
	TestFunc();
	return 0;
}

#endif

//ȱʡ���������Ͷ�������λ�ö����Ը�����ֻ����һ��λ�ø����� ��������λ��ͬʱ��
//������λ�ú�	��������ͷ�ļ������㿴����ͷ�ļ�����Ҫ֪����û��ȱʡ������
void TestFunc(int a = 10);

void TestFunc(int a)
{

}

//  .lib ��̬���ļ�		.dll ��̬���ļ�