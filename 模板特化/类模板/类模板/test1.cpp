#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

#if 0
namespace rose {
	//静态的顺序表
	template<class T, size_t N>
	class array {
	public:
		array() : _size(0) {
			//不能改变N
			//N = 10;
		}

		T& operator[] (size_t index) {
			assert(index < _size);
			return _array[index];
		}

		const T& operator[] (size_t index) const {
			assert(index < _size);
			return _array[index];
		}
	private:
		T _array[N];
		size_t _size;
	};
	
}

int main() {
	rose::array<int, 10> arr;

	/*
	//非类型的模板参数，编译器在编译期间必须把值确定下来
	int a = 10;
	int b = 10;
	rose::array<int, a + b> arr1;	//a+b编译期间无法确定，类模板中的静态数组没有办法创建
	*/

	return 0;
}
#endif


#if 0
//Max函数模板对于大部分类型都可以处理，但是处理不了char* （字符串的比较规则）
//Max函数模板必须对char* 进行特殊处理--特化
template<class T>
T& Max(T& left, T& right) {
	return left > right ? left : right;
}

//1.必须有函数模板 2.特化成什么类型
template<>
const char*& Max<const char*>(const char*& left, const char*& right) {
	if (strcmp(left, right) > 0)
		return left;
	else
		return right;
}

//最简单的方式--将无法处理类型的普通函数直接给出
char* Max(char* left, char* right) {
	if (strcmp(left, right) > 0)
		return left;
	else
		return right;
}

//类模板全特化
template<class T1, class T2>
class Data {
public:
	Data() { 
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//Data类模板的特化
template<>
class Data<int, char> {
	public:
	Data() { 
		cout << "Data<T1, T2>" << endl;
	}
private:
	int _d1;
	char _d2;

};

int main() {
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;

	const char* ps1 = "world";
	const char* ps2 = "hello";

	cout << Max(ps1, ps2) << endl;

	return 0;
}
#endif

#if 0
//偏特化：1.部分特化	2.对模板参数进一步的条件限制
template<class T1, class T2>
class Data {
public:
	Data() {
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//Data类模板的部分特化
//在实例化Data类模板时，只要第二个类型使用int，最后都会使用部分特化
template<class T1>
class Data<T1, int> {
public:
	Data() {
		cout << "Data<T1, int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};

//对模板参数进行更近一步的条件限制
//如果类模板两个参数按照指针的方式进行实例化，都会执行以下特化版本
template<class T1, class T2>
class Data<T1*, T2*> {
public:
	Data() {
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;

};

int main() {
	//d1,d2都是特化版本
	Data<int, int> d1;
	Data<double, int> d2;
	Data<int, double> d3;

	Data<int*, char* > d4;

	return 0;
}
#endif
