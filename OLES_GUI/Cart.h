/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef CART_H_
#define CART_H_

//other types
#include "Chrono.h"				//uncomment once you have added the type definition
#include <string>
#include <sstream>
using namespace std;
using namespace Chrono;
struct Cart {
public:
	//data

	// constructors
	//Cart () {}
	Cart();
	Cart (int cart_id, int cust_id, Chrono::Date cart_puchase_date);
	int get_cart_id() const;//MA-S3
	int get_cust_id() const;//MA-S3
  Date get_date() const; //sp-c3
   // utility functions
	string display() const;
	string save(); // AS-C3
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

