#include "Product.h"


Product::Product (int prod, int cat, string name, double price) {
	this->prod_id = prod;
	this->cat_id = cat;
	this->prod_name = name;
	this->prod_price = price;

} 


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


int Product::get_id() const{
	return prod_id;
} // MA-S3
int Product::get_cat_id() const{
	return cat_id;
} // MA-S3
string Product::get_name() const{
	return prod_name;
} // MA-S3
double Product::get_price() const{
	return prod_price;
} //MA-S3


void Product::set_id(int id){
	this->prod_id = id;
}
void Product::set_cat_id(int cat_id){
	this->cat_id = cat_id;
}
void Product::set_name(string name){
	this->prod_name = name;
}
void Product::set_price(double price){
	this->prod_price = price;
}



double Product::getTotalSell(const vector<Cart_item>& cart_items) const {
	for (int i = 0; i < cart_items.size() ; i++ ) {
		if (prod_id == cart_items[i].prodId())
		return cart_items[i].prodQty();
	}
} // MA-S3
