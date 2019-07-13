#pragma once
#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
	void InitStudent(const char* name, const char* gender, int age);
	void PrintStudent();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

