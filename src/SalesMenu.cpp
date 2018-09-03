/*
 * SalesMenu.cpp
 *
 *  Created on: 2 wrz 2018
 *      Author: XR
 */

#include "SalesMenu.h"

SalesMenu::SalesMenu(Warehouse * apteka) {
	w_pointer = apteka;
	// TODO Auto-generated constructor stub

}

SalesMenu::~SalesMenu() {
	// TODO Auto-generated destructor stub
}

bool SalesMenu::choiceConfirmation(){
	char confirmation;
	cin >> confirmation;
	if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
		return true;
	}else{
		return false;
	}
}

void SalesMenu::showSalesMenu(){
	char editOptionChoice;

	    do {
	    	system("cls");
	    	cout << "************* WITAMY W MODULE SPRZEDAZY ********************" << endl;
	    	cout << "Wybierz sposob dodawnia produktu: \n" ;
	    	cout << "1) ID \n";
	    	cout << "2) Nazwa \n";
	    	cout << "3) Kategoria + ID \n" ;
	    	cout << "4) Wyœwietl aktualne pozycje na paragonie \n";
	    	cout << "5) Zatwierdz zamowienie i wydrukuj paragon \n";
	    	cout << "Q) Anauluj zamowienie i wyjdz \n ";
	    cout << "\n" ;
	    cin >> editOptionChoice ;
	    cout << "\n";

	    switch (editOptionChoice) {
			case '1':
			{
				SearchResult sr;
				cout << "Wprowadz ID wyszukiwanego produktu" << endl;
				int searchedID;
				cin >> searchedID;
				sr.populateSearchResultsById(w_pointer, searchedID);
				sr.showAllProducts();
				cout << "Czy chcesz dodac ten produkt? T/N ";
				if(choiceConfirmation()){
					int quantity;
					cout << " Podaj liczbe sztuk";
					cin >> quantity;
					/*
					 * TODO - Sprwadzenie czy podana ilosc jest na magazynie - Wazne
					 */
					ReceiptPosition rp(sr.searchResults[0],quantity);
					currentReceipt.addPosition(rp);
					currentReceipt.printPositionsOnReceipt();
					//MenuOptions *mo = new MenuOptions();

					system("Pause");

				}


				break;
			}
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
			{
				currentReceipt.printReceipt();
				system("Pause");
				return;
				break;
			}

			case 'q':
				break;
			default:
				cout << "Niepoprawne dane \n";
				system("Pause");
			}
	    }while((editOptionChoice !='q' || editOptionChoice !='Q'));
}

