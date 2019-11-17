#pragma once
#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;

template<class T>
struct ListNode {
	T _data;
	struct ListNode* _prev;
	struct ListNode* _next;

	ListNode(const T& val = T()) : _prev(nullptr), _next(nullptr), _data(val) {}
};

#if 0
//List迭代器借助List的节点完成类似于指针的功能
template<class T>
struct ListIterator {
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T> Self;

	//成员变量
	pNode _node;

	ListIterator(pNode node) :_node(node) {}

	//解引用： 可读可写
	T& operator*() {
		return _node->_data;
	}

	// ptr->_year; 可以可写
	T* operator->() {
		return &operator*();
		//return &_node->_data;
	}
	
	//迭代器前置++
	Self& operator++() {
		_node = _node->_next;
		return *this;
	}
	
	Self operator++(int) {
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	
	Self& operator--() {
		_node = _node->_prev;
		return *this;
	}
	
	Self operator--(int) {
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	
	//!= 
	bool operator!=(const Self& it) {
		return _node != it._node;
	}
	
	bool operator==(const Self& it) {
		return _node == it._node;
		//return !*this != it;
	}
};

template <class T>
struct ListConstIterator {
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListConstIterator<T> Self;

	pNode _node;

	ListConstIterator(pNode node)
		:_node(node)
	{}

	//解引用： 只读
	const T& operator*() {
		return _node->_data;
	}

	// ptr->_year; 只读
	const T* operator->() {
		return &operator*();
		//return &_node->_data;
	}

	//迭代器前置++
	Self& operator++() {
		_node = _node->_next;
		return *this;
	}

	Self operator++(int) {
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--() {
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int) {
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it) {
		return _node != it._node;
	}

	bool operator==(const Self& it) {
		return _node == it._node;
		//return !*this != it;
	}
};
#endif

template <class T, class Ref, class Ptr>
struct ListIterator {
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;

	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	//解引用： 可读可写
	Ref operator*() {
		return _node->_data;
	}
	// ptr->_year; 可以可写
	Ptr operator->() {
		return &operator*();
		//return &_node->_data;
	}

	//迭代器前置++
	Self& operator++() {
		_node = _node->_next;
		return *this;
	}

	Self operator++(int) {
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--() {
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int) {
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it) {
		return _node != it._node;
	}

	bool operator==(const Self& it) {
		return _node == it._node;
		//return !*this != it;
	}
};

template <class T>
class List {
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	List() {
		CreatHead();
	}

	void CreatHead() {
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;
	}

	void PushBack(const T& value) {
		/*pNode newNode = new Node(value);
		pNode tail = _head->_prev;

		tail->_next = newNode;
		newNode->_prev = tail;
		newNode->_next = _head;
		_head->_prev = newNode;*/
		Insert(end(), value);
	}

	iterator begin() {
		return iterator(_head->_next);
	}

	iterator end() {
		/*iterator it(head);
		return it;*/
		return iterator(_head);
	}

	const_iterator begin() const {
		return const_iterator(_head->_next);
	}

	const_iterator end() const {
		return const_iterator(_head);
	}

	void PushFront(const T& value) {
		Insert(begin(), value);
	}

	void PopBack() {
		Erase(--end());
	}

	void PopFront() {
		Erase(begin());
	}

	void Insert(iterator pos, const T& value) {
		//pos-> node
		//prev -->  node -> next
		pNode cur = pos._node;
		pNode newNode = new Node(value);
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator Erase(iterator pos) {
		//头节点不能删
		if (pos != end()) {
			//prev  --> curNode --> next
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			cur = nullptr;
			prev->_next = next;
			next->_prev = prev;
			//更新迭代器，指向下一个元素的位置，防止迭代器失效
			pos = iterator(next);
		}
		return pos;
	}

	void Clear() {
		if (!Empty()) {
			/*pNode cur = _head->_next;
			while (cur != _head)
			{
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}

			_head->_next = _head;
			_head->_prev = _head;*/

			iterator it = begin();
			while (it != end()) {
				it = Erase(it);
			}
		}
	}

	template <class InputIterator>
	List(InputIterator first, InputIterator last) {
		CreatHead();
		while (first != last) {
			PushBack(*first);
			++first;
		}
	}

	//深拷贝
	List(const List<T>& lst) {
		CreatHead();
		for (const auto& e : lst) {
			PushBack(e);
		}
	}

	List<T>& operator=(List<T> lst) {
		swap(_head, lst._head);
		return *this;
	}

	bool Empty() {
		return _head == _head->_next;
	}

	size_t Size() {
		size_t sz = 0;
		for (const auto& e : *this)
			++sz;
		return sz;
	}

	~List() {
		Clear();
		if (_head) {
			delete _head;
			_head = nullptr;
		}
	}
private:
	pNode _head;
};
