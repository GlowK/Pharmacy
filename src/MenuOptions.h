/*
 * MenuOptions.h
 *
 *  Created on: 30 sie 2018
 *      Author: mediaexpert
 */

#ifndef MENUOPTIONS_H_
#define MENUOPTIONS_H_

#include "Warehouse.h"

class MenuOptions {
public:
	MenuOptions();
	virtual ~MenuOptions();
	void eraseProductOption(Warehouse *);
};

#endif /* MENUOPTIONS_H_ */
