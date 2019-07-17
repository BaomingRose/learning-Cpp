#include<iostream>
using namespace std;
#include<string>


#if 0

int main()
{
	string s1;
	string s2("hello world");
	string s3(10, '$');
	string s4(s3);
	//string支持直接输出
	cout << s2 << endl << s3 << endl << s4 << endl;

	//cin >> s1;		“hello world”不能全部接收 以空格分割
	getline(cin, s1);		//接收一行
	cout << s1 << endl;
	return 0;
#endif

#if 0
	string s("hello");
	//size 和 length 一样(有效长度)
	cout << s << endl << s.size() << endl;	//5
	cout << s.length() << endl;				//5
	cout << s.capacity() << endl;			//15

	if (s.empty())
	{
		cout << "empty string " << endl;
	}
	else
	{
		cout << "not empty string " << endl;
	}
	cout << endl;

	cout << s.capacity() << endl;

	//void resize(size_t n, char ch)
	//将string类中有效字符变到n个，多出的空间用ch填充
	s.resize(10, '$');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << endl;

	s.resize(30, '8');
	cout << s << endl << s.size() << endl << s.capacity() << endl;
	cout << endl;

	s.resize(2);
	cout << s << endl << s.size() << endl << s.capacity() << endl;
	cout << endl;

	s.resize(12);
	cout << s << endl << s.size() << endl << s.capacity() << endl;
#endif

#if 0
	string s("hello");
	
	//resize:改变有效元素个数+可能扩容
	//reserve：只改变空间的大小，不改变有效元素个数
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;		//5
	cout << s.capacity() << endl;	//15

	s.reserve(20);
	cout << s << endl << s.size() << endl << s.capacity() << endl;
	//	5	31

	s.reserve(3);
	cout << s << endl << s.size() << endl << s.capacity() << endl;
	//	5	31
	cout << endl;

	s.clear();	//不改变底层空间大小
	cout << s << s.size() << endl << s.capacity() << endl;
	//	0	31

#endif


#if 0 
	string s("hello");
	//cout << s[3] << endl;
	//cout << s[10] << endl;	//崩溃
	//cout << s.at(3) << endl;
	//cout << s.at(10) << endl;	//异常

	//迭代器：类似一个指针
	reverse(s.begin(), s.end());
	cout << s << endl;
	//string::iterator it = s.begin();
	//正向遍历string类
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	for (auto e : s)
		cout << e;
	cout << endl;

	//反向遍历打印
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
//begin、end正向迭代器：++操作--->迭代器从begin向end的方向移动
//rbegin、rend反向迭代器：++操作类似正向迭代器--的操作
#endif


#if 0
	string s;
	s += 'I';		//接字符
	s += " Love ";	//接字符串

	string str("myself ");
	s += str;
	cout << s << endl;

	s.push_back('!');		//尾插一个字符
	cout << s << endl;

	size_t pos = s.find('!');
	if (pos != string::npos)
	{
		s.insert(pos, "^_^");
	}
	cout << s << endl;
	
	s.erase(s.rfind(' ') + 1, 3);						//反向查找
	cout << s << endl;

	s.replace(s.find("myself"), 6, "you");
	cout << s << endl;

	//fopen(s.c_str(), "rb");	//fopen参数为const char*，而s是string类对象
							//c_str 将string类对象转成C格式的字符串
	char* p = (char*)s.c_str();


	swap(s, str);
	cout << s << endl;
	s.swap(str);
	cout << s << endl;

	//输出最后一个单词的长度，每个单词以空格分隔
	//while(cin >> s)   循环接收每个单词
	/*while (getline(cin, s))			//循环接收每行
	{
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}*/

	//三个清空有效字符
	/*s.erase();						
	s.erase(s.begin(), s.end());
	s.clear();*/

	return 0;
}


#endif