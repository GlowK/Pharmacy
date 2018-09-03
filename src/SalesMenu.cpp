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
	    	cout << "Q) Anuluj zamowienie i wyjdz \n ";
	    cout << "\n" ;
	    cout << "Wprowadz wartosc: ";
	    cin >> editOptionChoice ;

	    switch (editOptionChoice) {
			case '1':
			{
				SearchResult sr;
				IDCheck(&sr);
				if(choiceConfirmation()){
					this->quantityCheck(&sr);
				}
				system("Pause");
				break;
			}
			case '2':
				break;
			case '3':
				break;
			case '4':
			{
				system("cls");
				cout << "Pozycje na aktualnym paragonie :" << endl;
				currentReceipt.printPositionsOnReceipt();
				cout << endl << "Suma: " << this->currentReceipt.getSum() << "zl" <<endl;
				system("Pause");
				break;
			}
			case '5':
			{
				currentReceipt.printReceipt();
				w_pointer->addReceiptToReceiptArchive(currentReceipt);
				system("Pause");
				editOptionChoice = 'q';
				break;
			}

			case 'q':
				break;
			default:
				cout << "Niepoprawne dane \n";
				system("Pause");
			}
	    }while(editOptionChoice !='q' && editOptionChoice !='Q');
}

void SalesMenu::quantityCheck(SearchResult *sr){
	int quantity;
	cout << "Podaj liczbe sztuk: ";
	cin >> quantity;
	if(sr->searchResults[0].getProductQuantity() <quantity ){
		cout << "Wymagana ilosc nie znajduje sie na magazynie. " << "Max: " << sr->searchResults[0].getProductQuantity() << endl;
		quantityCheck(sr);
		return;
	}else if( quantity < 0){
		cout << "Wartosc ujemna nie jest przyjmowana " << "Min: 0 " <<  "Max: " << sr->searchResults[0].getProductQuantity() << endl;
		quantityCheck(sr);
		return;
	}else{
		ReceiptPosition rp(sr->searchResults[0],quantity);
		currentReceipt.addPosition(rp);
		currentReceipt.printPositionsOnReceipt();
		MenuOptions *mo = new MenuOptions();
		mo->editQuantitySubstract(w_pointer,quantity,sr->searchResults[0].getProductNumber());
		delete mo;
		return;
	}
}

void SalesMenu::IDCheck(SearchResult * sr){
	cout << "Wprowadz ID wyszukiwanego produktu: ";
	int searchedID;
	cin >> searchedID;
	sr->populateSearchResultsById(this->w_pointer, searchedID);
	if(sr->searchResults.empty()){
		cout << "Przepraszamy. Nie ma takiego produktu w bazie" << endl;
		cout << "Czy chcesz wyszukac ponownie? T/N ";
		if(choiceConfirmation()){
			IDCheck(sr);
			return;
		}
		return;
	}
	sr->showAllProducts();
	cout << "\nCzy chcesz dodac ten produkt? T/N ";
}

