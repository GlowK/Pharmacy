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
	this->availableProducts.push_back(p);
}

void Warehouse::showAllProducts() const{

	int nameColumnLength = 2;
	for(Product p : this->availableProducts){
		if (p.getProductName().length() > nameColumnLength){
			nameColumnLength = p.getProductName().length();
		}
	}
	Product *temp = new Product(1, "temp", 1,1);
		temp->display_table_names(nameColumnLength+1);
		delete temp;
	for(Product p : this->availableProducts){
		p.display_product(nameColumnLength+1);
	}
}

void Warehouse::fillWarehouseWithProducts(){

	fstream inputfile;
	string line;
	inputfile.open("C:/Users/mediaexpert/eclipse-workspace/Pharmacy/src/test.csv", ios::in);

	while(getline(inputfile,line)){
		istringstream iss(line);
		string token;
		while(getline(iss, token, ';')){
			int id = atoi(token.c_str());

			getline(iss, token, ';');
			char *name = new char[token.length() + 1];
			strcpy(name, token.c_str());

			getline(iss, token, ';');
			float price = atof(token.c_str());

			getline(iss, token, ';');
			int quantity = atoi(token.c_str());
			Product *temp = new Product(id, name, price,quantity);

			this->availableProducts.push_back(*temp);
			delete temp;
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
