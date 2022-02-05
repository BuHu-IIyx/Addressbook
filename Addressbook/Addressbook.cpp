#include "Addressbook.h"

Addressbook::Addressbook()
{
	pathF = "FriendBook.txt";
	pathC = "ColleagueBook.txt";
}
void Addressbook::start()
{	
	std::ifstream finF;
	finF.open(pathF);
	Friend fr;
	if (!finF.is_open())
	{
		cout << "Ошибка открытия файла FriendBook.txt";
	}
	else
	{
		while (finF.read((char*)&fr, sizeof(Friend)))
		{
			book.push_back(&fr);
		}
		cout << "Файл FriendBook.txt загружен." << endl;
	}
	finF.close();
	//std::ifstream finF(pathF);
	//Friend f;
	//if (finF.is_open())
	//{
	//	while (finF.read((char*)&f, sizeof(Friend)))
	//	{
	//		Fbook.push_back(f);
	//	}
	//	cout << "Файл FriendBook.txt загружен." << endl;
	//}
	//else
	//{
	//	cout << "Ошибка открытия файла FriendBook.txt";
	//}
	//finF.close();

	//std::ifstream finC(pathC);
	//Colleague c;
	//if (finC.is_open())
	//{
	//	while (finC.read((char*)&c, sizeof(Colleague)))
	//	{
	//		Cbook.push_back(c);
	//	}
	//	cout << "Файл ColleagueBook.txt загружен." << endl;
	//}
	//else
	//{
	//	cout << "Ошибка открытия файла ColleagueBook.txt";
	//}
	//finC.close();


	//unsigned int flag;
	//while (true)
	//{
	//	flag = mainMenu();
	//	if (flag == 0)
	//	{
	//		saveBook();
	//		break;
	//	}			
	//	else
	//	{
	//		selectAction(flag);
	//	}		
	//}
}
unsigned int Addressbook::mainMenu()
{
	while (true)
	{
		unsigned int flag = 0;
		cout << "Выберите пункт меню:\n"
			<< "\t1. Показать все записи\n"
			<< "\t2. Добавить запись\n"
			<< "\t3. Удалить запись\n"
			<< "\t4. Найти запись\n"
			<< "\t5. Сохранить\n"
			<< "\t0. Выйти\n" << endl;
		cin >> flag;
		if (flag >= 0 && flag < 6)
			return flag;
		else
		{
			cout << "Ошибка, нажмите Enter для повтора!" << endl;
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
		cout << "Ошибка, нажмите Enter для возврата в главное меню." << endl;
		cin;
		break;
	}
}
void Addressbook::showAll()
{
	for (auto f : book)
	{
		cout << f->getPerson() << endl;
	}
}

void Addressbook::addPerson(Person* f)
{
	book.emplace_back(f);
}

void Addressbook::addPerson()
{	
	string name;
	string lastName;
	string phone;
	string nickName;
	cout << "Введите имя, фамилию, номер телефона и прозвище через пробел:\n";
	cin >> name >> lastName >> phone >> nickName;
	Person* p = new Friend(name, lastName, phone, nickName);
	book.push_back(p);
}

void Addressbook::saveBook()
{
	std::ofstream foutF;
	std::ofstream foutC;
	foutF.open(pathF);
	foutC.open(pathF);
	if (!foutF.is_open())
		cout << "Ошибка сохранения." << endl;
	else
	{
		for (auto f : book)
		{
			if (f->getStatus() == 'F')
				foutF.write((char*)f, sizeof(Friend));
			else if (f->getStatus() == 'C')
				foutC.write((char*)f, sizeof(Colleague));
			else
				continue;
		}
		cout << "Файл сохранен." << endl;
	}
	foutF.close();
	foutC.close();
}