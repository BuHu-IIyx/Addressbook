#pragma once
#include "Person.h"
class Colleague :
    public Person
{
private:
    string position;
    string department;
    string organization;
public:
    Colleague();
    Colleague(string, string, string, string, string, string);
    void setPerson(string, string, string, string, string, string);
    static Person* getCopy(Colleague);
    string getPerson() override;
    char getStatus() override;
};

