#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

#if 0
namespace rose {
	//��̬��˳���
	template<class T, size_t N>
	class array {
	public:
		array() : _size(0) {
			//���ܸı�N
			//N = 10;
		}

		T& operator[] (size_t index) {
			assert(index < _size);
			return _array[index];
		}

		const T& operator[] (size_t index) const {
			assert(index < _size);
			return _array[index];
		}
	private:
		T _array[N];
		size_t _size;
	};
	
}

int main() {
	rose::array<int, 10> arr;

	/*
	//�����͵�ģ��������������ڱ����ڼ�����ֵȷ������
	int a = 10;
	int b = 10;
	rose::array<int, a + b> arr1;	//a+b�����ڼ��޷�ȷ������ģ���еľ�̬����û�а취����
	*/

	return 0;
}
#endif


#if 0
//Max����ģ����ڴ󲿷����Ͷ����Դ������Ǵ�����char* ���ַ����ıȽϹ���
//Max����ģ������char* �������⴦��--�ػ�
template<class T>
T& Max(T& left, T& right) {
	return left > right ? left : right;
}

//1.�����к���ģ�� 2.�ػ���ʲô����
template<>
const char*& Max<const char*>(const char*& left, const char*& right) {
	if (strcmp(left, right) > 0)
		return left;
	else
		return right;
}

//��򵥵ķ�ʽ--���޷��������͵���ͨ����ֱ�Ӹ���
char* Max(char* left, char* right) {
	if (strcmp(left, right) > 0)
		return left;
	else
		return right;
}

//��ģ��ȫ�ػ�
template<class T1, class T2>
class Data {
public:
	Data() { 
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//Data��ģ����ػ�
template<>
class Data<int, char> {
	public:
	Data() { 
		cout << "Data<T1, T2>" << endl;
	}
private:
	int _d1;
	char _d2;

};

int main() {
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;

	const char* ps1 = "world";
	const char* ps2 = "hello";

	cout << Max(ps1, ps2) << endl;

	return 0;
}
#endif

#if 0
//ƫ�ػ���1.�����ػ�	2.��ģ�������һ������������
template<class T1, class T2>
class Data {
public:
	Data() {
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//Data��ģ��Ĳ����ػ�
//��ʵ����Data��ģ��ʱ��ֻҪ�ڶ�������ʹ��int����󶼻�ʹ�ò����ػ�
template<class T1>
class Data<T1, int> {
public:
	Data() {
		cout << "Data<T1, int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};

//��ģ��������и���һ������������
//�����ģ��������������ָ��ķ�ʽ����ʵ����������ִ�������ػ��汾
template<class T1, class T2>
class Data<T1*, T2*> {
public:
	Data() {
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;

};

int main() {
	//d1,d2�����ػ��汾
	Data<int, int> d1;
	Data<double, int> d2;
	Data<int, double> d3;

	Data<int*, char* > d4;

	return 0;
}
#endif
