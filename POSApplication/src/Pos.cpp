/*
 * Pos.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: darlington
 */

#include "Pos.h"
#include <iostream>

namespace std {
namespace literals {
namespace string_literals {

Pos::Pos() {
	// TODO Auto-generated constructor stub
	customerId = 0;
	MenuItem[0].name  = "fried fish     "; MenuItem[0].price = 1000;
	MenuItem[1].name  = "fried chicken  "; MenuItem[1].price = 2500;
	MenuItem[2].name  = "stew rice      "; MenuItem[2].price = 700;
	MenuItem[3].name  = "fried rice     "; MenuItem[3].price = 1000;
	MenuItem[4].name  = "jellof rice    "; MenuItem[4].price = 900;
	MenuItem[5].name  = "vegetable soup "; MenuItem[5].price = 800;
	MenuItem[6].name  = "pepper soup    "; MenuItem[6].price = 500;
	MenuItem[7].name  = "egusi soup     "; MenuItem[7].price = 500;
	MenuItem[8].name  = "ogbono soup    "; MenuItem[8].price = 800;
	MenuItem[9].name =  "okra soup      "; MenuItem[9].price = 600;
	MenuItem[10].name = "bitterleaf soup"; MenuItem[10].price = 700;
	MenuItem[11].name = "pounded yam    "; MenuItem[11].price = 350;
	MenuItem[12].name = "semovita       "; MenuItem[12].price = 350;
	MenuItem[13].name = "eba            "; MenuItem[13].price = 300;
	MenuItem[14].name = "fufu           "; MenuItem[14].price = 500;
	MenuItem[15].name = "moi moi        "; MenuItem[15].price = 200;
	MenuItem[16].name = "yam & bean     "; MenuItem[16].price = 750;
	MenuItem[17].name = "yam poridge    "; MenuItem[17].price = 500;
	MenuItem[18].name = "beans          "; MenuItem[18].price = 500;
	MenuItem[19].name = "egg sauce      "; MenuItem[19].price = 400;
	MenuItem[20].name = "fried plantain "; MenuItem[20].price = 300;
	MenuItem[21].name = "abacha         "; MenuItem[21].price = 500;
	MenuItem[22].name = "pineapple juice"; MenuItem[22].price = 300;
	MenuItem[23].name = "orange juice   "; MenuItem[23].price = 300;
	MenuItem[24].name = "fruit salad    "; MenuItem[24].price = 700;
	MenuItem[25].name = "red wine       "; MenuItem[25].price = 1200;

}

Pos::~Pos() {
	// TODO Auto-generated destructor stub
}

void Pos::homepage(){
	cout<<"Welcome. enter a name to start shopping"<<endl;
	cin >>shopper.name;

	system("CLS");//clears terminal and starts a new page

	cout<<"Welcome " + shopper.name<<endl;
	cout<<"*************************************************************\n";
	cout<<"                	FOOD MENU\n";
	cout<<"Enter food label to order a meal. for more than one meal on \n";
	cout<<"the menu, enter food labels in series.\n";
	cout<<"*************************************************************\n";
//hnt store this data in a list or string
	cout<<"[1] FRIED FISH   ";cout<<"[2] FRIED CHIKEN         ";cout<<"[3] RICE & STEW \n";
	cout<<"[4] FRIED RICE   ";cout<<"[5] JELLOF RICE          ";cout<<"[6] VEGETABLE SOUP \n";
	cout<<"[7] PEPPER SOUP  ";cout<<"[8] EGUSI SOUP           ";cout<<"[9] OGBONO SOUP \n";
	cout<<"[10] OKRA SOUP   ";cout<<"[11] BITER LEAF SOUP     ";cout<<"[12] POUNDED YAM \n";
	cout<<"[13] SEMOVITA    ";cout<<"[14] EBA                 ";cout<<"[15] FUFU \n";
	cout<<"[16] MOI MOI     ";cout<<"[17] YAM & BEANS PORIDGE ";cout<<"[18] YAM PORIDGE \n";
	cout<<"[19] BEANS       ";cout<<"[20] YAM WITH EGG SAUCE  ";cout<<"[21] FRIED PLANTAIN \n";
	cout<<"[22] ABACHA      ";cout<<"[23] PINEAPPLE JUICE     ";cout<<"[24] ORANGE JUICE \n";
	cout<<"[25] FRUIT SALAD ";cout<<"[26] RED WINE            ";cout<<"[0] CHECKOUT \n";
	//cout<<"[27] VIEW CART   ";cout<<"[28] PRINT RECIEPT       ";cout<<"[29] PAY "<<endl;
	addItems();
}

void Pos::pay(){
	//read card detals
	cout<<"checking card...\n";
//	sleep(3);
	//connect to customer bank
	cout<<"connecting to bank...\n";
//	sleep(4);
	//credit the seller and debit buyer
	cout<<"processing payment...\n";
//	sleep(4);
	cout<<"done\n";
}

void Pos::addItems(){
	unsigned int total_qty = 0;
	bool _is_Item_Present = false;

	while(shopper.choice != 0)
	{
		shopper.choice = -10;

		cin>>shopper.choice;

		if(!isalpha(shopper.choice))
		{
			if((shopper.choice > 0) & (shopper.choice <= MenuItem.size())){
				//check if already added to cart increment the qty and compute subtotal price
				if(_is_Item_Present == true){
					for(uint16_t i = 0; i <= cart.size(); i++){
						if(MenuItem[shopper.choice].name == cart[i].name){
							cart[i].quanty++;
							cart[i].price = MenuItem[shopper.choice].price * cart[i].quanty;

							cout<<MenuItem[shopper.choice].name + " updated ";
							_is_Item_Present = false;
						}
					}
				}
				else{
					//else add it as a new item
					//adds the selected food to cart
					cart.insert(cart.end(), MenuItem[shopper.choice-1]);

					cout<<"[" + to_string(shopper.choice) + "]";
					cout<<MenuItem[shopper.choice-1].name + " added to cart ";
					total_qty++;
					_is_Item_Present = true;
				}
			}
			else{
				if(shopper.choice == 0){
					cout<<"***********End Of Shopping***********\n";
					//proceed to checkout
					checkout(total_qty);
				}
				else cout<<"invalid selection";
			}
		}
	}
}

void Pos::checkout(uint8_t qty){
//	system("clear");//clears terminal
	system("CLS");//clears terminal
	cout<<"\nchecking out...\n\n";
	ViewCart(qty);
}
void Pos::removeItem(){
	;
}
void Pos::ViewCart(uint8_t total_qty){
//loop through the cart string and print corresponding item
//the cart holds the food label
	uint16_t total_price = 0;
	cout<<"#########################################\n";
	cout<<"               SHOPING RECIEPT\n";
	cout<<"#########################################\n";
	cout<<"BUYER   : " + shopper.name + "\n";
	cout<<"DATE    : 16/02/2022\n";
	cout<<"CASHIER : NGP\n";

	cout<<"****************************************\n";
	cout<<"ITEMs               QTY            PRICE\n";
	cout<<"****************************************\n";
	for(unsigned int i=0; i <= cart.size(); i++){
		cout<<cart[i].name + "      " + to_string(cart[i+1].quanty) + "             " + to_string(cart[i+1].price)<<endl;
		total_price += cart[i+1].price;
	}
	cout<<"*****************************************"<<endl;
	cout<<"TOTAL                " + to_string(total_qty) + "             " + to_string(total_price) + "\n";
	cout<<"*****************************************"<<endl;

	cout<<"[1] PRINT RECIEPT  ";cout<<"[2] PAY "<<endl;
	char choice;
	cin>>choice;

	if(choice == '1'){

	}
	else if(choice == '2'){
		pay();
	}
}

} /* namespace string_literals */
} /* namespace literals */
} /* namespace std */
