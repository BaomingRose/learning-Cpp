#if 1
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
/*================================================
 * description�� C++�����ṩ�߳̿�ģ�����һ���̶߳��󣬾�������һ���߳�
			//����Ч�ʺܵ�
=================================================*/
mutex mtx;
int num = 0;

void fun1(int n) {
	for (int i = 0; i < n; ++i) {
		mtx.lock();
		++num;
		mtx.unlock();
	}
}

void testThread1() {
	//�����̣߳� ����һ���̶߳���
	int a = 10;
	cin >> a;
	thread t(fun1, a);
	thread t2(fun1, a);

	//�߳̽����� join�� detach
	t.join();  
	t2.join();
	cout << num << endl;

	//t.detach();
}

/*================================================
 * description��C++�ṩԭ�ӿ⣬�����кܶ������������
				Ч�ʱȼ����ߵĶ�
=================================================*/
#include <atomic>

atomic_int anum{ 0 };
void fun2(int n, int a, int b, int c) {
	for (int i = 0; i < n; ++i) {
		//mtx.lock();
		++anum;  //ԭ�����Լӣ� ���ᱻ���
		//mtx.unlock();
	}
}

void testThread2() {
	int a = 10;
	cin >> a;
	int b = 1;
	int c = 2;
	int d = 3;
	//�����ǿ��Ժܶ�ģ��Ǻ͵�һ������������Ӧ��
	thread t(fun2, a, b, c, d);
	thread t2(fun2, a, b, c, d);

	t.join();
	t2.join();
	cout << anum << endl;
}

int main() {
	//testThread1();
	testThread2();

	return 0;
}
#endif
