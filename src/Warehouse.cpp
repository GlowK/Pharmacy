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

void Warehouse::addProduct(){
	/*
	 * Funkcja dodaj�ca nowy produkt na koniec vectora, moze sie
	 * przydac przy dodawaniu zupelnie nowego produktu
	 */
	int index, quantity;
	float price;
	string name;
	//cout << "Podaj id (tymczasowe) " << endl ;
	//cin >> index;
	index = this->availableProducts.back().product_number + 1;
	cout << "Podaj nazwe .. " << endl;
	cin >> name;
	cout << "Podaj cene ...  " << endl;
	cin >> price;
	cout << "Podaj Ilosc sztuk ... " << endl;
	cin >> quantity ;
	Product *p_temp = new Product(index, name, price, quantity);
	this->availableProducts.push_back(*p_temp);
	delete p_temp; //Dopisany delete - Kamil
}


int  Warehouse::checkNameColumnLength(){
	int unsigned nameColumnLength = 2;
		for(Product p : this->availableProducts){
			if (p.getProductName().length() > nameColumnLength){
				nameColumnLength = p.getProductName().length();
			}
		}
	return nameColumnLength+1;
}

int Warehouse::checkCategoryColumnLength(){
	int unsigned categoryColumnLenght = 2;
		for(Product p : this->availableProducts){
			if (p.getProductCategory().length() > categoryColumnLenght){
				categoryColumnLenght = p.getProductCategory().length();
			}
		}
	return categoryColumnLenght+1;
}

void Warehouse::showProductColumns(){
	Product *temp = new Product(1, "temp", 1,1);
	temp->display_table_names(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	delete temp;
}

void Warehouse::showAllProducts(){
	this->showProductColumns();

	for(Product p : this->availableProducts){
		p.display_product(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	}
}


void Warehouse::showProductsLowQuantity(int quantity){
	this->showProductColumns();
	for(Product p : this->availableProducts){
		if(p.getProductQuantity() <= quantity){
			p.display_product(this->checkNameColumnLength(), this->checkCategoryColumnLength());
		}
	}
}





void Warehouse::fillWarehouseWithProducts(){
	/*
	 * TODO - Rozbudowac razem jak bedzie rosl produkt
	 */
	fstream inputfile;
	string line;
	inputfile.open("../src/test3.csv", ios::in);

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


void Warehouse::eraseElementById(int id){
	int i = 0;
	for(Product p : this->availableProducts){
		if(p.getProductNumber() == id){
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

void Warehouse::eraseElementByCategory(string category){
	int i = 0;
	for(Product p : this->availableProducts){
			if(p.getProductCategory() == category){
				availableProducts.erase(availableProducts.begin()+i);
				this->eraseElementByCategory(category);
				break;
			}else{
				i++;
			}
	}
}

void Warehouse::showProductDetailsThroughIndex(int index){
	for(Product p : this->availableProducts){
		if(p.getProductNumber() == index){
			p.display_full_information();
			}
	}
}

void Warehouse::changeProductQuantity(int quantity, int index){
	this->showProductColumns();

	for(Product p : this->availableProducts){
		if(p.getProductNumber() == index){
			cout << "ustawiam nowa wartosc ..." << endl;
			p.setProductQuantity(quantity);
			cout << endl;
			cout << p.getProductQuantity() << endl ;
		}
		else
			cout << "nie ustawiam nowej wartosc " << endl;
	}
}

void Warehouse::showProductsByID(int index){
	this->showProductColumns();

	for(Product p : this->availableProducts){
		if(p.getProductNumber() == index){
			p.display_product(this->checkNameColumnLength(), this->checkCategoryColumnLength());;
				}

	}
}
