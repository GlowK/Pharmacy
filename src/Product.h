/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Product {
public:
	int product_number;
	string product_name;
	string product_category;
	string product_description;
	string product_prescription_required;
	float product_price;
	int product_quantity;
	//float product_taxation;
	//float product_discount;

public:
	Product();
	Product(int, string, float, int);
	Product(int, string, string, string, float, int, string);
	void display_product(int, int) const;
	void display_table_names(int, int);
	void display_full_information();
	virtual ~Product();

	const string& getProductName() const {
		return product_name;
	}

	int getProductNumber() const {
		return product_number;
	}

	int getProductQuantity() const {
		return product_quantity;
	}

	const string& getProductCategory() const {
		return product_category;
	}

	void setProductQuantity(int changeQuantity)  {
		cout << this->product_quantity << endl;
		this->product_quantity+=changeQuantity;
		cout << product_quantity << endl;
	}

	float getProductPrice() const {
		return product_price;
	}
};

#endif /* PRODUCT_H_ */
