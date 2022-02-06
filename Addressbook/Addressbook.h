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
	std::vector <Friend> Fbook;
	std::vector <Colleague> Cbook;
	//std::list <Person* > book;
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
	void loadFriends();
	void loadColleagues();
	void showAll();
	void addPerson(char);
	//template <class T>
	void addPerson(Person*);
	//void addFriend(Friend);
	//void addColleague(Colleague);
	void delPerson();
	void findPerson();
	void saveBook();
};

