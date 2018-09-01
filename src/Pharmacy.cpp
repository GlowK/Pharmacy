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
#include "LoginPanel.h"

using namespace std;


int main()
{
	LoginPanel loginPanel;
	User u1;

	if(loginPanel.ShowLoggingPanel(u1).logged == true)
	{
		Warehouse apteka;
		apteka.fillWarehouseWithProducts();

		Menu menu;
		menu.showUserMenu(&apteka, &u1);
		//menu.showAdminMenu();
	}
	return 0;
}
