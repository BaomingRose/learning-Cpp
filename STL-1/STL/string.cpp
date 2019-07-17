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
	//string֧��ֱ�����
	cout << s2 << endl << s3 << endl << s4 << endl;

	//cin >> s1;		��hello world������ȫ������ �Կո�ָ�
	getline(cin, s1);		//����һ��
	cout << s1 << endl;
	return 0;
#endif

#if 0
	string s("hello");
	//size �� length һ��(��Ч����)
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
	//��string������Ч�ַ��䵽n��������Ŀռ���ch���
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
	
	//resize:�ı���ЧԪ�ظ���+��������
	//reserve��ֻ�ı�ռ�Ĵ�С�����ı���ЧԪ�ظ���
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

	s.clear();	//���ı�ײ�ռ��С
	cout << s << s.size() << endl << s.capacity() << endl;
	//	0	31

#endif


#if 0 
	string s("hello");
	//cout << s[3] << endl;
	//cout << s[10] << endl;	//����
	//cout << s.at(3) << endl;
	//cout << s.at(10) << endl;	//�쳣

	//������������һ��ָ��
	reverse(s.begin(), s.end());
	cout << s << endl;
	//string::iterator it = s.begin();
	//�������string��
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

	//���������ӡ
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
//begin��end�����������++����--->��������begin��end�ķ����ƶ�
//rbegin��rend�����������++�����������������--�Ĳ���
#endif


#if 0
	string s;
	s += 'I';		//���ַ�
	s += " Love ";	//���ַ���

	string str("myself ");
	s += str;
	cout << s << endl;

	s.push_back('!');		//β��һ���ַ�
	cout << s << endl;

	size_t pos = s.find('!');
	if (pos != string::npos)
	{
		s.insert(pos, "^_^");
	}
	cout << s << endl;
	
	s.erase(s.rfind(' ') + 1, 3);						//�������
	cout << s << endl;

	s.replace(s.find("myself"), 6, "you");
	cout << s << endl;

	//fopen(s.c_str(), "rb");	//fopen����Ϊconst char*����s��string�����
							//c_str ��string�����ת��C��ʽ���ַ���
	char* p = (char*)s.c_str();


	swap(s, str);
	cout << s << endl;
	s.swap(str);
	cout << s << endl;

	//������һ�����ʵĳ��ȣ�ÿ�������Կո�ָ�
	//while(cin >> s)   ѭ������ÿ������
	/*while (getline(cin, s))			//ѭ������ÿ��
	{
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}*/

	//���������Ч�ַ�
	/*s.erase();						
	s.erase(s.begin(), s.end());
	s.clear();*/

	return 0;
}


#endif