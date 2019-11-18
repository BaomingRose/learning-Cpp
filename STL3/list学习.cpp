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

//����������������ӡ�������������Ȼ��++
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

//�º�������
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

#if 0		//erase ɾ��������		remove	ɾ��ָ��Ԫ��
	l2.erase(l2.begin());
	printList(l2);
	l2.erase(l2.begin(), l2.end());
	printList(l2);

	cpy.remove(3);
	printList(cpy);
#endif
	
#if 1		//������ʧЧ
	list<int>::iterator it = l2.begin();
	cout << *it << endl;
	l2.insert(it, 100);		//����100�󣬵�������λ��û�иı�,û��ʧЧ�����벻�����������ʧЧ
	cout << *it << endl;
	printList(l2);

/*	l2.erase(it);
	cout << *it << endl;	//������λ�ñ��ͷţ�������ʧЧ
	printList(l2);
	*/
	it = l2.erase(it);		//erase������һ��Ԫ�ص�λ��
	cout << *it << endl;
	printList(l2);
#endif


	/*
	l0.assign(10, 100);	//��ֵ  10��100
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

#if 0	//emplace_back ��push_back
	list<A> la;
	la.push_back(A(1, 2));		//���ù��죬����������
	//la.push_back(1, 2);
	la.emplace_back(A(3, 4));	//���ù��죬����������
	//���Ե������͵Ĺ��캯����ֱ�Ӵ���������Ч�ʸߣ�����������
	la.emplace_back(5, 6);		//�ܹ�����A�Ĺ��캯������ֱ�Ӳ��뵽�����У�����������push_back���� ������
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

#if 0	//unique ȥ�� ��������		merge �ϲ� Ҳ��������		spice ƴ��
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

	//lst.splice(lst.begin(), lst2, ++lst2.begin());	//��lst2�ĵ�����λ��ƴ�ӵ�lst��beginλ��
	//lst.splice(lst.begin(), lst2);		//ƴ��֮��lst2Ϊ�գ���lst2ƴ�ӵ�lst�Ŀ�ʼλ��
	lst.splice(lst.begin(), lst2, ++lst2.begin(), --lst2.end());	//lst2������ƴ�ӵ�lstbeginλ��
	printList(lst);
	printList(lst2);
	

	lst2.sort();
	lst2.merge(lst);	//lst2 lst��������lstΪ�գ�ȫ���ϲ���lst2��
	printList(lst2);
	printList(lst);
#endif
	
	return 0;
}