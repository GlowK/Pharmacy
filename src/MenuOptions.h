/*
 * MenuOptions.h
 *
 *  Created on: 30 sie 2018
 *      Author: mediaexpert
 */

#ifndef MENUOPTIONS_H_
#define MENUOPTIONS_H_

#include "Warehouse.h"
#include "SearchResult.h"

class MenuOptions {
public:
	MenuOptions();
	virtual ~MenuOptions();
	void eraseProductOption(Warehouse *);
	void showProductDetailsOption(Warehouse *, int);
	void searchOption(Warehouse *, int);
};

#endif /* MENUOPTIONS_H_ */
