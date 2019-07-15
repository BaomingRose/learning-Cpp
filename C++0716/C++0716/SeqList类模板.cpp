#if 1
#include<iostream>
using namespace std;
//实现一个通用的顺序表：任意类型都可以存放
//typedef double DataType;


/*模板的编译分为两个阶段：
1.实例化前--只对模板进行简单的语法检测
2.实例化后--编译器就会根据T的实际类型来生成代码
*/
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 3)
		: _array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	//拷贝构造 & 赋值运算符重载

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}

	void PushBack(const T& data);
	void PopBack()
	{
		if (!Empty())
			return;
		--_size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	//随机访问
	T& operator[](size_t index)
	{
		return _array[index];
	}

	T& Front()
	{
		return _array[0];
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;

};

template <typename T>
void SeqList<T>::PushBack(const T& data)
{
	//_CheckCapacity();
	_array[_size++] = data;

}


int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << array[5] << endl;


	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1[1] = 10;

	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;

	return 0;
}
#endif 