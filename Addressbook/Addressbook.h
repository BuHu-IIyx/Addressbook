#pragma once
#include <list>
#include <fstream>
#include "Person.h"
#include "Friend.h"
#include "Colleague.h"
class Addressbook
{
private:
	std::list <Friend> Fbook;
	std::list <Colleague> Cbook;
	std::list <Person* > book;
	string pathF;
	string pathC;
	unsigned int mainMenu();
	void selectAction(unsigned int);
public:
	Addressbook();
	void start();
	void showAll();
	void addPerson();
	void addPerson(Person*);
	//void addFriend(Friend);
	//void addColleague(Colleague);
	void delPerson();
	void findPerson();
	void saveBook();
};

