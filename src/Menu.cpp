/*
 * Menu.cpp
 *
 *  Created on: 29 sie 2018
 *      Author: mediaexpert
 */

#include "Menu.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::showUserMenu(Warehouse *apteka){
		int  menuChoice = 0;
		cout << "Witamy w apteka management soft" <<endl << endl;

		do
		{
			system("cls");
			cout << "Dostepne opcje wyboru" << endl;
			cout << "1) Stworz produkt" <<endl;
			cout << "2) Dodaj produkt"<<endl;
			cout << "3) Wylistuj produkty "<<endl;
			cout << "4) Usun produkt"<<endl;
			cout << "5) Zmien dane produktu"<<endl;
			cout << "6) Wyswietl dane leku"<<endl;
			cout << "7) Zamow towar" <<endl;
			cout << "8) EXIT" <<endl;
			cout << "Wybierz opcje: ";
			cin >> menuChoice;

			switch (menuChoice)
			{
				case 1:
					//Dodaj nowy produkt do magazynu
					break;
				case 2:
					//Dodaj produkty
					break;
				case 3: // Wypisywanie wszystkich produktow
				{
					system("cls");
					cout << " Wszystkie zaindeksowane produkty:" << endl;
					apteka->showAllProducts();
					cout << endl;
					system("Pause");
					break;
				}
				case 4: // Kasowanie produktu
				{
					/*
					 * TODO - wybor wg jakiego kryterium mozna kasowac, index, nazwa, stan magazynowy
					 * TODO - wyswietleie produktu czy aby na pewno ten chemy skasowac T/N
					 *
					 */

					system("cls");
					cout << "Jaki produkt wg indeksu chcesz skasowac" << endl;
					int index = 0;
					cin >> index;
					apteka->eraseElementByPosition(index);
					cout << "Produkt wykasowany" << endl;
					system("Pause");

					break;
				}
				case 5:
					//Zmien dane produktu
					break;
				case 6:
					//Wyswietl pe�ne informacje na temat danego produktu + d�ugi opis,
					break;
				case 7 :
					// UUUU tutaj to jakas wieksza operacja sie szykuje
					break;
				case 8:
					cout << "Zakonczenie dzialnia programu" << endl;
					break;
				default:
					cout << "Bad input motherfucker" << endl;
					break;
			}

		}while(menuChoice != 8);
}

void Menu::showAdminMenu(){
		char choice;
		do
		{

			system("CLS");
			cout << "Witaj a panelu administracyjnym" <<endl << endl;
			cout << "1) Dodaj uzytkownika" <<endl;
			cout << "2) Usun uzytkownika"<<endl;
			cout << "3) C "<<endl;
			cout << "4) D"<<endl;

			cout << "Q) EXIT" <<endl;
			cout << "Wybierz opcje: " << endl;
			cin.get(choice);

			switch (choice)
			{
				case '1':
					//Dodaj nowy produkt do magazynu
					break;
				case '2':
					//Dodaj produkty
					break;
				case '3':
					//Wy�wietl wszsytkie produkty
					break;
				case '4':
					//Wykasuj product
					break;
				case '5':
					//Zmien dane produktu
					break;
				case '6':
					//Wyswietl pe�ne informacje na temat danego produktu + d�ugi opis,
					break;
				case '7' :
					// UUUU tutaj to jakas wieksza operacja sie szykuje
					break;
				case '8':
					break;
			}
		}while(choice != 'Q' or choice != 'q');
}
