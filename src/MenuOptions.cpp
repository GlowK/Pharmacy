/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
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
				SearchResult searchResult;
				searchResult.populateSearchResultsById(apteka, index);
				cout << endl;
				cout << "Czy na pewno chcesz skasowac ten produkt? T/N ";
				char confirmation;
				cin >> confirmation;
				if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
					apteka->eraseElementById(index);
					cout << "Produkt wykasowany" << endl;
				}
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
				SearchResult searchResult;
				searchResult.populateCategoryList(apteka);
				searchResult.showCategoryList();
				cout << "Podaj numer kategorii, ktora chcesz skasowac" << endl;
				int eraseCategory;
				cin >> eraseCategory;
				string eraseCat = searchResult.populateSearchResultsByCategoryReturnCategoryName(apteka, eraseCategory);
				searchResult.showAllProducts();
				cout << "Czy na pewno chcesz skasowac te produkty? T/N ";
				char confirmation;
				cin >> confirmation;
				if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
					apteka->eraseElementByCategory(eraseCat);
					cout << "Produkty wykasowane" << endl;
				}
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
				cout << endl << "Anulowanie..." << endl;
				system("Pause");
				break;
			default :
				break;
		}
}


void MenuOptions::searchOption(Warehouse *apteka, int clearScreenFlag){
	if(clearScreenFlag == 1){
			system("cls");
	}
	cout << "W jaki sposob chcesz przeszukac baze: " << endl;
	cout << "1) Po nazwie produktu" << endl;
	cout << "2) Po kategorii produktu" << endl;
	cout << "3) Po cenie produktu (min/max)" << endl;
	cout << "4) Anuluj " << endl;
	cout << "Wprowadz wybor: ";

	int searchOptionChoice = 0;
	cin >> searchOptionChoice;

		switch(searchOptionChoice)
		{
			case 1 :
			{
				system("cls");
				nameSearch(apteka);
				break;
			}
			case 2 :
			{
				system("cls");
				categorySearch(apteka);
				break;
			}
			case 3 :
			{
				system("cls");
				priceSearch(apteka);
				break;
			}
			case 4 :
				cout << endl << "Anulowanie..." << endl;
				system("Pause");
				break;
			default :
				break;
		}
}

void MenuOptions::categorySearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po kategorii produktu **********" << endl;
	cout << "Dostepne kategorie do przeszukania: " << endl << endl;
	SearchResult searchResult;
	searchResult.populateCategoryList(apteka);
	int rangeControl = searchResult.showCategoryList();
	cout<< endl << "Podaj numer kategorii do wyswietelnia: ";
	int categoryNumber;
	cin >> categoryNumber;
	if(categoryNumber < 0 || categoryNumber > rangeControl){
		cout << "Nie ma takiej kategorii. Przerywam..." << endl;
		system("Pause");
	}else{
		cout << endl;
		searchResult.populateSearchResultsByCategory(apteka, categoryNumber);
		searchResult.showAllProducts();
		cout << endl;
		system("Pause");
	}
}


void MenuOptions::nameSearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po nazwie produktu **********" << endl;
	cout << "Podaj nazwe produktu do wyszukania" << endl;
	string searchedName;
	cin >> searchedName;
	SearchResult searchResult;
	searchResult.populateSearchRusultsByName(apteka, searchedName);
	cout << endl;
	system("Pause");
}

void MenuOptions::priceSearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po cenie (min/max) **********" << endl;
	cout << "Podaj minimalna wartosc minimalna: ";
	float minValue;
	cin >> minValue;
	cout << "Podaj wartosc maksymalna: ";
	float maxValue;
	cin >> maxValue;
	cout << endl;
	SearchResult searchResult;
	searchResult.populateSearchResultsByPrice(apteka, minValue, maxValue);
	cout << endl;
	system("Pause");
}
