#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
using namespace std;
/*================================================
 * description：
简单理解：
	左值： 可以出现在赋值符号的两边
	右值： 只可以出现在赋值符号的右边
		1： 常量
		2： 将亡值： 生命周期马上要结束的值
=================================================*/
int fun() {
	int a = 10;
	return a;
}

void test1() {
	//fun() = 2;	//这个临时对象是不能赋值的，这就是将忘值
}

/*================================================
 * description：
	左值引用： 即可以引用左值，也可以引用右值(需要加const)
	右值引用&&： 只能引用右值		//为了提高效率
=================================================*/
void test2() {
	int a = 10;
	int& ra = a;
	const int& ra2 = 10;
	const int& f22 = fun();

	int&& rra = 10;
	int&& f2 = fun();
	//int&& rra2 = a;  //右值引用不能引用左值
}

/*================================================
 * description：实现string类的移动拷贝		（我觉得原逻辑并没有改变，只是判断是否将亡，如果将亡值，我就在拷贝的时候做手脚）
		当一个函数返回string类型的时候，那么这个对象是个将亡值，如果不使用右值引用的移动拷贝，那么将调用一次拷贝做返回值，然后析构掉
		如果使用右值引用，就调用移动拷贝，移动拷贝并创建空间拷贝了，而是将你的空间拿来用，把你置空，析构的时候别把空间释放了，直接把你的原空间返回
		
		如果是赋值，右值是临时对象，则相同的道理，不需要再拷贝临时对象，而是直接使用临时对象，以节省开销
=================================================*/
class String {
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1]) {
		strcpy(_str, str);
		cout << "String(char*)" << endl;
	}

	String(const String& s) : _str(new char[strlen(s._str) + 1]) {
		strcpy(_str, s._str);
		cout << "String (const String&)" << endl;
	}
	//移动构造
	String(String&& s)
		:_str(s._str) {	//直接抢夺资源，使用
		s._str = nullptr;
		cout << "String (String&&)" << endl;
	}
	
	String& operator=(const String& s) {
		if (this != &s) {
			if (_str)
				delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		cout << "operator=(const String&)" << endl;
		return *this;
	}
	//移动赋值
	String& operator=(String&& s) {
		if (this != &s) {
			char* tmp = _str;
			_str = s._str;
			s._str = tmp;
		}
		cout << "operator=(String&&)" << endl;

		return *this;
	}

	char* c_str() {
		return _str;
	}
	
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
		cout << "析构函数" << endl;
	}
private:
	char* _str;
};

String getString(const char* str) {
	String strOut(str);	//会调用构造
	return strOut;		//返回之前拷贝一份临时对象返回，如果采用右值引用直接使用，是一个将亡值
}

void test3() {
	const char* str = "123";
	String copy = getString(str);  //执行一次构造 + 2次拷贝构造 ---> 编译器优化--> 1次构造 + 1次拷贝构造
									//如果有移动构造，则调用移动构造
	cout << copy.c_str() << endl;
}

void test4() {
	String str("123");
	String str2("456");
	String str3("-10");
	str3 = str2;  // 赋值
	str2 = String("789");  // 构造 +  移动赋值 + 析构
	cout << str2.c_str() << endl;
}

/*================================================
 * description：移动语义, 唯一的功能就是将一个左值强制转化为右值引用，通过右值引用使用该值，实现移动语义
				下面的str被转成右值，但是并不会析构，毕竟还是个声明周期较长的变量，只是拿到的值是str2不再使用的值
=================================================*/
void test5() {
	String str("123");
	String str2("456");
	String str3("-10");
	cout << str.c_str() << endl;
	str3 = str2;  // 赋值
	//移动语义move: 错误使用场景， str本身为左值，且str在后面被继续访问
	// 只有完全确定左值在后面的代码中不会再被使用到，才可以把左值通过移动语义转成右值
	str2 = move(str);  // move: 改变str的属性： str-->右值，  移动赋值
	cout << str.c_str() << endl;
	str2 = String("789");  // 构造 +  移动赋值 + 析构
}

/*================================================
 * description： move的正确使用，在E的移动构造和移动赋值函数中，要想临时对象中的String对象移动赋值，就要使用move移动语义，才能实现真正的
				因为临时的对象中的String对象也是临时的也是不需要再用了，所以可以转换为右值，让String真正的调用移动构造和移动赋值函数
=================================================*/
class E {
public:
	E(const String& name, const String& id) : _name(name)), _id(id) {
		cout << "E(const String& name, const String& id)" << endl;
	}

	//移动构造中实现String 的移动构造
	E(E&& e) : _name(move(e._name)), _id(move(e._id)) {
		cout << "E(E&&)" << endl;
	}

	E(E& e) : _name(e._name), _id(e._id) {
		cout << "E(E& e)" << endl;
	}

	E& operator=(const E& e) {
		cout << "E& operator=(const E& e)" << endl;
		if (this != &e) {
			_name = e._name;
			_id = e._id;
		}
		
		return *this;
	}

	//移动赋值中实现String的移动赋值
	E& operator=(E&& e) {
		cout << "E& operator=(E&& e)" << endl;
		if (this != &e) {
			_name = move(e._name);
			_id = move(e._id);
		}
		
		return *this;
	}

private:
	String _name;
	String _id;
};

void test6() {
	E e("123", "46");
	E copy(e);
	E copy2 = E("999", "999");
	cout << "=" << endl;
	e = copy;
	copy2 = E("1000", "1000");
}

/*================================================
 * description：完美转发, 函数模板在向其他函数传递自身形参时，如果相应实参是左值，它就应该被转发为左值；如果相应实参是右值，它就应该被转发为右值。
=================================================*/
void Fun(int &x) { cout << "lvalue ref" << endl; }
void Fun(int &&x) { cout << "rvalue ref" << endl; }
void Fun(const int &x) { cout << "const lvalue ref" << endl; }
void Fun(const int &&x) { cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward0(T t) {
	Fun(t);
}
// 具体类型： 具体类型&&  右值引用
// 泛型： T&&  未定引用类型： 根据实例化的类型确定： 左值/右值引用
// 完美转发
template<typename T>
void PerfectForward(T &&t) {
	//C++11通过forward函数来实现完美转发
	Fun(std::forward<T>(t));
}

void test7() {
	PerfectForward(10); // rvalue ref

	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref

	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
}

int main() {
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
	test6();

	return 0;
}
#endif