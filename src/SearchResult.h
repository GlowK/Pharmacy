/*
 * SearchResult.h
 *
 *  Created on: 31 sie 2018
 *      Author: mediaexpert
 */

#ifndef SEARCHRESULT_H_
#define SEARCHRESULT_H_

#include <string>
#include <vector>
#include <algorithm>

#include "Product.h"
#include "Warehouse.h"

using namespace std;

class SearchResult {
public:
	vector<string> categoryList;
	vector<Product> searchResults;
public:
	SearchResult();
	virtual ~SearchResult();

	void populateCategoryList(Warehouse *);
	void showCategoryList();
	void populateSearchResults(Warehouse *, int);
	// zle tego nie powinno tu byc
	void showProductColumns();
	void showAllProducts();
	int checkNameColumnLength();
	int checkCategoryColumnLength();
};

#endif /* SEARCHRESULT_H_ */
