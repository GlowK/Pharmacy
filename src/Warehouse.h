/*
 * Warehouse.h
 *
 *  Created on: 29 sie 2018
 *      Author: mediaexpert
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
	void addProduct(Product);
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
};

#endif /* WAREHOUSE_H_ */
