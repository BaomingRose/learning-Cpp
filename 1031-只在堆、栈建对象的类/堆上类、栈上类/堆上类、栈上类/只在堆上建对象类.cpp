#if 0
#include<iostream>
using namespace std;

//ֻ���ڶ��ϴ����������
// 1. ����˽�л�
// 2. �ṩһ�����е�static�ӿڴ�������
// 3. ������

class HeapOnly {
public:
	static HeapOnly* CreateHeapOnly() {
		return new HeapOnly;
	}
private:
	HeapOnly() {
		cout << "HeapOnly()" << endl;
	}

	//�������� ֻ������ʵ��
	//HeapOnly(const HeapOnly& h);
	//��������C++11 ɾ������������
	HeapOnly(const HeapOnly& h) = delete;
};

int main() {
	HeapOnly::CreateHeapOnly();
	return 0;
}
#endif