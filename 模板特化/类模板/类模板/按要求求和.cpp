/*Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C��*/

//����ʱ�ݹ����������

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