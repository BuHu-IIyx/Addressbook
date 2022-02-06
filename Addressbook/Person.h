#pragma once
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Person
{
protected:
	string name;
	string lastName;
	string phone;
	char status; // Friend = F, Colleague = C, N/A = N
public:
	Person();
	Person(string, string, string, char);
	virtual void setPerson(string, string, string, char);
	virtual string getPerson();
	string getName();
	virtual char getStatus() = 0;
	virtual ~Person() {};
};

