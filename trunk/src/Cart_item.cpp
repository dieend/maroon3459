#include "Cart_item.h"
//created by MA-A2
// constructors
Cart_item::Cart_item () {
}

Cart_item::Cart_item(int citemid, int cart_id, int cidprod, int quantity) {
	this->cart_item_id = citemid;
	this->cart_id = cart_id;
	this->prod_id = cidprod;
	this->prod_qty = quantity;

}

// utility functions
string Cart_item::display() const{
	stringstream ss;
	ss << "Cart item id     : " << cart_item_id << endl;
	ss << "Cart id          : " << cart_id << endl;
	ss << "Product id       : " << prod_id << endl;
	ss << "Product Quantity : " << prod_qty << endl;
	ss << "\n";
	string s = ss.str();
	return s;
}

ostream& operator<<(ostream& c, Cart_item d){
	c << d.display();
	return c;
}
istream& operator>>(istream& c, Cart_item& d){
	int ciid, cid, pid, pqt;
	c >> ciid >> cid >> pid >> pqt;
	d = Cart_item(ciid, cid, pid, pqt);
	return c;
}

int Cart_item::cartItemId() const{ //MA-S3
	return cart_item_id;
}
int Cart_item::cartId()const { //MA-S3
	return cart_id;
}
int Cart_item::prodId()const { //MA-S3
	return prod_id;
}
int Cart_item::prodQty()const { //MA-S3
	return prod_qty;
}

