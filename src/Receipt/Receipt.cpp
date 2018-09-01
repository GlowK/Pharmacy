/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "Receipt.h"

Receipt::Receipt() : receiptId(recepitCount++){
	time_t now = time(0);
	sellTime = ctime(&now);

}

Receipt::~Receipt() {
	// TODO Auto-generated destructor stub
}


void Receipt::printReceipt(){
	cout << "************************" << endl;
	cout << "      Local Pharmacy    " << endl;
	cout << "       00-840 Krakow    " << endl;
	cout << "        UL. WLOSKA 1    " << endl;
	cout << "     NIP 444-555-66-66  " << endl;
	cout << "************************" << endl;
	cout << "         RECEIPT        " << endl;
	cout << "************************" << endl;
	cout << sellTime;
	cout << "************************" << endl;


}


int Receipt::recepitCount = 0;
