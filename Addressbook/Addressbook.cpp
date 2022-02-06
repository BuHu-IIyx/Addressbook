#include "Addressbook.h"
#include "Fabric.cpp"

Addressbook::Addressbook()
{
	pathF = "FriendBook.txt";
	pathC = "ColleagueBook.txt";
}
void Addressbook::start()
{		
		while (true)
	{
		unsigned int flag = mainMenu();
		if (flag == 0)
			break;
		else
			selectAction(flag);
	}
	

}
unsigned int Addressbook::mainMenu()
{
	while (true)
	{
		unsigned int flag = 0;
		cout << "�������� ����� ����:\n"
			<< "\t1. �������� ��� ������\n"
			<< "\t2. �������� ������\n"
			<< "\t3. ������� ������\n"
			<< "\t4. ����� ������\n"
			<< "\t5. ���������\n"
			<< "\t6. ���������\n"
			<< "\t0. �����\n" << endl;
		cin >> flag;
		if (flag >= 0 && flag < 7)
			return flag;
		else
		{
			cout << "������, ������� Enter ��� �������!" << endl;
			cin;
		}
	}
}
void Addressbook::selectAction(unsigned int flag)
{
	switch (flag)
	{
	case 1:
		showAll();
		break;
	case 2:
		char f;
		cout << "���� �� ������ ��������? ����� ��� ������� (F/C)";
		cin >> f;
		addPerson(f);
		break;
	//case 3:
	//	delPerson();
	//	break;
	//case 4:
	//	findPerson();
	//	break;
	case 5:
		saveBook();
		break;
	case 6:
		loadBook();
		break;
	default:
		cout << "������, ������� Enter ��� �������� � ������� ����." << endl;
		cin;
		break;
	}
}
void Addressbook::showAll()
{
	for (auto const f : book)
	{
		cout << f.second->getPerson() << endl;
	}
}

void Addressbook::addPerson(Person* f)
{	
	string key = f->getName();
	book.insert(make_pair(key, f));
}

void Addressbook::addPerson(char f)
{	
	string name;
	string lastName;
	string phone;
	if (f == 'F')
	{		
		string nickName;
		cout << "������� ���, �������, ����� �������� � �������� ����� ������:\n";
		cin >> name >> lastName >> phone >> nickName;		
		addPerson(createPerson(name, lastName, phone, nickName));
	}
	else
	{
		string position;
		string department;
		string organization;
		cout << "������� ���, �������, ����� ��������, ���������, ����� � ����������� ����� ������:\n";
		cin >> name >> lastName >> phone >> position >> department >> organization;
		addPerson(createPerson(name, lastName, phone, position, department, organization));		
	}
	
}

void Addressbook::saveBook()
{
	std::ofstream foutF;
	std::ofstream foutC;
	foutF.open(pathF);
	foutC.open(pathC);
	if (!foutF.is_open())
		cout << "������ ����������." << endl;
	else
	{
		for (auto f : book)
		{
			if (f.second->getStatus() == 'F')
				foutF.write((char*)f.second, sizeof(Friend));
			else if (f.second->getStatus() == 'C')
				foutC.write((char*)f.second, sizeof(Colleague));
			else
				continue;
		}
		cout << "���� ��������." << endl;
	}
	foutF.close();
	foutC.close();
}
void Addressbook::loadBook()
{
	std::ifstream finF;
	finF.open(pathF);
	Friend* fr = new Friend();
	if (!finF.is_open())
	{
		cout << "������ �������� ����� FriendBook.txt";
	}
	else
	{
		while (finF.read((char*)fr, sizeof(Friend)))
		{
			addPerson(fr->getCopy(*fr));
		}
		cout << "���� FriendBook.txt ��������." << endl;
	}
	finF.close();
	
	std::ifstream finC(pathC);
	Colleague* c = new Colleague();
	if (finC.is_open())
	{
		while (finC.read((char*)c, sizeof(Colleague)))
		{			
			addPerson(c->getCopy(*c));
		}
		cout << "���� ColleagueBook.txt ��������." << endl;
	}
	else
	{
		cout << "������ �������� ����� ColleagueBook.txt";
	}
	finC.close();
}