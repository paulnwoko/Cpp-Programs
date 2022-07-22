/*
 * Pos.h
 *
 *  Created on: Feb 9, 2022
 *      Author: darlington
 */

#ifndef POS_H_
#define POS_H_

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

namespace std {
namespace literals {
namespace string_literals {

class Pos {
private:
	int customerId;
	struct user{
		string name;
		string cardnum;
		unsigned int itemQty;
		uint16_t choice = -10;
	};
	user shopper;

	struct Item{
		string name = " ";
		uint16_t price = 0;
		uint16_t quanty = 1;
	};
	Item food, itm1, itm2, itm3, itm4, itm5, itm6, itm7, itm8, itm9, itm10, itm11, itm12, itm13,
	itm14, itm15, itm16, itm17, itm18, itm19, itm20, itm21, itm22, itm23, itm24, itm25, itm26;


//vector<string>FoodMenu = {"FRIED FISH       ", "FRIED CHIKEN       ", "RICE & STEW        ", "FRIED RICE         ",
//						  "JELLOF RICE      ", "VEGETABLE SOUP     ", "PEPPER SOUP        ", "EGUSI SOUP         ",
//						  "OGBONO SOUP      ", "OKRA SOUP          ", "BITER LEAF SOUP    ", "POUNDED YAM        ",
//						  "SEMOVITA         ", "EBA                ", "FUFU", "MOI MOI    ", "YAM & BEANS PORIDGE",
//						  "YAM PORIDGE      ", "BEANS              ", "YAM WITH EGG SAUCE ", "FRIED PLANTAIN     ",
//						  "ABACHA           ", "PINEAPPLE JUICE    ", "ORANGE JUICE       ", "FRUIT SALAD        ", "RED WINE           "};

vector<Item>MenuItem = {itm1, itm2, itm3, itm4, itm5, itm6, itm7, itm8, itm9, itm10, itm11, itm12, itm13, itm14,
						itm15, itm16, itm17, itm18, itm19, itm20, itm21, itm22, itm23, itm24, itm25, itm26};


//to hold items in the cart
vector<Item>cart = {};

//to hold labels of the items to purchase
vector<string>ShoppingCart = {};

public:
	Pos();
	virtual ~Pos();

	void homepage();
	void pay();
	void addItems();
	void checkout(uint8_t qty);
	void removeItem();
	void ViewCart(uint8_t qty);
};

} /* namespace string_literals */
} /* namespace literals */
} /* namespace std */

#endif /* POS_H_ */
