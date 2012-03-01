#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

using namespace std;

struct Product
{
private:
   //constants
   //moved to public data
public:
	//data
	int prod_id;
	int cat_id;
	string prod_name;
	double prod_price;
	// constructors
	Product () {}
   // utility functions
	string display() const;
};


#endif //PRODUCT_H_
