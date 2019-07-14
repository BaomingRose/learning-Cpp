#if 0
#include<iostream>
#include<assert.h>
#include<malloc.h>
using namespace std;



class String
{
public:
	String(const char* pstr = "")
	{
		_str = (char*)malloc(strlen(pstr) + 1);
		if (nullptr == _str)
		{
			assert(0);
			return;
		}

		strcpy(_str, pstr);

		cout << "String()" << endl;
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
		cout << "~String()" << endl;
	}
private:
	char* _str;
};

class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
private:
	String _strName;
};

void TestPerson()
{
	Person p;
}
int main()
{
	TestPerson();
	return 0;
}


#endif