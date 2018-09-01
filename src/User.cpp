#include "User.h"
#include <iostream>
#include <fstream>


fstream plik_;
int miejsce;

User::User()
{
	line = 0;

}

User::~User() {
	// TODO Auto-generated destructor stub
}

bool User::FindUser(string log)
{
	//sprawdzanie czy uzytkownik o takim loginie istnieje
	string tmp;
	int a;
	line = 0;
	plik_.open("src/dane.txt", ios::in);

	while(!plik_.eof())
	{
		line++;
		loginFromFile = "";
		tmp = "";
		getline(plik_, tmp);
		a = tmp.find("|");
		for(int i = 0; i < a; i++)
		{
			loginFromFile += tmp[i];
		}

		if(loginFromFile == log)
		{
			plik_.close();
			return true;
			break;
		}

		if(plik_.eof() == true)
		{
			plik_.close();
			return false;
		}
	}

	plik_.close();
}

bool User::ConverterStringToBool(string txt)
{
	if(txt == "1" || txt == "true")
		return true;
	else
		return false;
}

void User::DownloadingDataFromFile()
{
	plik_.close();
	string tmp;
	int a;
	plik_.open("src/dane.txt", ios::in);


	for(int i = 0; i < line; i++)
	{
		tmp = "";
		getline( plik_, tmp );
	}


	for(int i = 0; i < amountDataToLoad; i++)
	{
		switch(i)
		{
		case 0:
			a = tmp.find("|");
			tmp.erase(0, loginFromFile.length()+1);
			break;
		case 1:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				passwordFromFile += tmp[j];
			}
			tmp.erase(0, passwordFromFile.length()+1);
			break;
		case 2:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				name += tmp[j];
			}
			tmp.erase(0, name.length()+1);
			break;
		case 3:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				surname += tmp[j];
			}
			tmp.erase(0, surname.length()+1);
			break;
		case 4:
			status = ConverterStringToBool(tmp);
			break;
		default:
			cout << "Error!" << endl;
			break;
		}
	}

	plik_.close();
}

void User::AddNewUser()
{
	string tmp;
	plik_.open("src/dane.txt", ios::app);

	cout << "Dodaj nowego uzytkownika!" << endl;
		//Login:
		cout << "Login: ";
		cin >> temporary[0];

		/*if(FindUser(temporary[0]) == true)
		{
			cout << "Taki uzytkownik ju¿ istnieje, wprowadz inny login!" << endl;
					goto Login;
		}*/
		password:
		cout << "Haslo: ";
		cin >> temporary[1];
		if(temporary[1].length() < 3 ||temporary[1].length() > 32)
		{
			cout << "Haslo musi zawierac od 3 do 32 znaków!" << endl;
			goto password;
		}
		cout << "Imie: ";
		cin >> temporary[2];
		cout << "Nazwisko: ";
		cin >> temporary[3];
		//status:
		cout << "Status (1 jeœli administator lub 0 jeœli u¿ytkownik): ";
		cin >> temporary[4];
		/*if(temporary[4] != "1" || temporary[4] != "0")
		{
			cout << "Status musi miec wartosc 1 lub 0!" << endl;
			goto status;
		}*/
	tmp = temporary[0] + "|" + temporary[1] + "|" + temporary[2] + "|" + temporary[3] + "|" + temporary[4];
	plik_ << tmp << endl;
	cout << "Poprawnie zapisano dane!" << endl;
	plik_.close();
}
