//�����ڵײ�ʵ�ʾ��ǰ���ָ��ķ�ʽ���д����
//ʵ���ϣ��������͵ı���Ҳ�пռ䣬�ռ���ʵ�ʴ�ŵ�������ʵ��ĵ�ַ
//�����������ʵ�幫��ͬһ��ռ�    ����--->ʵ��ı���
//T& <==> T* const	(���ܸı�ָ���ָ��)
//const T& <==> const T* const
#include<iostream>
#include<time.h>
using namespace std;

#if 0
void TestFunc1(int a)
{}

void TestFunc2(int & a)
{}

void TestFunc3(int * a)
{}

void TestRefAndValue()
{
	int a = 0;	
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);//��������Ϊ��������
	size_t end2 = clock();

	//�ֱ���������������н������ʱ��
	cout << "TestFunc1(int ) - time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int &) - time:" << end2 - begin2 << endl;
}
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

//���ú�ָ�벻ͬ��
//1.�����ڶ���ʱ�����ʼ����ָ��û��Ҫ��
//2.�����ڳ�ʼ��ʱ����һ��ʵ��󣬾Ͳ�������������ʵ�壬��ָ�����
//	���κ�ʱ��ָ���κ�ʵ��
//3.û��NULL���ã�����NULLָ��
//4.��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С��
//	��ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ�����32λƽ̨��ռ4���ֽڣ�
//5.�����ԼӼ����õ�ʵ�� + 1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С
//6.�ж༶ָ�룬����û�ж༶����
//7.����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʾ�����ã����ñ������Լ�����
//8.���ñ�ָ����������԰�ȫ
