#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

/*
����ģʽ�������һ��ʹ�õ�ʱ�򴴽�
�������������ʮ�ֺ�ʱ����ռ�úܶ���Դ��������ز������ ��ʼ���������Ӱ�����ȡ�ļ����ȵȣ�
���п��ܸö����������ʱ�����õ�����ôҲҪ�ڳ���һ��ʼ�ͽ��г�ʼ����
�ͻᵼ�³�������ʱ�ǳ��Ļ����� �����������ʹ������ģʽ���ӳټ��أ�����
1. ���캯��˽��
2. ������
3. �ṩ���е�static�ӿڣ��ӿڵ�һ�ε���ʱ��������
4. ����һ��static��ָ��
5���̰߳�ȫ��˫���
*/


class Singleton {
public:

	static Singleton* getInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		//˫���
		//�ⲿ��飺���Ч��
		if (_pInstance == nullptr) {
			_mtx.lock();
			//�ڲ���飺��֤�̰߳�ȫ
			if (_pInstance == nullptr) {

				cout << "create obj" << endl;
				_pInstance = new Singleton;

			}
			_mtx.unlock();
		}
		return _pInstance;
	}
	//�����ݹ����
	//~Singleton()
	//{
	//	if (_pInstance)
	//	{
	//		delete _pInstance; // delete������+�ͷ�
	//		_pInstance = nullptr;
	//	}
	//}

	// ʵ��һ����Ƕ����������
	//�����ڲ�����п��ޣ�ȫ�������������ڽ����ռ���Զ�����ϵͳ���������ֻ���ڷ���ϵͳ֮ǰ��ǰ�ͷ�
	class Garba {
	public:
		~Garba() {
			if (_pInstance) {
				delete _pInstance;
				_pInstance = nullptr;
			}
		}
	};

private:
	Singleton() {
		cout << "Singleton()" << endl;
	}
	//������
	Singleton(const Singleton* s);



	static Singleton* _pInstance;	// ��������ָ��
	static mutex _mtx;		//������
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static Garba _gc;
};

Singleton* Singleton::_pInstance = nullptr;
mutex Singleton::_mtx;
Singleton::Garba Singleton::_gc;

void fun(int n) {
	for (int i = 0; i < n; ++i) {
		Singleton* ps = Singleton::getInstance();
	}
}


int main() {
	/*Singleton* ps = Singleton::getInstance();
	Singleton* ps1 = Singleton::getInstance();
	Singleton* ps2 = Singleton::getInstance();
	Singleton* ps3 = Singleton::getInstance();*/

	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);
	thread t3(fun, n);
	thread t4(fun, n);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	/*fun(n);
	fun(n);*/
	return 0;
}
