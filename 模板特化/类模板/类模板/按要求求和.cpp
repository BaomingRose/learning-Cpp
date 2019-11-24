/*要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）*/

//编译时递归次数有限制

#include <iostream>
using namespace std;

template<size_t N>
struct Sum {
	enum e { RET = N + Sum<N - 1>::RET };
};

template<>
struct Sum<1> {
	enum e {RET = 1};
};

int main() {
	Sum<100> s;
	cout << s.RET << endl;

	return 0;
}