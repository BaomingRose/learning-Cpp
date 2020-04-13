#if 0
#include <iostream>
#include <vector>
using namespace std;

/*================================================
 * description：通过decltype关键字通过推导表达式运行时得到类型，RTTI, 运行时推导还有向typeid,  dynamic_cast
=================================================*/
void test1() {
	double x = 3.9;
	//运行时推导y的类型为double 通过表达式得到结果 RTTI
	decltype(x + 3) y;
	//typeid是一个操作符，不是一个函数，类似于sizeof
	cout << typeid(y).name() << endl;
}

void test2() {
	decltype(test1) f;
	//推导函数类型
	cout << typeid(f).name() << endl;	//结果：void __cdecl(void)
	cout << typeid(f()).name() << endl;	//结果：void,是函数的返回值
}

/*================================================
 * description：
问题：	template<class T1, class T2>
		//返回类型不一定是T1  （int ，double）返回的是double，需要运行时识别类型
		T1 Add(const T1& left, const T2& right) {
			return left + right;
		}
=================================================*/
//解决如下，返回值类型追踪
template<class T1, class T2>
//返回类型不一定是T1  （int ，double）返回的是double，需要运行时识别类型
auto Add(const T1& left, const T2& right)->decltype(left + right){
	return left + right;
}

void test3() {
	int a = 5;
	double b = 3.9;
	cout << typeid(Add(a, b)).name() << endl;
}

/*================================================
 * description：结构体pt只是一个变量，没有类型名，要想拿到一个和pt相同类型的变量，可以使用decltype
=================================================*/
struct {
	int x;
	int y;
}pt;

void test4() {
	decltype(pt) p;
	cout << typeid(p).name() << endl;	//运行结果：struct <unnamed-type-p>
}
/*================================================
 * description：这个测试是和test2相同的知识，主要尝试测试vector::erase的函数类型
=================================================*/
void* GetMemory(size_t size) {
	return malloc(size);
}

void test5() {
	// 如果没有带参数，推导函数的类型
	cout << typeid(decltype(GetMemory)).name() << endl;		//void * __cdecl(unsigned int)

	// 如果带参数列表，推导的是函数返回值的类型,注意：此处只是推演，不会执行函数
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