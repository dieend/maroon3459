#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <sstream>
#include <vector>
#include "Cart_item.h"
using namespace std;

struct Product
{
private:
   //constants
   //data
	int prod_id;
	int cat_id;
	string prod_name;
	double prod_price;
	
public:
	int get_id() const; // MA-S3
	int get_cat_id() const; // MA-S3
	string get_name() const; // MA-S3
	double get_price() const; //MA-S3
	void set_id(int id); // MA-S3
	void set_cat_id(int cat_id); // MA-S3
	void set_name(string name); // MA-S3
	void set_price(double price); //MA-S3
	// constructors
	Product (){}
	Product (int prod, int cat, string name, double price);
   // utility functions
    string display() const;

	friend istream& operator>>(istream&, Product d);
	// comparator
	static bool cheaper(const Product& a, const Product& b); // MA-S3
	
	
	// helper
	double getTotalSell(const vector<Cart_item>& cart_items) const; // MA-S3
	static vector<const Product*>& getProductsByCategory(const vector<Product>& product, int id); //MA-S3
	
};


#endif //PRODUCT_H_
