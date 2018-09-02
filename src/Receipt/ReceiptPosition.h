/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
 */

#ifndef RECEIPT_RECEIPTPOSITION_H_
#define RECEIPT_RECEIPTPOSITION_H_

#include <string>
#include <iomanip>

using namespace std;

class ReceiptPosition {
private:
	string positionName;
	int quantity;
	float price;
	float sum;


public:
	ReceiptPosition();
	ReceiptPosition(string, int, float);
	virtual ~ReceiptPosition();

	float calculateSum();

	const string& getPositionName() const {
		return positionName;
	}

	float getPrice() const {
		return price;
	}

	int getQuantity() const {
		return quantity;
	}

	float getSum() const {
		return sum;
	}
};

#endif /* RECEIPT_RECEIPTPOSITION_H_ */