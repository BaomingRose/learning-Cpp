#include<iostream>
using namespace std;

//auto���εı������Ǿ����Զ��洢���ľֲ����������ں��壩
//C++11�У�auto��Ϊһ���µ�����ָʾ����ָʾ������
#if 0
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = 12.34;
	//auto�����ı��������ɱ������ڱ���ʱ�Ƶ����� (�����ʼ��)
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;	//double
	cout << typeid(c).name() << endl;	//char
	cout << typeid(d).name() << endl;	//int	
	return 0;
}
#endif

#if 0
int main()
{
	//����ָ���ʱ��auto��auto*û���κ�����
	int a = 10;
	auto pa1 = &a;		//int* ---> auto
	auto* pa2 = &a;		//int*   int --->auto

	auto& ra = a;		//������&
	ra = 100;

	auto rra = a;

	cout << typeid(pa1).name() << endl;		//int*
	cout << typeid(pa2).name() << endl;		//int*

	cout << typeid(ra).name() << endl;	
	cout << typeid(rra).name() << endl;	
	return 0;
}
#endif

int main()
{
	auto a = 10, b = 20;
	//auto c = 10, d = 12.34;	//���г�ʼ�����ͱ�����ͬ
	return 0;
}

//auto�����Ƶ��ĳ���
//1.������Ϊ��������	����ȱʡֵҲ������
//2.����ֱ��������������
//3.Ϊ�˱�����C++98������ֻ������C++11��Ϊ����ָʾ�����÷�
//4.��ʽforѭ��
//5.���ܶ���Ǿ�̬��Ա����
//6.ʵ����ģ�岻��ʹ��auto��Ϊģ�����