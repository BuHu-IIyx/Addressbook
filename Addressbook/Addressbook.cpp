#include "Addressbook.h"

Addressbook::Addressbook()
{
	pathF = "FriendBook.txt";
	pathC = "ColleagueBook.txt";
}
//void Addressbook::start()
//{	
//	std::ifstream finF;
//	finF.open(pathF);
//	Friend* fr = new Friend;
//	if (!finF.is_open())
//	{
//		cout << "������ �������� ����� FriendBook.txt";
//	}
//	else
//	{
//		while (finF.read((char*)fr, sizeof(Friend)))
//		{
//			addPerson(*fr);
//		}
//		cout << "���� FriendBook.txt ��������." << endl;
//	}
//	finF.close();
//	
//	std::ifstream finC(pathC);
//	Colleague c;
//	if (finC.is_open())
//	{
//		while (finC.read((char*)&c, sizeof(Colleague)))
//		{
//			Cbook.push_back(c);
//		}
//		cout << "���� ColleagueBook.txt ��������." << endl;
//	}
//	else
//	{
//		cout << "������ �������� ����� ColleagueBook.txt";
//	}
//	finC.close();
//}
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
			<< "\t0. �����\n" << endl;
		cin >> flag;
		if (flag >= 0 && flag < 6)
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
		addPerson();
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
	default:
		cout << "������, ������� Enter ��� �������� � ������� ����." << endl;
		cin;
		break;
	}
}
void Addressbook::showAll()
{
	//for (auto f : book)
	//{
	//	cout << f->getPerson() << endl;
	//}
}

void Addressbook::addPerson(Friend f)
{	
	//if (f.getStatus() == 'F')
	//{		
	//	book.push_back(&f);
	//}		
	//else
	//{
	//	Colleague* temp = new Colleague;
	//	book.push_back(temp);
	//}
}

void Addressbook::addPerson(char f)
{	
	string name;
	string lastName;
	string phone;
	string nickName;
	cout << "������� ���, �������, ����� �������� � �������� ����� ������:\n";
	cin >> name >> lastName >> phone >> nickName;
	Friend p (name, lastName, phone, nickName);
	addPerson(p);
}

void Addressbook::saveBook()
{
	//std::ofstream foutF;
	//std::ofstream foutC;
	//foutF.open(pathF);
	//foutC.open(pathC);
	//if (!foutF.is_open())
	//	cout << "������ ����������." << endl;
	//else
	//{
	//	for (auto f : book)
	//	{
	//		if (f->getStatus() == 'F')
	//			foutF.write((char*)f, sizeof(Friend));
	//		else if (f->getStatus() == 'C')
	//			foutC.write((char*)f, sizeof(Colleague));
	//		else
	//			continue;
	//	}
	//	cout << "���� ��������." << endl;
	//}
	//foutF.close();
	//foutC.close();
}