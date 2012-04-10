#ifndef CART_ITEM_H_
#define CART_ITEM_H_

#include <string>
#include <sstream>
using namespace std;


struct Cart_item {
public:
	// constructors
	Cart_item ();
	Cart_item(int citemid, int cart_id, int cidprod, int quantity);
   // utility functions
	string display() const;
	int get_item_id() const; //MA-S3
	int get_cart_id() const; //MA-S3
	int get_prod_id() const;//MA-S3
	int get_prod_qty() const;//MA-S3
	string save(); // AS-C3


private:
   //constants  

   // private data
	int cart_item_id;
	int cart_id;
	int prod_id;
	int prod_qty;
	friend ostream& operator<<(ostream&, Cart_item d);
	friend istream& operator>>(istream&, Cart_item& d);

};

#endif //CART_ITEM_H_
