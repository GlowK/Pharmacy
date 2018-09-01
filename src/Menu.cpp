/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
 */

#include "Menu.h"


Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::showUserMenu(Warehouse *apteka, User *user){
		int  menuChoice = 0;
		MenuOptions menuOptions;
		cout << "Witamy w apteka management soft" <<endl << endl;

		do
		{
			system("cls");
			cout << "***************Pomy�lnie zalogowano jako ";
			if(user->status == 1)
				cout << "administator ";
			else
				cout << "uzytkownik ";
			cout << user->loginFromFile << "***************" << endl;
			cout << "Dostepne opcje wyboru" << endl;
			cout << "1) Stworz produkt" << endl;
			cout << "2) Przyjmij produkt na magazyn"<< endl;
			cout << "3) Pokaz stan magazynowy "<< endl;
			cout << "4) Usun produkt"<< endl;
			cout << "5) Edycja danych produktow "<< endl;
			cout << "6) Wyswietl szczegolowe dane produktu"<< endl;
			cout << "7) Przeszukaj baze produktow" << endl;
			cout << "8) Pokaz towary o niskim stanie magazynowym" << endl;
			cout << "9) EXIT" << endl;

			if(user->status == 1)
			{
				cout << "10) Dodaj nowego uzytkownika" << endl;
			}
			cout << "Wybierz opcje: ";
			cin >> menuChoice;

			switch (menuChoice)
			{
				case 1://Dodaj nowy produkt do magazynu
					/*
					 * TODO - Dodanie zupelnie nowego produktu
					 */
					apteka->addProduct();
					break;
				case 2: //Dodaj produkty
					/*
					 * TODO - Mozna zmienic na zmien ilosc produktow lub
					 */
				{
					system("cls");
					cout << "Podaj numer produktu do zmiany " << endl;
					int index = 0;
					cin >> index;
					cout << "Podaj ilosc sztuk produktu do zmiany" << endl;
					int quantity;
					cin >> quantity;
					apteka->changeProductQuantity(quantity, index);
					//cout << "dodane" << endl;
					//apteka->showProductsByID(index);
					system("Pause");
					break;
				}
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
					if (isDetails == 'T' or isDetails == 't'){
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
				case 6: //Wyswietl pe�ne informacje na temat danego produktu + d�ugi opis,

					menuOptions.showProductDetailsOption(apteka, 1);
					break;
				case 7 : // Przeszukiwanie bazy produkt�w
					/*
					 * TODO -
					 */
					menuOptions.searchOption(apteka, 1);
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
				case 10:
					if(user->status == 1)
					{
						user->AddNewUser();
					}
					else
					{
						cout << "Niepoprawne dane" << endl;
					}
					break;
				default:
					cout << "Niepoprawne dane" << endl;
					break;
			}

		}while(menuChoice != 9);
}

//void Menu::showAdminMenu(){
//		char choice;
//		do
//		{
//
//			/*
//			 * TODO - CALA NOWA OPJCA FUNKCJI
//			 */
//
//			system("CLS");
//			cout << "Witaj a panelu administracyjnym" <<endl << endl;
//			cout << "1) Dodaj uzytkownika" <<endl;
//			cout << "2) Usun uzytkownika"<<endl;
//			cout << "3) C "<<endl;
//			cout << "4) D"<<endl;
//
//			cout << "Q) EXIT" <<endl;
//			cout << "Wybierz opcje: " << endl;
//			cin.get(choice);
//
//			switch (choice)
//			{
//				case '1': //Dodaj uzytkownika
//					break;
//				case '2': //Usun uzytkownika
//					break;
//				case '3': //
//					break;
//				case '4': //
//					break;
//				case 'Q':
//					break;
//			}
//		}while(choice != 'Q' or choice != 'q');
//}
