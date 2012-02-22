/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef CART_H_
#define CART_H_

//other types
#include "Date.h"				//uncomment once you have added the type definition
#include <string>
using namespace std;

struct Cart {
public:
	//data

	// constructors
	//Cart () {}
	Cart();
	Cart (int cart_id, int cust_id, Date& cart_puchase_date);
	
   // utility functions
	string display() const;
private:
   //constants

   // private data
	int cart_id;
	int cust_id;
	Date cart_purchase_date;	//uncomment once you have added the type definition
};
ostream& operator<<(ostream&, Cart d);
istream& operator>>(istream&, Cart& d);

#endif //CART_H_
