#include <iostream>
#include <vector>
using namespace std;

/*
push()		---> push_back,���ϵ���
pop()		---> pop_back, ���µ���
top()		---> front
Ҫ֧��������ʣ���Ϊ��Ԫ�صĽ���������list������ʵ��
*/

//Ĭ��ʵ�ִ��
#if 0
template<class T, class Container>
class Priority_Queue {
public:
	void push(const T& val) {
		_con.push_back(val);
		//���ϵ���
		shiftUp(_con.size() - 1);
	}

	void pop() {
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		//���µ���
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
		size_t parent = (child - 1) >> 1;	//���׽��Ϊ ���ý��-1��/2
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

//�º����ࣺ����"()" �������һ����
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
	//�������ߵȼ�
	ret = g(a, b);
}

//ʹ�÷º���,�Զ������ȼ�������Ҫ�޸Ĵ��룬���Ӵ���������
template<class T, class Container, class Compare>
class Priority_Queue {
public:
	void push(const T& val) {
		_con.push_back(val);
		//���ϵ���
		shiftUp(_con.size() - 1);
	}

	void pop() {
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		//���µ���
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
		size_t parent = (child - 1) >> 1;	//���׽��Ϊ ���ý��-1��/2
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