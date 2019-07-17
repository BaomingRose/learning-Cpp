#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	//区间构造
	vector<int> v3(v2.begin(), v2.end());
	
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	vector<int> v5(v4);

	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	//采用迭代器遍历
	//vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v4)
		cout << e << " ";
	cout << endl;

	auto rit = v5.rbegin();
	while (rit != v5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}