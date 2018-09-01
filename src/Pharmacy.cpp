//============================================================================
// Name        : Pharmacy.cpp
// Author      : Kamil Glowinski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <string>
#include <process.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "Product.h"
#include "Warehouse.h"
#include "Menu.h"
#include "User.h"

using namespace std;

fstream plik;
char a;

User u1;
bool IfExist()//funkcja sprawdza czy plik istnieje
{
	plik.open("src/dane.txt", ios::in);

	if(plik.good())
		return true;
	else
		return false;

	plik.close();
}

void ShowLoggingPanel()
{
	start:

	if(IfExist() == true)
		{
			//jeœli znajdzie plik z danymi do logowania
			cout << "Proszê wprowadzic dane do logowania. \nLogin: ";
			cin >> u1.enteredLogin;
			cout << "Haslo: ";
			cin >> u1.enteredPassword;

			if(u1.FindUser(u1.enteredLogin) == true)
			{
				//jeœli znajdzie u¿ytkownika o takim loginie
				u1.DownloadingDataFromFile(); //pobieramy dane z pliku (haslo, imie, nazwisko)
				cout << "Znaleziono uzytkownika o loginie " << u1.loginFromFile << endl;
				if(u1.enteredPassword == u1.passwordFromFile)
				{
					cout << "Pomyœlnie zalogowano jako ";
					if(u1.status == true)
					{
						cout << "administrator";
					}
					else
					{
						cout << "uzytkownik";
					}

					cout << " " << u1.name << " " << u1.surname << endl;
					u1.logged = true;
				}
				else
				{
					cout << "B³êdne has³o!" << endl;
				}

			}
			else
			{
				//je¿eli nie znajdzie u¿ytkownika o takim loginie
				cout << "Brak u¿ytkownika o loginie: " << u1.enteredLogin << endl;
				cout << "Czy chcesz sprobowac zalogowac siê ponownie? (y/n)" << endl;
				cin >> a;

				if(a == 'y')
					goto start;
				if(a =='n')
					system("pause");
			}

		}
		else
		{
			//jeœli nie znajdzie pliku z danymi do logowania
			cout << "Nie znaleziono pliku. Logowanie jest niemo¿liwe!" << endl;
			cout << "Czy chcesz dodac nowego uzytkownika aby utworzyc plik?(y/n)" << endl;
			cin >> a;
			if(a == 'y' || a == 'Y')
			{
				u1.AddNewUser();
				system("cls");
				goto start;
			}
		}
}


int main()
{
	ShowLoggingPanel();
	if(u1.logged == true)
	{
		Warehouse apteka;
		apteka.fillWarehouseWithProducts();

		Menu menu;
		menu.showUserMenu(&apteka, &u1);
		//menu.showAdminMenu();
	}
	return 0;
}
