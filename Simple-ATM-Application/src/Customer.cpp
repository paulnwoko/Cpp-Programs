/*
 * account.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: darlington
 */

#include "Customer.h"
#include <iostream>
#include <vector>

using namespace std;

Customer::Customer(){
	// TODO Auto-generated constructor stub
}

	struct UserAccount{
		string name = "\0";
		string id = "\0";
		unsigned int balance = 0;
	};
	UserAccount account;

	//create a list of type UserAccount
	vector<UserAccount> customerList = {};

	//this checks whether an account exists
	bool Customer::check_acc(string acc_id)
	{
		bool acc_exist = false;		//flag to detect if account exists

		for(unsigned int i = 0; i < customerList.size(); i++)
		{
			account = customerList[i];
			if(account.id == acc_id)
			{
				account_index = i;
				acc_exist = true;	//account exist
				if(acc_exist == true) break;
			}
			else{
				acc_exist = false; //account doesnt exist
			}
		}

		return acc_exist;
	}

	void Customer::login_user(){
		int id;

		cout << "*******************************"<< endl;
		cout << "LOGIN TO YOUR ACCOUNT"<<endl;
		cout << "*******************************"<< endl<<endl;

		cout << "Enter your id : "<<endl<<endl;
		cin >>id;
		//check if acc exist
		if(check_acc(to_string(id)) == true){
			cout <<"account exists!!"<<endl;
			cout <<"WELCOME " + account.name <<endl;
			cout <<"Account ID : " + to_string(id)<<endl;
			cout <<"Balance    : " + to_string(account.balance)<<endl;// + account.balance;

			StayLoggedIn();
		}
		else{
			cout << "\nThis account ID does not exist\nPlease create an account"<<endl<<endl;
			start_page();// return to start page
		}
	}

	void Customer::StayLoggedIn(){
		login_status = true;
		while(login_status == true){
			homepage();
		}
	}

	void Customer::start_page(){
		cout << "(A) login "<<endl;
		cout << "(B) create Account "<<endl;
		cout << "(C) Close Application "<<endl<<endl;
	}

	void Customer::homepage(){
		cout << "\nAccount options "<<endl;
		cout << "(A) check balance "<<endl;
		cout << "(B) Withdraw "<<endl;
		cout << "(C) Deposit "<<endl;
		cout << "(D) Exit "<<endl<<endl;

		cin >>choice;

		if(choice == 'A'){
			checkbalance();
		}
		else if(choice == 'B'){
			unsigned int amount = 0;
			cout << "Enter amount to withdraw "<<endl;
			cin >>amount;
			withdraw_amnt(amount);
		}
		else if(choice == 'C'){
			unsigned int amount = 0;
			cout << "Enter amount to deposit "<<endl;
			cin >>amount;
			deposit_amt(amount);
		}
		else if(choice == 'D'){
			login_status = false;
			cout << "Logged out\n"<<endl;
			start_page();
		}
		else{
			cout << "Invalid Selection "<<endl;
		}
	}

	//creates an account
	void Customer::create_acc(){
		cout << "*******************************"<< endl;
		cout << "CREATE NEW ACCOUNT"<<endl;
		cout << "*******************************"<< endl;

		cout << "enter your name"<<endl;
		cin >>account.name;

		cout << "enter ammount"<<endl;
		cin >>account.balance;

		//generate customer id
		account.id = to_string(acc_num);

		//save account to customer db
		customerList.insert(customerList.end(),account); //appends the struct to the end of the vector
//		customerList.push_back(account); //appends the struct to the end of the vector

		cout << "Congrats " + account.name + "!. Your Account has been created\n" + "Your Account ID is " + account.id << endl;
		cout << "Your Account balance is N" + to_string(account.balance) << endl <<endl;

		acc_num++;

//		login_status = true;
		StayLoggedIn();//logs in user immediately the account is created

	}

	//remove account
	void Customer::delete_acc(unsigned int id){
		//implementation: remove struct with associated with the acc from list

	}

	void Customer::deposit_amt(unsigned int amount){
		account.balance += amount;
		cout << "You deposited " + to_string(amount)<<endl;
		cout << "New Balance : N" + to_string(account.balance)<<endl<<endl;
		customerList[account_index] = account; //Updates the vector database
	}

	void Customer::withdraw_amnt(unsigned int amount){
		if(amount < account.balance){
			account.balance -= amount;
			cout << 'N' + to_string(amount) + " withdrawn \nNew Balance: " + to_string(account.balance)<<endl<<endl;
			customerList.at(account_index) = account; //Updates the vector database
		}
		else{
			cout << "Insufficient fund! "<<endl;
		}
	}

	void Customer::checkbalance(){
		cout << "Your Balance is N" + to_string(account.balance)<<endl;
	}

