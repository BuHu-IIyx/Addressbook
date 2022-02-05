#include <iostream>
#include "Addressbook.h"

int main()
{
    system("chcp 1251");
    Addressbook address;
    address.start();
    //address.addPerson();
    //address.showAll();
    address.saveBook();
    return 1;
}