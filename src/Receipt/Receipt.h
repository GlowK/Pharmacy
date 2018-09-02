/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
 */

#ifndef RECEIPT_RECEIPT_H_
#define RECEIPT_RECEIPT_H_

#include <vector>
#include <string>
#include <ctime>
#include <iostream>

#include "../Receipt/ReceiptPosition.h"

using namespace std;

class Receipt {
private:
	vector<ReceiptPosition> positionsOnReceipt;
	char * sellTime;
	static int recepitCount;
	const int receiptId;

public:
	Receipt();
	virtual ~Receipt();
	void printReceipt();
};

#endif /* RECEIPT_RECEIPT_H_ */
