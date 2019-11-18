#include <iostream>
#include <list>
using namespace std;

template<class T>
void printList(const list<T>& l) {
	for (const auto& e : l) {
		cout << e << " ";
	}
	cout << endl;
}

//反向迭代器，反向打印，反向迭代器仍然是++
template<class T>
void printListIterator(const list<T>& l) {
	auto lit = l.rbegin();
	while (lit != l.rend()) {
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}

struct str {
	char c;
	int a;
	int b;
	double d;
	float f;
	int* p;
};

class A {
public:
	A(int a, int b) : _a(a) {
		cout << "A(int a = 0)" << endl;
	}

	A(const A& aa) : _a(aa._a) {
		cout << "A(const A& aa)" << endl;
	}
private:
	int _a;
};

bool single_digit(const int& value) {
	return (value < 10);
}

//仿函数对象
struct is_odd {
	bool operator()(const int& value) {
		return (value % 2) == 1;
	}
};

int main() {
	list<int> l0;
	/*
	list<char> cl;
	list<long long> lll;
	list<double> dl;
	list<str> ls;
	*/
	list<int> l1(10, 8);
	int arr[] = { 1, 2, 3, 4, 5, 3 };
	list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	list<int> cpy(l2);

#if 0		//erase 删除迭代器		remove	删除指定元素
	l2.erase(l2.begin());
	printList(l2);
	l2.erase(l2.begin(), l2.end());
	printList(l2);

	cpy.remove(3);
	printList(cpy);
#endif
	
#if 1		//迭代器失效
	list<int>::iterator it = l2.begin();
	cout << *it << endl;
	l2.insert(it, 100);		//插入100后，迭代器的位置没有改变,没有失效，插入不会引起迭代器失效
	cout << *it << endl;
	printList(l2);

/*	l2.erase(it);
	cout << *it << endl;	//迭代器位置被释放，迭代器失效
	printList(l2);
	*/
	it = l2.erase(it);		//erase返回下一个元素的位置
	cout << *it << endl;
	printList(l2);
#endif


	/*
	l0.assign(10, 100);	//赋值  10个100
	l0.assign(arr, arr + 6);
	printList(l0);
	printListIterator(l0);
	printList(l1);
	printListIterator(l1);
	printList(l2);
	printListIterator(l2);
	printList(cpy);
	printListIterator(cpy);
	*/

	/*
	cout << l0.max_size() << endl << l1.max_size() << endl;		//357913941  357913941
	cout << cl.max_size() << endl;			//357913941
	cout << lll.max_size() << endl;			//268435455
	cout << dl.max_size() << endl;			//268435455
	cout << sizeof(str) << " " << ls.max_size() << endl;		//32	107374182
	*/

#if 0	//emplace_back 和push_back
	list<A> la;
	la.push_back(A(1, 2));		//调用构造，并拷贝传参
	//la.push_back(1, 2);
	la.emplace_back(A(3, 4));	//调用构造，并拷贝传参
	//可以调用类型的构造函数，直接创建结点对象，效率高，不发生拷贝
	la.emplace_back(5, 6);		//能够调用A的构造函数，并直接插入到链表中，不拷贝，而push_back不行 ※※※
#endif

#if 0   //remove_if
	int myints[] = { 15, 36, 7, 17, 20, 39, 4, 1 };
	list<int> mylist(myints, myints + 8);
	mylist.remove_if(single_digit);	//	15,36,17,20,39
	printList(mylist);

	mylist.assign(myints, myints + 8);
	mylist.remove_if(is_odd());		//36 20 4
	printList(mylist);
#endif

#if 0	//unique 去重 必须有序		merge 合并 也必须有序		spice 拼接
	list<int> lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(1);

	lst.sort();
	lst.unique();
	printList(lst);

	list<int> lst2;
	lst2.push_back(7);
	lst2.push_back(9);
	lst2.push_back(5);
	lst2.push_back(1);
	lst2.push_back(2);

	//lst.splice(lst.begin(), lst2, ++lst2.begin());	//把lst2的迭代器位置拼接到lst的begin位置
	//lst.splice(lst.begin(), lst2);		//拼接之后lst2为空，将lst2拼接到lst的开始位置
	lst.splice(lst.begin(), lst2, ++lst2.begin(), --lst2.end());	//lst2的区间拼接到lstbegin位置
	printList(lst);
	printList(lst2);
	

	lst2.sort();
	lst2.merge(lst);	//lst2 lst必须有序，lst为空，全部合并到lst2中
	printList(lst2);
	printList(lst);
#endif
	
	return 0;
}