#pragma once
#include <list>
#include <vector>
#include <map>
#include <fstream>
#include "Person.h"
#include "Friend.h"
#include "Colleague.h"
class Addressbook
{
private:
	std::map<string, Person*> book;
	std::map<string, Person*>::iterator bookIter;
	string pathF;
	string pathC;
	
	void selectAction(unsigned int);
public:
	Addressbook();
	unsigned int mainMenu();
	void start();
	void loadBook();
	void showAll();
	void addPerson(char);
	void addPerson(Person*);
	void delPerson();
	void findPerson();
	void saveBook();
};

