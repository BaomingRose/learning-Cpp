#if 1
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
/*================================================
 * description： C++是有提供线程库的，创建一个线程对象，就是启动一个线程
			//加锁效率很低
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
	//启动线程： 创建一个线程对象
	int a = 10;
	cin >> a;
	thread t(fun1, a);
	thread t2(fun1, a);

	//线程结束： join， detach
	t.join();  
	t2.join();
	cout << num << endl;

	//t.detach();
}

/*================================================
 * description：C++提供原子库，里面有很多基本数据类型
				效率比加锁高的多
=================================================*/
#include <atomic>

atomic_int anum{ 0 };
void fun2(int n, int a, int b, int c) {
	for (int i = 0; i < n; ++i) {
		//mtx.lock();
		++anum;  //原子性自加： 不会被打断
		//mtx.unlock();
	}
}

void testThread2() {
	int a = 10;
	cin >> a;
	int b = 1;
	int c = 2;
	int d = 3;
	//参数是可以很多的，是和第一个参数个数对应的
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
