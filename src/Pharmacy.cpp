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
#include "Product.h"
#include "Warehouse.h"
#include "Menu.h"

using namespace std;

int main()
{
	Warehouse apteka;
	apteka.fillWarehouseWithProducts();

	Menu menu;
	menu.showUserMenu(&apteka);
	//menu.showAdminMenu();

	return 0;
}
