#include"Person.h"

//C++�ṹ����Էź���
#if 0
// class Student ��
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

	s1.InitStudent("Peter", "��", 40);
	s2.InitStudent("����", "Ů", 41);
	s3.InitStudent("Summer", "��", 21);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	return 0;
}
#endif

//���� ---> һ���ֽ� ---> ���ָ��ഴ���Ĳ�ͬ����
//����������һ���ֽ�
class A
{};
//һ���ֽ�
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

	s1.InitStudent("Peter", "��", 40);
	s2.InitStudent("����", "Ů", 41);
	s3.InitStudent("Summer", "��", 21);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;		//28
	cout << sizeof(A) << endl << sizeof(B) << endl;	//1

	cout << offsetof(C, c) << endl;		//��ƫ����

	cout << &s1 << endl;		//�͵��ú����е�thisָ���ַ��ͬ

	/*Person* p = &s1;
	p->PrintStudent();
							//��ʱthisָ��Ϊ�գ�������ʳ�Ա���������
	p = nullptr;
	p->PrintStudent();		//Student::PrintStuden(p);
	*/

	return 0;
}

