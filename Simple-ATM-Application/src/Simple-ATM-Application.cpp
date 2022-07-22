//============================================================================
// Name        : SimplePOSApplication.cpp
// Author      : ngp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Customer.h"

using namespace std;

Customer customer;
char choice = '\0';

int main()
{
	customer.start_page();
	bool startApp = true;

	while(startApp)
	{
		cin >> choice;
		if(choice == 'A')
		{
			customer.login_user();
			choice = '\0';
		}
		else if(choice == 'B')
		{
			customer.create_acc();
//			choice = '\0';
		}
		else if(choice == 'C')
		{
			startApp = false;
			cout << "Closing application... "<<endl;
		}
		else{
			cout << "Invalid Selection "<<endl;
		}
	//	cout << "Hello World!" << endl; // prints Hello World!
	}
	return 0;
}
