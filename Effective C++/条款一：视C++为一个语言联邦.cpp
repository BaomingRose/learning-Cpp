#if 0
/*把C++视为一个由相关语言组成的联邦而非单一语言
四个部分(次语言)：
1.C语言
2.Object-Oriented C++	//面向对象
3.Template C++			//模板
4.STL					//STL库
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