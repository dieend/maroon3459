#ifndef CART_ITEM_H_
#define CART_ITEM_H_

#include <string>
using namespace std;


struct Cart_item {
public:
	// constructors
	Cart_item () {}

   // utility functions
	string display() const;

private:
   //constants  

   // private data
	int cart_item_id;
	int cart_id;
	int prod_id;
	int prod_qty;
};


#endif //CART_ITEM_H_