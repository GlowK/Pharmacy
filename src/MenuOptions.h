/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
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

	//SearchFunctions
	void categorySearch(Warehouse *);
	void nameSearch(Warehouse *);
	void priceSearch(Warehouse *);
};

#endif /* MENUOPTIONS_H_ */
