#include<iostream>
#include<cstring>
using namespace std;

//写一个通用的拷贝函数：任意类型都可以进行拷贝
#if 0
template<class T>
void Copy(T* dst, T* src, size_t size) {
#if 0
	//memcpy缺陷：浅拷贝
	//优点：效率高
	//memcpy内存泄漏，浅拷贝
	memcpy(dst, src, sizeof(T) * size);
#endif

	//优点：一定不会出错
	//缺陷：效率低
	for (size_t i = 0; i < size; ++i) {
		dst[i] = src[i];	//调用赋值运算符的重载
	}
}
#endif

/*因为内置类型的个数是确定的，可以将“所有内置类型”放在一个“集合”，
再在内置类型集合中“查找”其是否存在， 即 确定该类型 是否 “内置类型”*/

#if 1
//将两个优点结合
bool IsPODType(const string& type) {
	const string strTypes[] = { "char", "short", "int", "long", "long long", "float", "double" };
	for (auto e : strTypes) {
		if (e == type)
			return true;
	}
	return false;
}

template<class T>
void Copy(T* dst, T* src, size_t size) {
	//内置类型和自定义类型
	//T到底是内置类型还是自定义类型
	//typeid(T).name();	//"int" "class Date"
	if (IsPODType(typeid(T).name())) {
		memcpy(dst, src, sizeof(T) * size);
	} else {
		for (size_t i = 0; i < size; ++i) {
			dst[i] = src[i];
		}
	}
}
#endif

/*
通过typeid来确认所拷贝对象的实际类型，然后再在内置类型集合中“枚举”其是否出现过，
既可确认所拷贝元素的类型为内置类型或者自定义类型。
但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比较，效率比较低
可应用模板特化在编译器确定其类型，查阅“类型萃取”文件
*/
