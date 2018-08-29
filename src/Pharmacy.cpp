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
//	Product *dupa = new Product(1, "Nazwa", 12.3,  4);
//		dupa->display_table_names();
//	for(int i=0; i<=10; i++ ){
//		dupa->display_product();
//	}

	Warehouse apteka;

	//apteka.addProduct(*dupa);
	//apteka.addProduct(*dupa);
	//apteka.addProduct(*dupa);

	//apteka.showAllProducts();

	apteka.fillWarehouseWithProducts();
	//apteka.showAllProducts();

	Menu menu;
	menu.showUserMenu(&apteka);
	//menu.showAdminMenu();

//	cout << endl;
//	int x=10;
//	printf("|%-5d|\n|%+5d|\n|% d|\n|% 5d|\n|%05d|\n\n", x,x,x,x,x);
//	double y=10;
//	printf("|%-15f|\n|%+15f|\n|% f|\n|% 15f|\n|%015f|\n\n", y,y,y,y,y);
//	char ch[4] = "txt";
//	printf("|%-5s|\n|%+5s|\n|% s|\n|% 5s|\n|%05s|\n\n", ch,ch,ch,ch,ch);

	return 0;
//	delete dupa;
}
