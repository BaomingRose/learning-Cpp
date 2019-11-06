#include "String.h"
#include <iostream>
#include <string>
using namespace std;

#if 0	//无参构造的坑
int main() {
	String s;
	string s1;	//
	cout << (int*)s.c_str() << endl;	//如果无参构造让字符指针指向空	结果为0	和string的实现不符
	cout << (int*)s1.c_str() << endl;	//string无参构造也是有申请空间的
	
	return 0;
}
#endif

#if 0		//char* 字符串的构造坑	如果只是把指针赋给成员变量，会二次释放
int main() {
	char* str = new char[10];
	strcpy(str, "hello");
	String s3(str);
	delete[] str;
	return 0;
}
#endif

int main() {
	String s("heillo");

	return 0;
}