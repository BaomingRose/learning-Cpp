#include<iostream>
using namespace std;
#include<vector>		//�ײ�ṹ---��̬˳���

#if 0

int main() {
	//���ֹ��췽ʽ
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2.begin(), v2.end());	//���乹��
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	vector<int> v5(v4);


	//���ֱ�����ʽ
	for (size_t i = 0; i < v2.size(); ++i) {
		cout << v2[i] << " ";
	}
	cout << endl;


	//���õ���������
	//vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v4)
		cout << e << " ";
	cout << endl;

	auto rit = v5.rbegin();
	while (rit != v5.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}
#endif

#if 0

int main() {
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}

#endif

#if 0
int main() {
	vector<int> v;
	v.reserve(10);
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	auto it = find(v.begin(), v.end(), 5);
	if (it != v.end()) {
		cout << "5 is in vector" << endl;
	}
	else {
		cout << "5 is not in vector" << endl;
	}
	return 0;
}
#endif


#if 0
int main() {
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto it = v.begin();
	
	//������ܻ����ݣ�������ݣ�vector��ǰ�ռ䱻�ͷ�
	//it ��������ʧЧ
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//������ʧЧ��������������һ��ָ�룬ָ����ָ��Ŀռ�Ƿ�
	//������ʧЧ�Ľ����ʽ�������������¸�ֵ
	//resize reserve push_back insert swap assign

	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}

	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5 };
	auto it1 = v1.begin();
	//v1.swap(v2);
	while (it1 != v1.end()) {
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	vector<int> v3{ 1, 2, 3 };
	auto it2 = v.begin();
	v3.assign(10, 5);
	it2 = v3.begin();
	cout << *it2 << endl;


	return 0;
}
#endif

#if 0
int main() {
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto it = v.begin();

	while (it != v.end()) {
		it = v.erase(it);	//erase���ص���һ��Ԫ��λ��
		//++it;		//ɾ�˸�Ԫ�ص�����ʧЧ

	}
	return 0;
}
#endif


//�������
vector<vector<int>> PascalTriangle(int nRows) {
	vector<vector<int>> vRet;
	if (0 == nRows)
		return vRet;
	
	vRet.resize(nRows);
	for (size_t i = 0; i < nRows; ++i) {
		vRet[i].resize(i + 1);
		vRet[i][0] = vRet[i][i] = 1;
	}

	for (size_t i = 2; i < nRows; ++i) {
		for (size_t j = 1; j < i; ++j) {
			vRet[i][j] = vRet[i - 1][j] + vRet[i - 1][j - 1];
		}
	}
	return vRet;
}

int main() {
	vector<vector<int>> vRet = PascalTriangle(5);
	for (size_t i = 0; i < vRet.size(); ++i) {
		for (size_t j = 0; j < vRet[i].size(); ++j) {
			cout << vRet[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}
