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

Product::Product(int number, string name, string category, string desc,
				float price, int quantity, string prescription)
{
	product_number = number;
	product_name = name;
	product_category = category;
	product_description = desc;
	product_price = price;
	product_quantity = quantity;
	product_prescription_required = prescription;

}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

void Product::display_product(int length) const{
	/*
	 * TODO - Sprobowac skasowac magic numbers, ustalanie dydanmiczne tresci na podstawie dlugosci
	 */
	cout << setw(5) << left << product_number << "|";
	cout << setw(length) << left << product_name << "|";
	cout << setw(20) << left << product_category << "|";
	cout << fixed << setprecision(2) << setw(10) << left  << product_price << "|";
	cout << setw(10) << left << product_quantity << "|";
	cout << setw(10) << left << product_prescription_required << endl;
}

void Product::display_table_names(int length) {
	/*
	 * TODO - Musi miec parametry jak w funkcji display_product
	 *
	 * TODO - Koniecznie zrobic jakas funkcje ktora wyspiuje odpowiednia ilosc "-"
	 * 			rown¹ sumie wartosci x z setw(x)
	 */
	cout << setw(5) << left << "ID" << "|";
	cout << setw(length) << left << "Nazwa" << "|";
	cout << setw(20) << left << "Kategoria" << "|";
	cout << setw(10) << left << "Cena" << "|";
	cout << setw(10) << left << "Ilosc" << "|";
	cout << setw(10) << left << "W.Recepty" << endl;
	cout << setw(50) << left << "----------------------------------------------------------------------"<<endl;
}

