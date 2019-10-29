#include<iostream>
using namespace std;

//����͸�����ͬ������m_a, ���ظ���ĳ�Ա�����ͳ�Ա����
//����ָ�����ת��Ϊ����ָ�룬��֮����
//ֻҪ������ͬ�����أ������ǹ������ر��磺
//void TestBase::func(int i)�����Ǻ������func��������

//���ʸ��౻���س�Ա��ʽ��
/*
1.����������ָ��ת��Ϊ�����ָ��
2.������ ��������������Ա �ķ�ʽֱ�ӷ���
*/
class TestBase {
public:
	int m_a;
	TestBase(int i) : m_a(i) {

	}

	void func() {
		cout << "���Ǹ���ĺ���" << endl;
	}
};

class Test : public TestBase {
public:
	int m_a;
	//
	Test(int a, int b) : TestBase(a), m_a(b) {

	}

	void func() {
		cout << "��������ĺ���" << endl;
	}
};

int main() {
#if 0
	Test t(1, 2);
	//�����m_a������
	cout << t.m_a << endl;	//2
#endif

#if 0
	Test* pt = new Test(5, 6);	//����ָ��
	TestBase* ptb = pt;			//�������и������ָ��
	cout << pt->m_a << endl;	//6
	cout << ptb->m_a << endl;	//5
#endif

#if 0
	Test t(5, 6);
	//���෽��������
	t.func();

	Test* pt = new Test(5, 6);	
	TestBase* ptb = pt;		//��Ȼ�������и������ָ��
	pt->func();		//�������෽��
	ptb->func();	//���ø���
#endif


	return 0;
}

//���飺
/*
1.��Ҫ���������ж���������Աͬ���ĳ�Ա
2.�̳�һ��ֻ����public��ʽ
*/