#include<iostream>
using namespace std;

/*
只能在栈上创建对象的类
: 1. 构造函数私有化
  2. 提供一个公有的static接口创建对象
*/

class StackOnly {
public:
	static StackOnly CreateStackOnly() {
		return StackOnly();
	}
private:
	StackOnly() {
		cout << "StackOnly()" << endl;
	}
};

/*
只能在栈上创建对象的类
： 1. 只声明不实现 operator new函数
*/
class StackOnly2 {
private:
	void* operator new(size_t size) = delete;
};

int main() {
	StackOnly::CreateStackOnly();
	return 0;
}