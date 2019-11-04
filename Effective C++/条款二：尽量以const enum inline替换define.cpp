//宁可以编译器替换预处理器

#include<iostream>
using namespace std;

//该名称从未被编译器看见，也许在编译器开始处理源代码之前它就被处理器移走了
#define ASPECT_RATIO 1.653
const double AspectRatio = 1.653;

//定义常量指针
//第一个const不能修改指针所指内容，第二个const不能改变指针指向 
const char* const authorName = "Rose";
//string对象通常比前辈char*-based合宜
const string AuthorName("Rose");

//class专属常量。※※※为了将常量的作用域(scope)限制于class内，必须让它成为class的一个成员
//确保此常量只有一份实体，必须让它成为一个static成员
class GamePlayer {
private:
public:
	static const int NumTurns = 5;	//声明常量
	int scores[NumTurns];			//使用该常量
};
//C++要求使用的任何东西提供定义是，但它是个class专属常量有事static且为整数类(int,char,bool),则需特殊处理
//只要不取它们的地址，可以声明并使用它们无需提供定义式
//取某个专属常量的地址，或你的编译器却坚持要看到一个定义式，必须提供一个定义式
//const int GamePlayer::NumTurns;

//旧式编译器可能不支持static成员获得初值，可以将初值放到定义式
class A {
public:
	static const int a;
};
const int A::a = 100;

//无法使用#define创建一个class专属常量，以为#define不重视作用域(scope)

//当你在编译期间需要一个class常量值，比如上面的数组大小，万一你的编译器不允许static整数常量初值设定
//可改用"the enum hack"补偿做法：一个属于枚举类型的数值可权充ints被使用
class B {
private:
	enum { NumTurns = 10 };
	int scores[NumTurns];
};
//取enum的地址不合法，如果不想让别人获得一个pointer或reference指向你的某个整数常量，enum可以实现这个约束

void f(int a) {
	cout << a << endl;
}
//必须记住为宏中的所有实参加上小括号，否则可能遭遇麻烦（见main函数）
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

//template inline 可以获得宏带来的效率以及一般函数的所有可预料行为和类型安全性
template<typename T>
inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}


int main() {
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);			//a被累加两次
	CALL_WITH_MAX(++a, b + 10);		//a被累加一次
	GamePlayer g;
	cout << g.NumTurns << endl;	//5
	A aa;
	cout << aa.a << endl;

	return 0;
}