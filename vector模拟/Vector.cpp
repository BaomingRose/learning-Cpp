#include<iostream>
#include<cstdlib>
#include<cassert>
#include<string.h>
using namespace std;

template<class T>
class Vector {
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector() : _start(nullptr), _finish(nullptr), _eos(nullptr) {

	}

	~Vector() {
		if (_start) {
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}

	void PushBack(const T& val) {
		//容量
		if (_finish == _eos) {
			//增容的个数，如果容量为0，容量变为1，如果容量不为0，容量变为原来的二倍
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}

		*_finish = val;
		++_finish;
	}

	size_t Capacity() const {
		return _eos - _start;
	}


	void Reserve(size_t n) {
		int sz = Size();
		if (n > Capacity()) {
			//开新的空间
			T* tmp = new T[n];

			//拷贝	，memcpy内置数据类型没问题，效率高
			//memcpy(tmp, _start, sizeof(T) * Size());	string类将会是一个浅拷贝，该调用string的赋值重载（深拷贝）※※※
			//深拷贝
			for (int i = 0; i < sz; ++i) {
				tmp[i] = _start[i];	//赋值运算符重载
			}
			//后续会有类型萃取，判断是内置类型使用memcpy，自定义类型使用深拷贝

			//释放原有的空间
			delete[] _start;

			//原有空间被释放，所以三个指针都需要更新※※※
			_start = tmp;
			//_finish = _start + Size();	原来指针改变，不能使用Size()函数，事先保存size
			_finish = _start + sz;
			_eos = _start + n;
		}
	}

	size_t Size() const {
		return _finish - _start;
	}

	const T& operator[](size_t pos) const {
		assert(pos < Size());
		return _start[pos];
	}
	T& operator[](size_t pos) {
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin() {
		return _start;
	}

	iterator end() {
		return _finish;
	}

	const_iterator begin() const {
		return _start;
	}

	const_iterator end() const {
		return _finish;
	}

	/*	该代码的问题所在就是扩容后，迭代器失效了※※※
	//扩容后，pos位置就不在新申请的内存之中了
	void Insert(iterator pos, const T& val) {
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos) {
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reseve(newC);
		}

		//元素移动
		iterator end = _finish;
		while (end > pos) {
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}
	*/

	void Insert(iterator pos, const T& val) {
		int len = pos - _start;		//记录pos距离start的位置
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos) {
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}

		//扩容后，更新pos 的位置
		pos = _start + len;
		//元素移动
		iterator end = _finish;
		while (end > pos) {
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}

	//迭代器失效
	iterator Erase(iterator pos) {
		assert(pos >= begin() && pos < end());
		iterator begin = pos;
		//元素的移动
		while (begin < _finish) {
			*(begin - 1) = *begin;
			++begin;
		}
		
		--_finish;
		//返回被删除元素的下一个位置
		return pos;
	}

	//缺省：调用默认无参构造※※※
	void Resize(size_t n, const T& val = T()) {
		if (n <= Size()) {
			_finish = _start + n;
		} else {
			if (n > Capacity()) {
				Reserve(n);
			}
			//赋值：[_finish , _start + n)
			while (_finish != _start + n) {
				*_finish = val;
				++_finish;
			}
		}
	}

	//代码复用
	void PopBack() {
		Erase(end() - 1);
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last) {
		while (first != last) {
			PushBack(*first);
			++first;
		}
	}

	Vector(const Vector<T>& vec) : _start(new T[vec.Size()]), _finish(_start + vec.Size()), _eos(_start + vec.Capacity()) {
		
		for (int i = 0; i < vec.Size(); ++i) {
			_start[i] = vec[i];
		}
	}

	//新写法赋值重载
	Vector<T>& operator=(Vector<T> vec) {
		Swap(vec);
		return *this;
	}

	void Swap(Vector<T>& vec) {
		swap(_start, vec._start);
		swap(_finish, vec._finish);
		swap(_eos, vec._eos);
	}

private:
	iterator _start;
	iterator _finish;
	iterator _eos;	//开的空间的最后一个的下一个

};

template<class T>
void Printvec(const Vector<T>& vec) {
	typename Vector<T>::const_iterator vit = vec.begin();
	while (vit != vec.end()) {
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
	/*for (int i = 0; i < vec.Size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
}

void testErase() {
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	Vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0)
			v.Erase(it);
		else
			++it;
	}
}

void TestResize() {
	/*Vector<Vector<int>> v;
	v.PushBack(Vector<int>());
	v.PushBack(Vector<int>());
	v.Resize(100);
	v.Resize(10);*/

	Vector<int> v;
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	cout << v.Capacity() << endl;
	v.Resize(6);	//赋值 0
	cout << v.Capacity() << endl;
	v.Resize(10, 10); //先增容再赋值
	Printvec(v);
	cout << v.Capacity() << endl;
	v.Resize(2);
	Printvec(v);
}

int main() {
	TestResize();
	testErase();
	Vector<int> v;
	cout << v.Capacity() << endl;
	v.PushBack(1);

	cout << v.Capacity() << endl;
	v.PushBack(2);
	cout << v.Capacity() << endl;
	v.PushBack(3);
	cout << v.Capacity() << endl;
	v.PushBack(4);
	cout << v.Capacity() << endl;
	v.Insert(v.begin(), 0);
	v.PushBack(5);
	cout << v.Capacity() << endl;
	Printvec(v);

	return 0;
}