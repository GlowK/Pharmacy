/*
 * Menu.h
 *
 *  Created on: 29 sie 2018
 *      Author: mediaexpert
 */

#ifndef MENU_H_
#define MENU_H_
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "Warehouse.h"

using namespace std;

class Menu {
public:
	Menu();
	virtual ~Menu();
	void showUserMenu(Warehouse * );
	void showAdminMenu();
};

#endif /* MENU_H_ */
