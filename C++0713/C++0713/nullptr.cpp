#include<iostream>
using namespace std;

void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}
void TestFunc(int* a)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int a = 10;
	int* pa1 = &a;
	int* pa2 = NULL;

	TestFunc(0);
	TestFunc(NULL);		//NULL�Ǻ궨�� ��0 ������int���ã� �����ǵ���ָ�����
		//C++11 ��nullptr��ʾ��ָ��	���µĹؼ���
	TestFunc(nullptr);	//������Ϊָ�����
	return 0;
}