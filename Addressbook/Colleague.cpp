#include "Colleague.h"

Colleague::Colleague():Person()
{
    position = "";
    department = "";
    organization = "";
}
Colleague::Colleague(string name, string lastName, string phone, 
    string position, string department, string organization) : Person(name, lastName, phone, 'C')
{
    Colleague::position = position;
    Colleague::department = department;
    Colleague::organization = organization;
}
void Colleague::setPerson(string name, string lastName, string phone,
    string position, string department, string organization)
{
    Colleague::Person::setPerson(name, lastName, phone, 'C');
    Colleague::position = position;
    Colleague::department = department;
    Colleague::organization = organization;
}
char Colleague::getStatus()
{
    return status;
}
string Colleague::getPerson()
{
    std::stringstream ss;
    ss << Person::getPerson() << " (" << organization << ", " << department << ", " << position << ")";
    return ss.str();
}