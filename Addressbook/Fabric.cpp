#include "Person.h"
#include "Friend.h"
#include "Colleague.h"

static Person* createPerson(string name, string lastName, string phone, string nickname)
{
	return new Friend(name, lastName, phone, nickname);
}

static Person* createPerson(string name, string lastName, string phone,	string position, string department, string organization)
{
	return new Colleague(name, lastName, phone, position, department, organization);
}

