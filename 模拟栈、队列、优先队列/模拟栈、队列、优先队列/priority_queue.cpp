#include <iostream>
#include <vector>
using namespace std;

/*
push()		---> push_back,向上调整
pop()		---> pop_back, 向下调整
top()		---> front
要支持随机访问，因为有元素的交换，所以list不可以实现
*/

//默认实现大堆
#if 0
template<class T, class Container>
class Priority_Queue {
public:
	void push(const T& val) {
		_con.push_back(val);
		//向上调整
		shiftUp(_con.size() - 1);
	}

	void pop() {
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		//向下调整
		shiftDown(0);
	}

	T& top() {
		return _con.front();
	}

	size_t size() {
		return _con.size();
	}

	bool empty() {
		return _con.empty();
	}

private:
	Container _con;

	void shiftUp(size_t child) {
		size_t parent = (child - 1) >> 1;	//父亲结点为 （该结点-1）/2
		while (child > 0) {
			if (_con[child] > _con[parent]) {
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			} else {
				break;
			}
		}
	}

	void shiftDown(size_t parent) {
		size_t child = 2 * parent + 1;
		while (child < _con.size()) {
			if (child + 1 < _con.size() && _con[child + 1] > _con[child]) {
				++child;
			}
			if (_con[child] > _con[parent]) {
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			} else {
				break;
			}
		}
	}
};
#endif

//仿函数类：重载"()" 运算符的一个类
template <class T>
struct Greater {
	bool operator()(const T& a, const T& b) {
		return a > b;
	}
};

template <class T>
struct Less {
	bool operator()(const T& a, const T& b) {
		return a < b;
	}
};

void testFun() {
	Greater<int> g;
	int a = 1;
	int b = 2;
	bool ret = g.operator()(a, b);
	//上下两者等价
	ret = g(a, b);
}

//使用仿函数,自定义优先级，不需要修改代码，增加代码的灵活性
template<class T, class Container, class Compare>
class Priority_Queue {
public:
	void push(const T& val) {
		_con.push_back(val);
		//向上调整
		shiftUp(_con.size() - 1);
	}

	void pop() {
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		//向下调整
		shiftDown(0);
	}

	T& top() {
		return _con.front();
	}

	size_t size() {
		return _con.size();
	}

	bool empty() {
		return _con.empty();
	}

private:
	Container _con;
	Compare _com;

	void shiftUp(size_t child) {
		size_t parent = (child - 1) >> 1;	//父亲结点为 （该结点-1）/2
		while (child > 0) {
			//if (_con[child] > _con[parent]) {
			if (_com(_con[child], _con[parent])) {
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			} else {
				break;
			}
		}
	}

	void shiftDown(size_t parent) {
		size_t child = 2 * parent + 1;
		while (child < _con.size()) {
			//if (child + 1 < _con.size() && _con[child + 1] > _con[child]) {
			if (child + 1 < _con.size() && _com(_con[child + 1], _con[child])) {
				++child;
			}
			//if (_con[child] > _con[parent]) {
			if (_com(_con[child], _con[parent])) {
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else {
				break;
			}
		}
	}
};

void testPriorityQueue() {
	Priority_Queue<int, vector<int>, Greater<int>> pq;
	pq.push(1);
	pq.push(100);
	pq.push(1000);
	pq.push(500);
	pq.push(300);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}

int main() {
	testPriorityQueue();

	return 0;
}