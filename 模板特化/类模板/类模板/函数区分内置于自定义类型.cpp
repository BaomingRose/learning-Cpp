#include<iostream>
#include<cstring>
using namespace std;

//дһ��ͨ�õĿ����������������Ͷ����Խ��п���
#if 0
template<class T>
void Copy(T* dst, T* src, size_t size) {
#if 0
	//memcpyȱ�ݣ�ǳ����
	//�ŵ㣺Ч�ʸ�
	//memcpy�ڴ�й©��ǳ����
	memcpy(dst, src, sizeof(T) * size);
#endif

	//�ŵ㣺һ���������
	//ȱ�ݣ�Ч�ʵ�
	for (size_t i = 0; i < size; ++i) {
		dst[i] = src[i];	//���ø�ֵ�����������
	}
}
#endif

/*��Ϊ�������͵ĸ�����ȷ���ģ����Խ��������������͡�����һ�������ϡ���
�����������ͼ����С����ҡ����Ƿ���ڣ� �� ȷ�������� �Ƿ� ���������͡�*/

#if 1
//�������ŵ���
bool IsPODType(const string& type) {
	const string strTypes[] = { "char", "short", "int", "long", "long long", "float", "double" };
	for (auto e : strTypes) {
		if (e == type)
			return true;
	}
	return false;
}

template<class T>
void Copy(T* dst, T* src, size_t size) {
	//�������ͺ��Զ�������
	//T�������������ͻ����Զ�������
	//typeid(T).name();	//"int" "class Date"
	if (IsPODType(typeid(T).name())) {
		memcpy(dst, src, sizeof(T) * size);
	} else {
		for (size_t i = 0; i < size; ++i) {
			dst[i] = src[i];
		}
	}
}
#endif

/*
ͨ��typeid��ȷ�������������ʵ�����ͣ�Ȼ�������������ͼ����С�ö�١����Ƿ���ֹ���
�ȿ�ȷ��������Ԫ�ص�����Ϊ�������ͻ����Զ������͡�
��ȱ���ǣ�ö����Ҫ���������ͱ���һ�飬ÿ�αȽ϶����ַ����ıȽϣ�Ч�ʱȽϵ�
��Ӧ��ģ���ػ��ڱ�����ȷ�������ͣ����ġ�������ȡ���ļ�
*/
