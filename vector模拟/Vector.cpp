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
		//����
		if (_finish == _eos) {
			//���ݵĸ������������Ϊ0��������Ϊ1�����������Ϊ0��������Ϊԭ���Ķ���
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
			//���µĿռ�
			T* tmp = new T[n];

			//����	��memcpy������������û���⣬Ч�ʸ�
			//memcpy(tmp, _start, sizeof(T) * Size());	string�ཫ����һ��ǳ�������õ���string�ĸ�ֵ���أ������������
			//���
			for (int i = 0; i < sz; ++i) {
				tmp[i] = _start[i];	//��ֵ���������
			}
			//��������������ȡ���ж�����������ʹ��memcpy���Զ�������ʹ�����

			//�ͷ�ԭ�еĿռ�
			delete[] _start;

			//ԭ�пռ䱻�ͷţ���������ָ�붼��Ҫ���¡�����
			_start = tmp;
			//_finish = _start + Size();	ԭ��ָ��ı䣬����ʹ��Size()���������ȱ���size
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

	/*	�ô�����������ھ������ݺ󣬵�����ʧЧ�ˡ�����
	//���ݺ�posλ�þͲ�����������ڴ�֮����
	void Insert(iterator pos, const T& val) {
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos) {
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reseve(newC);
		}

		//Ԫ���ƶ�
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
		int len = pos - _start;		//��¼pos����start��λ��
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos) {
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}

		//���ݺ󣬸���pos ��λ��
		pos = _start + len;
		//Ԫ���ƶ�
		iterator end = _finish;
		while (end > pos) {
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}

	//������ʧЧ
	iterator Erase(iterator pos) {
		assert(pos >= begin() && pos < end());
		iterator begin = pos;
		//Ԫ�ص��ƶ�
		while (begin < _finish) {
			*(begin - 1) = *begin;
			++begin;
		}
		
		--_finish;
		//���ر�ɾ��Ԫ�ص���һ��λ��
		return pos;
	}

	//ȱʡ������Ĭ���޲ι��������
	void Resize(size_t n, const T& val = T()) {
		if (n <= Size()) {
			_finish = _start + n;
		} else {
			if (n > Capacity()) {
				Reserve(n);
			}
			//��ֵ��[_finish , _start + n)
			while (_finish != _start + n) {
				*_finish = val;
				++_finish;
			}
		}
	}

	//���븴��
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

	//��д����ֵ����
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
	iterator _eos;	//���Ŀռ�����һ������һ��

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
	v.Resize(6);	//��ֵ 0
	cout << v.Capacity() << endl;
	v.Resize(10, 10); //�������ٸ�ֵ
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