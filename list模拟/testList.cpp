#include<iostream>
#include "List.h"
using namespace std;

struct Date {
	int _year = 2020;
	int _month = 1;
	int _day = 1;
};

void TestList1() {
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);

	//µü´úÆ÷ pNode
	List<int>::iterator lit = lst.begin();
	while (lit != lst.end()) {
		cout << *lit << " ";
		//++lit;
		lit++;
	}
	cout << endl;


}

void TestList2() {
	List<Date> lst;
	lst.PushBack(Date());
	lst.PushBack(Date());
	List<Date>::iterator lit = lst.begin();
	while (lit != lst.end()) {
		cout << (*lit)._year << " " << (*lit)._month << " " << endl;
		cout << lit->_year << " " << lit->_month << " " << endl;
		cout << lit.operator->()->_year << " " << lit.operator->()->_month << " " << endl;
		++lit;
	}
}

template <class T>
void PrintList(const List<T>& lst) {
	typename List<T>::const_iterator it = lst.begin();
	while (it != lst.end()) {
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template <class T>
void PrintListFor(const List<T>& lst) {
	for (const auto& e : lst) {
		cout << e << " ";
	}
	cout << endl;
}

void PrintList2(const List<Date>& lst) {
	List<Date>::const_iterator it = lst.begin();
	while (it != lst.end()) {
		//*it = 10;
		//it->_year = 2019;
		cout << it->_year << " ";
		++it;
	}
	cout << endl;
}


void TestList3() {
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);

	//µü´úÆ÷ pNode
	List<int>::iterator lit = lst.begin();
	while (lit != lst.end()) {
		*lit = 5;
		cout << *lit << " ";
		//++lit;
		lit++;
	}
	cout << endl;

	PrintList(lst);

	PrintListFor(lst);

}

void TestList4() {
	List<Date> lst;
	lst.PushBack(Date());
	lst.PushBack(Date());
	PrintList2(lst);
}

void TestList5() {
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.PushFront(0);
	lst.PushFront(-1);
	lst.PushFront(-2);
	lst.PushFront(-3);
	PrintListFor(lst);
	/*lst.Erase(lst.begin());
	lst.Erase(--lst.end());
	PrintListFor(lst);
	lst.Erase(++lst.begin());
	PrintListFor(lst);
	auto it = lst.begin();
	cout << *it << endl;
	it = lst.Erase(it);
	cout << *it << endl;*/
	lst.PopBack();
	PrintListFor(lst);
	lst.PopFront();
	PrintListFor(lst);
	lst.Clear();
	PrintListFor(lst);
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	PrintListFor(lst);
	List<int> copy(lst);
	PrintListFor(copy);
	cout << lst.Size() << endl;

	List<int> lst3(lst.begin(), lst.end());

	PrintListFor(lst3);

	int arr[] = { 5, 6, 7, 8 };
	List<int> lst4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintListFor(lst4);
	string str("12345678");
	List<int> lst5(str.begin(), str.end());
	PrintListFor(lst5);
}

int main() {
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	TestList5();
	return 0;
}
