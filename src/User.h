#include <iostream>
#include <string.h>

using namespace std;

#ifndef USER_H_
#define USER_H_

class User
{
public:
	User();
	virtual ~User();

	string name;
	string surname;
	string loginFromFile = "";
	string passwordFromFile = "";
	string enteredLogin;
	string enteredPassword;
	string temporary[5];

	int amountDataToLoad = 5;
	int line;

	bool status = false; //false - uzytkownik, true - administrator
	bool logged = false;

	bool FindUser(string log);
	void DownloadingDataFromFile();
	bool ConverterStringToBool(string txt);
	void AddNewUser();

};

#endif /* USER_H_ */
