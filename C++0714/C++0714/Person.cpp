#include"Person.h"
void Person::InitStudent(const char* name, const char* gender, int age)
{
	cout << this << endl;
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Person::PrintStudent()
{
	cout << _name << ":" << _gender << ":" << _age << endl;
}