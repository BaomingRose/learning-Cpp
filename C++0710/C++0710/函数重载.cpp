//�������أ�C++�����ڣ�ǰ�ᣩ��һ���������������������Ƶ�ͬ��������
//��Щ�������β��б���벻ͬ: �������������͡�˳��
//�����������ֻ�Ƿ���ֵ���Ͳ�ͬ���ǲ��ܹ������ص�
//�����������������������Ͳ�ͬ������

#include<iostream>
using namespace std;

//C���Բ�֧������
//Ϊʲô��֧�֣���Դ�ļ��ĳ�.c�ļ����ֱ��������ͬ���ֺ�����ֻ���������壩���룬�۲���)
//��ΪC�����б������Ժ������ֵ����ι���ǳ��򵥣�ֻ�Ǻ�������ǰ����һ���»���
//��������д���ͬ���ĺ���ʱ�����������޷������ĸ�����
//C++�������Ժ����������ι���
//�����������ͱ��뵽���յĺ�������
int add(int left, int right)
{
	return left + right;
}

double add(double left, double right)
{
	return left + right;
}

int main()
{
	//�������ڱ����ڼ䣬�����ʵ�ε����ͽ������ݣ�
	//�������ݵĽ��ѡ����þ���ĺ���
	cout << add(1, 2) << endl;
	cout << add(1.0, 2.0) << endl;
	cout << add('1', '2') << endl;	//char --> int
	//add(1, 2.0)	����
	return 0;
}


//�޲κ�����ͬ����ȫȱʡ��������ͬʱ����
#if 0
void TestFunc()
{}

void TestFunc(int a = 10)
{}

int main()
{
	TestFunc(100);
	TestFunc();		//���� ��֪�������ĸ����� �ڶ�����Ĭ��a=10������
	return 0;
}

#endif


//C����д�Ŀ�
int Add(int left, int right);			//_Add

//C++
//Add(1, 2);				//?Add?@@YAHHH@Z
//������������ͬ
extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}