#if 0
#include <iostream>
#include <vector>
using namespace std;

/*================================================
 * description��ͨ��decltype�ؼ���ͨ���Ƶ����ʽ����ʱ�õ����ͣ�RTTI, ����ʱ�Ƶ�������typeid,  dynamic_cast
=================================================*/
void test1() {
	double x = 3.9;
	//����ʱ�Ƶ�y������Ϊdouble ͨ�����ʽ�õ���� RTTI
	decltype(x + 3) y;
	//typeid��һ��������������һ��������������sizeof
	cout << typeid(y).name() << endl;
}

void test2() {
	decltype(test1) f;
	//�Ƶ���������
	cout << typeid(f).name() << endl;	//�����void __cdecl(void)
	cout << typeid(f()).name() << endl;	//�����void,�Ǻ����ķ���ֵ
}

/*================================================
 * description��
���⣺	template<class T1, class T2>
		//�������Ͳ�һ����T1  ��int ��double�����ص���double����Ҫ����ʱʶ������
		T1 Add(const T1& left, const T2& right) {
			return left + right;
		}
=================================================*/
//������£�����ֵ����׷��
template<class T1, class T2>
//�������Ͳ�һ����T1  ��int ��double�����ص���double����Ҫ����ʱʶ������
auto Add(const T1& left, const T2& right)->decltype(left + right){
	return left + right;
}

void test3() {
	int a = 5;
	double b = 3.9;
	cout << typeid(Add(a, b)).name() << endl;
}

/*================================================
 * description���ṹ��ptֻ��һ��������û����������Ҫ���õ�һ����pt��ͬ���͵ı���������ʹ��decltype
=================================================*/
struct {
	int x;
	int y;
}pt;

void test4() {
	decltype(pt) p;
	cout << typeid(p).name() << endl;	//���н����struct <unnamed-type-p>
}
/*================================================
 * description����������Ǻ�test2��ͬ��֪ʶ����Ҫ���Բ���vector::erase�ĺ�������
=================================================*/
void* GetMemory(size_t size) {
	return malloc(size);
}

void test5() {
	// ���û�д��������Ƶ�����������
	cout << typeid(decltype(GetMemory)).name() << endl;		//void * __cdecl(unsigned int)

	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
	cout << typeid(decltype(GetMemory(0))).name() << endl;	//void *

	vector<int> v;
	vector<int>::iterator a;
	cout << typeid(decltype(v.erase(a))).name() << endl;	//class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
#endif