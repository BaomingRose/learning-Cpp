#include <iostream>
using namespace std;

/*��̬��Ա

��̬��Ա�����߲��������ߣ��������ڣ���һ���Ա�Ƕ����������ڡ�
���Ծ�̬��Ա����ͨ������ֱ�ӵ��ã�����ͨ��Ա����ͨ��������á�

��̬��ԱҲ��private��public��protected֮��
һ����̬��Ա����
1�����ж���������˭���ˣ����е�һ���
2���洢��ȫ��������ռ����Ŀռ䣬����ȡsizeof��ʱ��������
3������ֵֻ�������⣬��ֵʱ����static���á����� ����::������ = n�� ֱ�Ӹ�ֵ
������̬��Ա����
ֻ��ֱ�ӷ��ʾ�̬��Ա�������޷�������������ͨ��Ա����Ϊ��û��thisָ��
*/
class TestSt {
public:
	int a;
	static int m_s_i;

	TestSt() {
		m_s_i++;
	}

	static void testst() {
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;

int main() {
	/*	TestSt t1;
		cout << t1.m_s_i << endl;
		TestSt t2;
		cout << t1.m_s_i << endl;
		cout << t2.m_s_i << endl;
		TestSt t3;
		cout << t1.m_s_i << endl;
		cout << t2.m_s_i << endl;
		cout << t3.m_s_i << endl;
		*/
	TestSt::testst();
	cout << TestSt::m_s_i << endl;		//4
	return 0;
}