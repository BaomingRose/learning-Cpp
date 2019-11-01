#if 0
#include<iostream>
using namespace std;

/*
饿汉模式：
就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象。
   1. 构造函数私有化
   2. 提供一个static公有接口返回对象
   3. 定义一个static自身成员
   4. 防拷贝:拷贝构造只声明不实现
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

	//防拷贝
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

/*如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，
那么显然使用饿汉模式来避免资源竞争，提高响应速度更好。*/
#endif