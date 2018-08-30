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
		MenuOptions menuOptions;
		cout << "Witamy w apteka management soft" <<endl << endl;

		do
		{
			system("cls");
			cout << "Dostepne opcje wyboru" << endl;
			cout << "1) Stworz produkt" << endl;
			cout << "2) Dodaj produkt"<< endl;
			cout << "3) Wylistuj produkty "<< endl;
			cout << "4) Usun produkt"<< endl;
			cout << "5) Zmien dane produktu"<< endl;
			cout << "6) Wyswietl dane leku"<< endl;
			cout << "7) Zamow towar" << endl;
			cout << "8) Pokaz towary o niskim stanie magazynowym" << endl;
			cout << "9) EXIT" << endl;
			cout << "Wybierz opcje: ";
			cin >> menuChoice;

			switch (menuChoice)
			{
				case 1://Dodaj nowy produkt do magazynu
					/*
					 * TODO - Dodanie zupelnie nowego produktu
					 */
					break;
				case 2: //Dodaj produkty
					/*
					 * TODO - Mozna zmienic na zmien ilosc produktow lub
					 */
					break;
				case 3: // Wypisywanie wszystkich produktow
				{
					system("cls");
					cout << " Wszystkie zaindeksowane produkty:" << endl;
					apteka->showAllProducts();
					cout << endl;
					system("Pause");
					char isDetails = 'a';
					cout << "Czy chcesz wyswietlic szczegoly jakiegos produktu? T/N :";
					cin >> isDetails;
					if (isDetails == 'T'){
						menuOptions.showProductDetailsOption(apteka, 0);
					}
					break;
				}
				case 4: // Kasowanie produktu
				{
					/*
					 * TODO - wyswietleie produktu czy aby na pewno ten chemy skasowac T/N
					 */
					menuOptions.eraseProductOption(apteka);
					break;
				}
				case 5: //Zmien dane produktu
					/*
					 * TODO - Zmiana danych dla produktu z tablicy poprzez getery i settery
					 */
					break;
				case 6: //Wyswietl pe³ne informacje na temat danego produktu + d³ugi opis,

					menuOptions.showProductDetailsOption(apteka, 1);
					break;
				case 7 :
					/*
					 * TODO - ROZWOJ, NOWE FUNKCJE JAK SKONCZYMY TE WYZEJ
					 */
					break;
				case 8:
					system("cls");
					int quantity;
					cout << " Produkty o niskim stanie. Ponizej :";
					cin >> quantity;
					apteka->showProductsLowQuantity(quantity);
					cout << endl;
					system("Pause");
					break;
				case 9:
					cout << "Zakonczenie dzialnia programu" << endl;
					break;


				default:
					cout << "Niepoprawne dane" << endl;
					break;
			}

		}while(menuChoice != 9);
}

void Menu::showAdminMenu(){
		char choice;
		do
		{

			/*
			 * TODO - CALA NOWA OPJCA FUNKCJI
			 */

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
					//Wyœwietl wszsytkie produkty
					break;
				case '4':
					//Wykasuj product
					break;
				case '5':
					//Zmien dane produktu
					break;
				case '6':
					//Wyswietl pe³ne informacje na temat danego produktu + d³ugi opis,
					break;
				case '7' :
					// UUUU tutaj to jakas wieksza operacja sie szykuje
					break;
				case '8':
					break;
			}
		}while(choice != 'Q' or choice != 'q');
}
