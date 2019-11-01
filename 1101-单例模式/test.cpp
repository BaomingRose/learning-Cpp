#if 0
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

void fun(int n) {
	for (int i = 0; i < n; ++i) {
		cout << i << endl;
	}
}

int main() {
	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);

	t1.join();
	t2.join();

	return 0;
}
#endif