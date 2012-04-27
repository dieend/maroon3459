#include "Cart.h"

//MA-A2
Cart::Cart (int cart_id, int cust_id, Date cpd){
	this->cart_id = cart_id;
	this->cust_id = cust_id;
	this->cart_purchase_date = cpd;
}
Cart::Cart(){
}
// utility functions
string Cart::display() const{
	stringstream ss;
	ss << "Cart id       : " << cart_id << endl;
	ss << "Cust id       : " << cust_id << endl;
	ss << "Purchase Date : " << cart_purchase_date << endl;
	string s = ss.str();
	return s;
}

string Cart::save(){ // AS-C3
	stringstream ss;
	ss << cart_id <<"	"; 
	ss << cust_id <<"	"; // AS-C3
	ss << cart_purchase_date.year() << "	"; // AS-C3
	ss << cart_purchase_date.month() << "	";
	ss << cart_purchase_date.day() <<endl;
	string s = ss.str();
	return s; // AS-C3
}

ostream& operator<<(ostream& c, Cart d){
	c << d.display();
	return c;
}
istream& operator>>(istream& c, Cart& d){
	int cart_id,cust_id;
	Date date;
	c >> cart_id >> cust_id >> date;
	d = Cart(cart_id,cust_id,date);
	return c;
}
//MA-S3
int Cart::get_cart_id() const{
	return cart_id;
}
//MA-S3
int Cart::get_cust_id() const{
	return cust_id;
}
Date Cart::get_date() const{
  return cart_purchase_date;
}
