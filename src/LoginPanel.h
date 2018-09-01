/*
 * LoginPanel.h
 *
 *  Created on: 1 wrz 2018
 *      Author: XR
 */

#ifndef LOGINPANEL_H_
#define LOGINPANEL_H_

#include <iostream>
#include <stdlib.h>
#include <process.h>
#include <cstdio>
#include <fstream>
#include "User.h"


using namespace std;

class LoginPanel {
public:
	LoginPanel();
	virtual ~LoginPanel();
	User ShowLoggingPanel(User);
	bool IfExist();
};

#endif /* LOGINPANEL_H_ */
