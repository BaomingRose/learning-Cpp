#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

/*
懒汉模式：对象第一次使用的时候创建
如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等等，
而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，
就会导致程序启动时非常的缓慢。 所以这种情况使用懒汉模式（延迟加载）更好
1. 构造函数私有
2. 防拷贝
3. 提供公有的static接口，接口第一次调用时创建对象
4. 定义一个static的指针
5：线程安全：双检查
*/


class Singleton {
public:

	static Singleton* getInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		//双检查
		//外部检查：提高效率
		if (_pInstance == nullptr) {
			_mtx.lock();
			//内部检查：保证线程安全
			if (_pInstance == nullptr) {

				cout << "create obj" << endl;
				_pInstance = new Singleton;

			}
			_mtx.unlock();
		}
		return _pInstance;
	}
	//析构递归调用
	//~Singleton()
	//{
	//	if (_pInstance)
	//	{
	//		delete _pInstance; // delete：析构+释放
	//		_pInstance = nullptr;
	//	}
	//}

	// 实现一个内嵌垃圾回收类
	//下面内部类可有可无：全局区的生命周期结束空间会自动返回系统，这个操作只是在返回系统之前提前释放
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
	//防拷贝
	Singleton(const Singleton* s);



	static Singleton* _pInstance;	// 单例对象指针
	static mutex _mtx;		//互斥锁
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
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
