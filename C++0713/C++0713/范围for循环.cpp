#include<iostream>
using namespace std;


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto& e : arr)
		e *= 2;

	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}