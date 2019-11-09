#if 0
#include<iostream>
#include<vector>
using namespace std;

class Widget{};
//以下两种参数一样
void f1(const Widget* pw) {}
void f2(Widget const *pw) {}

int main() {
#if 0
	char greeting[] = "Hello";
	char* p = greeting;
	//*左边的const表示指针所指物是常量
	//*右边的const表示指针自身是常量
	const char* cptr = greeting;	//不能改变指针指向的内容
	char* const ptrc = greeting;	//不能改变指针的指向
	const char* const cptrc = greeting;	//既不能改变指向也不能改变内容
	cout << p << endl;
	cout << cptr << endl;
	cout << ptrc << endl;
	cout << cptrc << endl;
#endif

	vector<int> v{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	//迭代器的作用就像个T*指针，声明迭代器为const就像声明指针为const一样（T* const 指针）
	const vector<int>::iterator iv = v.begin();
	cout << *iv << endl;

	//如果希望迭代器所指的东西不可改动: const_iterator
	vector<int>::const_iterator civ = v.begin();
	while (civ != v.end()) {
		cout << *civ << " ";
		++civ;
	}
	
	
	return 0;
}
#endif


//const成员函数

//const成员函数两个流行概念：
//bitwise constness:不可以更改对象内任何non-static成员变量
				//但是有不十足具备const性质却能通过bitwise测试
				//当指针为成员变量时，指针指向没有变，但是指针所指内容改变
//logical constness:
#include<iostream>
using namespace std;

#if 0
class CTextBlock {
public:
	CTextBlock(const char* s = "") : pText(new char[strlen(s) + 1]) {
		strcpy(pText, s);
	}

	char& operator[](size_t position) const {	//const成员函数
		pText[position] = 'Z';		//虽然没有修改指针的指向，但是也改变了指针的内容
		return pText[position];
	}

	friend ostream& operator<<(ostream& os, const CTextBlock& c);

private:
	char* pText;
};

ostream& operator<<(ostream& os, const CTextBlock& c) {
	os << c.pText;
	return os;
}

int main() {
	CTextBlock c("hello");
	cout << c << endl;
#if 0
	char* pc = &c[1];
	cout << c << endl;
	*pc = 'E';
	cout << c << endl;
#endif

#if 1
	cout << c[3] << endl;
	cout << c << endl;
#endif
	return 0;
 }
#endif

#if 0
class CTextBlock {
public :
	size_t length() const;
private:
	char* pText;
	mutable size_t textLength;		//C++的const相关的摆动场：mutable（可变的）。mutable释放掉non-staitic成员变量的bitwise constness约束
	mutable bool lengthIsValid;
};

size_t CTextBlock::length() const {
	if (!lengthIsValid) {
		textLength = std::strlen(pText);	//const成员函数修改mutable成员
		lengthIsValid = true;
	}
	return textLength;
}

int main() {

	return 0;
}
#endif

//在const和non-const成员函数中避免重复
#if 0
class TextBlock {
public:
	const char& operator[](std::size_t position) const {
		//边界检验
		if (position > text.size() - 1) {

		}
		//志记标记访问
		//检验数据完整性
		return text[position];
	}
	const char& operator[](std::size_t position) const {
		//边界检验
		if (position > text.size() - 1) {

		}
		//志记标记访问
		//检验数据完整性
		return text[position];
	}

private:
	std::string text;
};
#endif
//上述代码重复以及伴随编译时间、维护、代码膨胀等问题
//operator机能一次并使用它两次，必须其中一个调用另一个，这促使我们将常量性移除

//转型（casting）是一个糟糕的想法，但是本例中const operator[]完全做掉了non-const版本该做的一切，唯一不同是返回类型多了一个const修饰
//所以令non-const operator[]调用其const兄弟是一个避免代码重复的安全做法
class TextBlock {
public:
	const char& operator[](std::size_t position) const {
		return text[position];
	}
	char& operator[](std::size_t position) {
		return
			const_cast<char&>(		//将operator[]返回值的const移除
				static_cast<const TextBlock&>(*this)[position]	//为*this加上const，调用const operator[]
				);
	//这个代码两个转型，为了避免一直调用自己递归，必须明确指出调用const operator[],所以将*this从原始类型TextBlock&转型为const TextBlock&
	//第一次为*this加const
	//第二次从const operator[]的返回值中移除const
	}

private:
	std::string text;
}; 

//添加const的那一次转型强迫进行了一次安全转型（将non-const对象转为const对象），所以使用static_cast
//移除的const的那个动作只可以借由const_cast完成，没有其他选择：一个C-style转型也行得通