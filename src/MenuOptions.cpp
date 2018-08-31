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
				apteka->eraseElementById(index);
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
			{
				cout << "Jaki produkty wg Kategorii chcesz skasowac" << endl;
				string eraseCategory;
				cin >> eraseCategory;
				apteka->eraseElementByCategory(eraseCategory);
				cout << "Produkt wykasowany" << endl;
				system("Pause");
				break;
			}
			case 4 :
				break;
			default :
				break;
		}
}


void MenuOptions::showProductDetailsOption(Warehouse * apteka, int clearScreenFlag){

	if(clearScreenFlag == 1){
		system("cls");
	}
	cout << "W jaki sposob wyswietlic szczegoly produktu?" << endl;
	cout << "1) Poprzez ID produktu" << endl;
	cout << "2) Poprzez Nazwe produktu" << endl;
	cout << "3) Anuluj operacje" << endl;
	cout << "Wprowadz wybor: ";

	int showDetailsChoice = 0;
	cin >> showDetailsChoice;

		switch(showDetailsChoice)
		{
			case 1 :
			{
				cout << "Podaj ID do pokazania szczeglow" << endl;
				int byIndex = 0;
				cin >> byIndex;
				apteka->showProductDetailsThroughIndex(byIndex);
				system("Pause");
				break;
			}
			case 2 :
			{
				cout << "Podaj Nazwe dla pokazania szczegolow" << endl;
				string byName;
				cin >> byName;
				//apteka->eraseElementByName(byName);
				system("Pause");
				break;
			}
			case 3 :
				break;
			default :
				break;
		}
}


void MenuOptions::searchOption(Warehouse *apteka, int clearScreenFlag){
	if(clearScreenFlag == 1){
			system("cls");
	}
	cout << "W jaki sposob wchcesz przeszukac baze" << endl;
	cout << "1) Po nazwie produktu" << endl;
	cout << "2) Po kategorii produktu" << endl;
	cout << "3) Po cenie produktu" << endl;
	cout << "4) Po wymagalnosci recepty " << endl;
	cout << "5) Anuluj " << endl;
	cout << "Wprowadz wybor: ";

	int showDetailsChoice = 0;
	cin >> showDetailsChoice;

		switch(showDetailsChoice)
		{
			case 1 :
			{
				cout << "Podaj ID do pokazania szczeglow" << endl;
				int byIndex = 0;
				cin >> byIndex;
				apteka->showProductDetailsThroughIndex(byIndex);
				system("Pause");
				break;
			}
			case 2 :
			{
				cout << "Podaj Nazwe dla pokazania szczegolow" << endl;
				string byName;
				cin >> byName;
				//apteka->eraseElementByName(byName);
				system("Pause");
				break;
			}
			case 3 :
				break;
			default :
				break;
		}
}
