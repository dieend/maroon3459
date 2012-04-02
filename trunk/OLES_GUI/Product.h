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
	void set_id(int id); //AS-S1
	void set_cat_id(int cat_id);  //AS-S1
	void set_name(string name);  //AS-S1
	void set_price(double price);  //AS-S1
	int product_id() const;
	double product_cost() const;
	// constructors
	Product (){}
	Product (int prod, int cat, string name, double price); //AS-S1
	Product (const Product& prod);
   // utility functions
    string display() const;
	string save(); //AS - C3
	friend istream& operator>>(istream&, Product& d); // MA-S3
	
	// comparator
	static bool cheaper(const Product& a, const Product& b); // MA-S3
	
	
	// helper
	double getTotalSell(const vector<Cart_item>& cart_items) const; // MA-S3
	static vector<const Product*>& getProductsByCategory(const vector<Product>& product, int id); //MA-S3
	static int getProductById(const vector<Product>& products, int id); //MA-S3
	static int getProductByName(const vector<Product>& products, const string& name);//MA-S3
	
};


#endif //PRODUCT_H_
