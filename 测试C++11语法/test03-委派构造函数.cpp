#if 0
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*================================================
 * description���������캯��֮��ʵ�ָ��ã�����һ�������Ĺ�������޲ι��죬���������Ĺ������һ�������Ĺ���
				���캯������ͬʱί�ɣ���ʹ�ó�ʼ���б�Ҳ����ί�ɵ��б�ֻ��һ�������Ĺ��캯������Ҫѭ������
=================================================*/
class B {
public:
	B()	:_a(1), _b(2), _c(3) {}

	B(int a) : B() {
		_a = a;
	}

	B(int a, int b) : B(a) {
		_b = b;
	}

	B& operator=(const B& b) = delete;

private:
	int _a;
	int _b;
	int _c;
};
/*�Ⱥ���������ر�ɾ��������ʵ��
B& B::operator=(const B& b) {
	return B();
}
*/

void test1() {
	B b;
	B b2(10);
	B b3(10, 20);
	//b = b2;
}

/*================================================
 * description��Ĭ�Ϻ�������	����Ĳ���ɾ���˶Ը�ֵ���صĺ���
 ��Ҫʱ��Ҫ���岻�������İ汾��ʵ�����޲εĶ��󣬶���ʱ�����������ɣ���ʱ�ֲ����ɣ�������ɻ��ң�����C++11�ó���Ա���Կ����Ƿ���Ҫ���������ɡ�
 ʹ��=default��ʽȱʡ����
=================================================*/
class C {
public:
	C(int c) :_c(c) {}

	C() = default;  //��ʾָ������һ���޲�Ĭ�Ϲ��캯��

	//�������������������⸳Ϊdefault
	C(const C& cc);

	C& operator=(const C& c) {
		cout << "C& operator=" << endl;
		return *this;
	}
private:
	int _c;
};
C::C(const C& cc) = default;

void test2() {
	C c;
	C d = c;
}

int main() {
	test1();
	test2();

	return 0;
}
#endif
