#if 0
#include <iostream>
using namespace std;

/*
��ֵ���������
operator=
��������أ�
����������ɺ����������ļ�Ŀ���ɲ�����ͨ������������ʶ�����Ӧ�Ĳ����������൱�ں������ء�
�����������ָ���Ĺ��򣬹��������������ƶ���
����Զ��ṩһ����ֵ�����������(4)��ִ�е���ǳ������������������ͬ

const��Ա����
const���ڳ�Ա������ĩβ��������������е�this��const���ε�
���һ��������const������ô�����ܵ��÷�const�ĳ�Ա����

ȡ��ַ���������
����Զ��ṩ����ȡ��ַ��������أ�һ���������ͨ�����(5)��һ�������const�����(6)
*/

class Testop {
public:
	int m_a;
	int m_b;

	Testop() :
		m_a(0),
		m_b(0)
	{}

	Testop(int a, int b) :
		m_a(a),
		m_b(b)
	{}

	void test1(int a, int b) {
		test2(2, 4);
	}

	void test2(int a, int b) const {
		//test1(2, 4);
	}

	Testop operator + (const Testop &s) const {
		Testop res;
		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;
		return res;
	}

	Testop & operator = (const Testop &s) {
		m_a = s.m_a;
		m_b = s.m_b;
		return *this;
	}
};

int main() {
	Testop a(3, 5);
	Testop b(2, 7);

	Testop c;
	const Testop d;
	c = c = a + b;

	cout << c.m_a << ' ' << c.m_b << endl;		//5 12
	return 0;
}
#endif