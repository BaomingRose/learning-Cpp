#include<iostream>
using namespace std;

#if 0
int main()
{
	const int a = 10;		//
	int * pa = (int*)&a;
	*pa = 100;

	cout << a << endl;		//10	����׶��Ѿ���10��a�滻
	cout << *pa << endl;	//100
	return 0;
}
#endif

