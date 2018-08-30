/*
 * MenuOptions.cpp
 *
 *  Created on: 30 sie 2018
 *      Author: mediaexpert
 */

#include "MenuOptions.h"

MenuOptions::MenuOptions() {
	// TODO Auto-generated constructor stub

}

MenuOptions::~MenuOptions() {
	// TODO Auto-generated destructor stub
}

void MenuOptions::eraseProductOption(Warehouse * apteka){
	system("cls");
	cout << "W jaki sposob chcesz usunac produkty?" << endl;
	cout << "1) Poprzez ID produktu" << endl;
	cout << "2) Poprzez Nazwe produktu" << endl;
	cout << "3) Poprzez Kategorie produktu" << endl;
	cout << "4) Anuluj operacje" << endl;
	cout << "Wprowadz wybor: ";
	int eraseChoice = 0;
	cin >> eraseChoice;

		switch(eraseChoice)
		{
			case 1 :
			{
				cout << "Jaki produkt wg indeksu chcesz skasowac" << endl;
				int index = 0;
				cin >> index;
				apteka->eraseElementByPosition(index);
				cout << "Produkt wykasowany" << endl;
				system("Pause");
				break;
			}
			case 2 :
			{
				cout << "Jaki produkty wg Nazwy chcesz skasowac" << endl;
				string eraseName;
				cin >> eraseName;
				apteka->eraseElementByName(eraseName);
				cout << "Produkt wykasowany" << endl;
				system("Pause");
				break;
			}
			case 3 :
				break;
			case 4 :
				break;
			default :
				break;
		}
}
