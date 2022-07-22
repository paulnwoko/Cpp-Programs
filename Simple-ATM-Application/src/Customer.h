/*
 * account.h
 *
 *  Created on: Jan 31, 2022
 *      Author: darlington
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

class Customer{
private:
	unsigned int acc_num = 10000;
	bool login_status = false;
	unsigned int account_index = 0;//holds the position of where an account is found while searching

public:
	char choice = '\0';
	Customer();// constructor

	bool check_acc(std::string id);
	void login_user();
	void StayLoggedIn(); //switches to logi
	void start_page();
	void create_acc();	//creates an account
	void delete_acc(unsigned int id);	//remove account
	void deposit_amt(unsigned int amount);	//deposit amount
	void withdraw_amnt(unsigned int amount);	//withdraw money
	void checkbalance();
	void homepage();
};

#endif /* CUSTOMER_H_ */
