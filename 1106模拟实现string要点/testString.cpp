#include "String.h"
#include <iostream>
#include <string>
using namespace std;

#if 0	//�޲ι���Ŀ�
int main() {
	String s;
	string s1;	//
	cout << (int*)s.c_str() << endl;	//����޲ι������ַ�ָ��ָ���	���Ϊ0	��string��ʵ�ֲ���
	cout << (int*)s1.c_str() << endl;	//string�޲ι���Ҳ��������ռ��
	
	return 0;
}
#endif

#if 0		//char* �ַ����Ĺ����	���ֻ�ǰ�ָ�븳����Ա������������ͷ�
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