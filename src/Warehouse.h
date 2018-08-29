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

#include "Product.h"

class Warehouse {
public:
	vector<Product> availableProducts;

public:
	Warehouse();
	virtual ~Warehouse();
	void addProduct(Product);
	void showAllProducts() const;
	void fillWarehouseWithProducts();
	void eraseElementByPosition(int);

};

#endif /* WAREHOUSE_H_ */
