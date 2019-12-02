#if 0
#include <iostream>
#include <deque>
#include <functional>
using namespace std;

template<class T, class Container>
class Stack {
public:
	void push(const T& val) {
		_con.push_back(val);
	}

	void pop() {
		_con.pop_back();
	}

	T& top() {
		return _con.back();
	}

	bool empty() {
		return _con.empty();
	}

	size_t size() {
		return _con.size();
	}
private:
	Container _con;
};

void testStack() {
	Stack<int, deque<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.top() << endl;
}

int main() {
	testStack();

	return 0;
}
#endif