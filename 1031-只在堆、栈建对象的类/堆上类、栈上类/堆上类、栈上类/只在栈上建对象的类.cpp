#include<iostream>
using namespace std;

/*
ֻ����ջ�ϴ����������
: 1. ���캯��˽�л�
  2. �ṩһ�����е�static�ӿڴ�������
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
ֻ����ջ�ϴ����������
�� 1. ֻ������ʵ�� operator new����
*/
class StackOnly2 {
private:
	void* operator new(size_t size) = delete;
};

int main() {
	StackOnly::CreateStackOnly();
	return 0;
}