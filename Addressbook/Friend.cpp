#include "Friend.h"

Friend::Friend() : Person()
{
    nickname = "";
}
Friend::Friend(string name, string lastName, string phone, string nickname) 
    : Person(name, lastName, phone, 'F')
{
    Friend::nickname = nickname;
}
void Friend::setPerson(string name, string lastName, string phone, string nickname)
{
    Friend::Person::setPerson(name, lastName, phone, 'C');
    Friend::nickname = nickname;
}
string Friend::getPerson()
{
    std::stringstream ss;
    ss << Person::getPerson() << " (" << nickname << ")";
    return ss.str();
}
char Friend::getStatus()
{
    return status;
}