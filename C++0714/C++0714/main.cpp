#include"Person.h"

//C++结构体可以放函数
#if 0
// class Student 类
struct Student
{
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1;
	Student s2;
	Student s3;

	s1.InitStudent("Peter", "男", 40);
	s2.InitStudent("静静", "女", 41);
	s3.InitStudent("Summer", "公", 21);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	return 0;
}
#endif

//空类 ---> 一个字节 ---> 区分该类创建的不同对象
//主流编译器一个字节
class A
{};
//一个字节
class B
{
public:
	void TestFunc()
	{}
};

struct C
{
	int a;
	char b;
	double c;
	char d;
};
int main()
{
	Person s1;
	Person s2;
	Person s3;

	s1.InitStudent("Peter", "男", 40);
	s2.InitStudent("静静", "女", 41);
	s3.InitStudent("Summer", "公", 21);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;		//28
	cout << sizeof(A) << endl << sizeof(B) << endl;	//1

	cout << offsetof(C, c) << endl;		//查偏移量

	cout << &s1 << endl;		//和调用函数中的this指针地址相同

	/*Person* p = &s1;
	p->PrintStudent();
							//此时this指针为空，如果访问成员变量则崩溃
	p = nullptr;
	p->PrintStudent();		//Student::PrintStuden(p);
	*/

	return 0;
}

