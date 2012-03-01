#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <sstream>
#include <vector>
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
	// constructors
	Product () {}
   // utility functions
	string display() const;
	friend istream& operator>>(istream&, Product d);
	// comparator
	static bool cheaper(const Product& a, const Product& b); // MA-S3
	static vector<const Product*>& getProductsByCategory(const vector<Product>& product, int id); //MA-S3
};


#endif //PRODUCT_H_