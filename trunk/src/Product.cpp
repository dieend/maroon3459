#include "Product.h"

bool Product::cheaper(const Product& a, const Product& b){ //MA-S3
	return a.get_price() < b.get_price();//MA-S3
}

string Product::display()const{ //MA-S3
	stringstream ret;
	ret << "Product ID: "<< get_id() << endl;
	ret << "Product Name: "<< get_name() << endl;
	ret << "Product Price: "<< get_price() << endl;
	return ret.str();
}
vector<const Product*>& Product::getProductsByCategory(const vector<Product>& product, int category_id) { // MA-S3
	vector<const Product*>* ret = new vector<const Product*>();
	for (int i=0; i<(int)product.size(); i++) {
		if (product[i].get_cat_id() == category_id) {
			ret->push_back(&product[i]);
		}
	}
	return (*ret);
}
istream& operator>>(istream& fsp, Product prod) { // MA-S3
	fsp >> prod.prod_id;
    fsp >> prod.cat_id;
    fsp >> prod.prod_name;
    fsp >> prod.prod_price;
    return fsp;
}


int Product::get_id() const{} // MA-S3
int Product::get_cat_id() const{} // MA-S3
string Product::get_name() const{} // MA-S3
double Product::get_price() const{} //MA-S3
double Product::getTotalSell(const vector<Cart_item>& cart_items) const {} // MA-S3
