#include<iostream>
using namespace std;

#if 0
int main()
{
	const int a = 10;		//
	int * pa = (int*)&a;
	*pa = 100;

	cout << a << endl;		//10	±àÒë½×¶ÎÒÑ¾­ÓÃ10°ÑaÌæ»»
	cout << *pa << endl;	//100
	return 0;
}
#endif

