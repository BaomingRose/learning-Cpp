#if 0
#include<iostream>
using namespace std;

//只能在堆上创建对象的类
// 1. 构造私有化
// 2. 提供一个公有的static接口创建对象
// 3. 防拷贝

class HeapOnly {
public:
	static HeapOnly* CreateHeapOnly() {
		return new HeapOnly;
	}
private:
	HeapOnly() {
		cout << "HeapOnly()" << endl;
	}

	//防拷贝： 只声明不实现
	//HeapOnly(const HeapOnly& h);
	//防拷贝：C++11 删除函数的声明
	HeapOnly(const HeapOnly& h) = delete;
};

int main() {
	HeapOnly::CreateHeapOnly();
	return 0;
}
#endif