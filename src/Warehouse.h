/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_


#include <vector>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include "Product.h"

class Warehouse {
public:
	vector<Product> availableProducts;

public:
	Warehouse();
	virtual ~Warehouse();
	void addProduct();
	void showAllProducts();
	void showProductsLowQuantity(int);
	void fillWarehouseWithProducts();
	void eraseElementById(int);
	void eraseElementByName(string);
	void eraseElementByCategory(string);
	int checkNameColumnLength();
	int checkCategoryColumnLength();
	void showProductColumns();
	void showProductDetailsThroughIndex(int);
	void changeProductQuantity(int, int); //Bartosz
	void showProductsByID(int); //Bartosz
};

#endif /* WAREHOUSE_H_ */
