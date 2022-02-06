#include <iostream>
#include "Addressbook.h"

int main()
{
    system("chcp 1251");
    Addressbook* address = new Addressbook;    
    address->start();
    return 1;
}