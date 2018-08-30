/*
 * Warehouse.cpp
 *
 *  Created on: 29 sie 2018
 *      Author: mediaexpert
 */

#include "Warehouse.h"

Warehouse::Warehouse() {
	// TODO Auto-generated constructor stub

}

Warehouse::~Warehouse() {
	// TODO Auto-generated destructor stub
}

void Warehouse::addProduct(Product p){
	/*
	 * Funkcja dodaj¹ca nowy produkt na koniec vectora, moze sie
	 * przydac przy dodawaniu zupelnie nowego produktu
	 */
	this->availableProducts.push_back(p);
}


int  Warehouse::checkNameColumnLength(){
	int nameColumnLength = 2;
		for(Product p : this->availableProducts){
			if (p.getProductName().length() > nameColumnLength){
				nameColumnLength = p.getProductName().length();
			}
		}
	return nameColumnLength+1;
}

void Warehouse::showProductColumns(){
	Product *temp = new Product(1, "temp", 1,1);
	temp->display_table_names(this->checkNameColumnLength());
	delete temp;
}

void Warehouse::showAllProducts(){
	this->showProductColumns();

	for(Product p : this->availableProducts){
		p.display_product(this->checkNameColumnLength());
	}
}


void Warehouse::showProductsLowQuantity(int quantity){
	this->showProductColumns();
	for(Product p : this->availableProducts){
		if(p.getProductQuantity() <= quantity){
			p.display_product(this->checkNameColumnLength());
		}
	}
}





void Warehouse::fillWarehouseWithProducts(){
	/*
	 * TODO - Rozbudowac razem jak bedzie rosl produkt
	 */
	fstream inputfile;
	string line;
	inputfile.open("../src/test2.csv", ios::in);

	while(getline(inputfile,line)){
		istringstream iss(line);
		string token;
		while(getline(iss, token, ';')){
			int id = atoi(token.c_str());

			getline(iss, token, ';');
			char *name = new char[token.length() + 1];
			strcpy(name, token.c_str());

			getline(iss, token, ';');
			char *category = new char[token.length() + 1];
			strcpy(category, token.c_str());

			getline(iss, token, ';');
			char *desc = new char[token.length() + 1];
			strcpy(desc, token.c_str());

			getline(iss, token, ';');
			float price = atof(token.c_str());

			getline(iss, token, ';');
			int quantity = atoi(token.c_str());

			getline(iss, token, ';');
			char *prescription = new char[token.length() + 1];
			strcpy(prescription, token.c_str());

			Product *temp = new Product(id, name, category, desc, price, quantity, prescription);

			this->availableProducts.push_back(*temp);
			delete temp;
			delete name;
			delete category;
			delete desc;
			delete prescription;
		}


	}
}


void Warehouse::eraseElementByPosition(int position){
	int i = 0;
	for(Product p : this->availableProducts){
		if(p.getProductNumber() == position){
			availableProducts.erase(availableProducts.begin()+i);
		}else{
			i++;
		}
	}
}


void Warehouse::eraseElementByName(string name){
	int i = 0;
	for(Product p : this->availableProducts){
			if(p.getProductName() == name){
				availableProducts.erase(availableProducts.begin()+i);
				this->eraseElementByName(name);
				break;
			}else{
				i++;
			}
	}
}
