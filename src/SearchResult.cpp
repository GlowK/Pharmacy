/*
 * SearchResult.cpp
 *
 *  Created on: 31 sie 2018
 *      Author: mediaexpert
 */

#include "SearchResult.h"

SearchResult::SearchResult() {
	// TODO Auto-generated constructor stub

}

SearchResult::~SearchResult() {
	// TODO Auto-generated destructor stub
}

struct compare{
	string key;
	compare(string const &i): key(i){}

	bool operator()(string const&i){
		return (i == key);
	}
};

void SearchResult::populateCategoryList(Warehouse * apteka){
	for(Product p : apteka->availableProducts){
		string temp = p.getProductCategory();
		if( this->categoryList.empty()){
			this->categoryList.push_back(temp);
		}else{
			if(any_of(this->categoryList.begin(), this->categoryList.end(), compare(temp))){
				// Nic nie robi
			}else{
				this->categoryList.push_back(temp);
			}
		}
	}
}

void SearchResult::showCategoryList(){
	int i = 0;
	for(string s : this->categoryList){
		cout << i << " " << s << endl;
		i++;
	}
}


void SearchResult::populateSearchResults(Warehouse * apteka, int categoryNumber){

	string catName = this->categoryList.at(categoryNumber);
	for(Product p : apteka->availableProducts){
		if(p.getProductCategory() == catName){
			this->searchResults.push_back(p);
		}
	}
}

void SearchResult::showProductColumns(){
	Product *temp = new Product(1, "temp", 1,1);
	temp->display_table_names(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	delete temp;
}

void SearchResult::showAllProducts(){
	this->showProductColumns();

	for(Product p : this->searchResults){
		p.display_product(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	}
}

int  SearchResult::checkNameColumnLength(){
	int unsigned nameColumnLength = 2;
		for(Product p : this->searchResults){
			if (p.getProductName().length() > nameColumnLength){
				nameColumnLength = p.getProductName().length();
			}
		}
	return nameColumnLength+1;
}

int SearchResult::checkCategoryColumnLength(){
	int unsigned categoryColumnLenght = 2;
		for(Product p : this->searchResults){
			if (p.getProductCategory().length() > categoryColumnLenght){
				categoryColumnLenght = p.getProductCategory().length();
			}
		}
	return categoryColumnLenght+1;
}

