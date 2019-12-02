#if 0
#include <iostream>
#include <deque>
using namespace std;

template<class T, class Container>
class Queue {
public:
	void push(const T& val) {
		con.push_back(val);
	}

	void pop() {
		con.pop_front();
	}

	T& front() {
		return _con.front();
	}

	T& back() {
		return _con.back();
	}

	bool empty() {
		return _con.empty();
	}

	size_t size() {
		return _con.size();
	}
private:
	Container<T> _con;
};

void testQueue() {
	Queue<int, deque<int>> q;
	q.push(1);
	q.push(2);
	q.pop();
	cout << q.front() << endl;
}

int main() {
	testQueue();

	return 0;
}
#endif