/*
 * Product.cpp
 *
 *  Created on: 29 sie 2018
 *      Author: mediaexpert
 */

#include "Product.h"

//Product::Product(){

//}

Product::Product(int number, string name, float price, int quantity) {
	product_number = number;
	product_name = name;
	product_price = price;
	product_quantity = quantity;
	// TODO Auto-generated constructor stub

}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

void Product::display_product(int length) const{
	cout << setw(5) << left << product_number << "|";
	cout << setw(length) << left << product_name << "|";
	cout << fixed << setprecision(2) << setw(10) << left  << product_price << "|";
	cout << setw(10) << left << product_quantity << endl;
}

void Product::display_table_names(int length) {
	cout << setw(5) << left << "ID" << "|";
	cout << setw(length) << left << "Nazwa" << "|";
	cout << setw(10) << left << "Cena" << "|";
	cout << setw(10) << left << "Ilosc" << endl;
	cout << setw(50) << left << "----------------------------------------"<<endl;
}

