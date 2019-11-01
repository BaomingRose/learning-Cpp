#if 0
#include<iostream>
using namespace std;

/*
����ģʽ��
����˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������
   1. ���캯��˽�л�
   2. �ṩһ��static���нӿڷ��ض���
   3. ����һ��static�����Ա
   4. ������:��������ֻ������ʵ��
*/

class Singleton {
public:
	static Singleton* getInstance() {
		return &_instance;
	}
private:
	Singleton() {
		cout << "Singleton()" << endl;
	}

	//������
	Singleton(const Singleton& s);

	static Singleton _instance;
	
};
Singleton Singleton::_instance;

int main() {
	Singleton* ps = Singleton::getInstance();
	Singleton* ps1 = Singleton::getInstance();
	Singleton* ps2 = Singleton::getInstance();
	Singleton* ps3 = Singleton::getInstance();
	/*Singleton copy(*ps2);
	Singleton s;*/
	return 0;
}

/*���������������ڶ��̸߲߳���������Ƶ��ʹ�ã�����Ҫ��ϸߣ�
��ô��Ȼʹ�ö���ģʽ��������Դ�����������Ӧ�ٶȸ��á�*/
#endif