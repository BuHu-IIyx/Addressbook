#pragma once
#include "Person.h"
class Friend :
    public Person
{
private:
    string nickname;
public:
    Friend();
    Friend(string, string, string, string);
    void setPerson(string, string, string, string);
    static Person* getCopy(Friend);
    string getPerson() override;
    char getStatus() override; 
};

