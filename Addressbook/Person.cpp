#include "Person.h"
Person::Person()
{
	//Person::name = "";
	//Person::lastName = "";
	//Person::phone = "";
	//Person::status = 'N';
}
Person::Person(string name, string lastName, string phone, char status = 'N')
{
	Person::name = name;
	Person::lastName = lastName;
	Person::phone = phone;
	Person::status = status;	
};
void Person::setPerson(string name, string lastName, string phone, char status = 'N')
{
	Person::name = name;
	Person::lastName = lastName;
	Person::phone = phone;
	Person::status = status;
}
string Person::getPerson()
{
	std::stringstream ss;
	ss << lastName << " " << name << " - " << phone;
	return ss.str();
}