#include<iostream>
using namespace std;


#if 0
//���ͱ�̣���д�������޹ص�ͨ�ô��룬 �Ǵ��븴�õ�һ���ֶΡ�ģ���Ƿ��ͱ�̵Ļ�����
//��������ڲ����б�Ҫ������ÿ��ǰ�涼Ҫ��typename��class

//����ģ�岻�������ĺ������Ǳ��������ɴ����ģ��
template<typename T>	//ģ������б�
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}
//��ģ�庯�����Ժ�һ��ͬ���ĺ���ģ��ͬʱ����
int Add(int left, int right)
{
	return left + right;
}

//����׶�	ģ��������� ---> T��ʵ������ --->	���ɴ���


int main()
{
	cout << Add(1, 2) << endl;	//���ȵ����û�д��int
	cout << Add(1.0, 2.0) << endl;
	cout << Add<>(1, 2) << endl;	//��ʽʵ����
	cout << Add<>(1, 2) << endl;	//��ʽʵ���� ���ȵ���ģ�����ɺ���
	cout << Add<double>(1, 2.0) << endl;	//����ʵ����-->ֱ�ӽ�T������ʵ����Ϊ�������ͣ�����Ҫ��ʵ�ε����ͽ�������
					//�ڴ���ִ��ʱ�����ܻ�ʵ������ʽ����ת��


	return 0;
}
#endif


#if 0
template<typename T1, typename T2>	//ģ������б�
T1 Add(T1 left, T2 right)
{
	cout << typeid(T1).name() << endl;
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;		//�����û�д��
	cout << Add(1, 2.0) << endl;	//���ģ����Բ���һ�����и���ƥ��ĺ�������ôѡ��ģ��
	return 0;
}
#endif
//ģ�庯���������Զ�����ת��������ͨ�������Խ����Զ�����ת��
