#if 0
/*��C++��Ϊһ�������������ɵ�������ǵ�һ����
�ĸ�����(������)��
1.C����
2.Object-Oriented C++	//�������
3.Template C++			//ģ��
4.STL					//STL��
*/
#include<iostream>
#include<thread>
#include<vector>
using namespace std;

void fun(vector<int> v) {
	for (auto & iv : v) {
		cout << iv << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v{ 100, 200, 300, 400, 500, 600 };
	thread thread1(fun, v);
	thread thread2(fun, v);

	thread1.join();
	thread2.join();
	return 0;
}
#endif