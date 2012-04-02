#include "Product.h"


Product::Product (int prod, int cat, string name, double price) { //AS-S1
	this->prod_id = prod; //AS-S1
	this->cat_id = cat;
	this->prod_name = name; //AS-S1
	this->prod_price = price; //AS-S1

} 

Product::Product(const Product& prod) {  // MA-S3
	prod_id = prod.get_id();
	cat_id = prod.get_cat_id();
	prod_name = prod.get_name();
	prod_price = prod.get_price();
}

bool Product::cheaper(const Product& a, const Product& b){ //MA-S3
	return a.get_price() < b.get_price();//MA-S3
}

string Product::display()const{ //MA-S3
	stringstream ret;
	ret << "----\n";
	ret << "Product ID: "<< get_id() << endl;
	ret << "Product Name: "<< get_name() << endl;
	ret << "Product Price: "<< get_price() << endl;
	return ret.str();
}

string Product::save() { //AS-C3
	stringstream ret; //AS-C3
	ret <<get_id()     <<"	";
	ret <<get_cat_id() <<"	"; //AS-C3
	ret <<get_name()   <<"	";
	ret << get_price() <<endl; //AS-C3
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
istream& operator>>(istream& fsp, Product& prod) { // MA-S3
	fsp >> prod.prod_id;
    fsp >> prod.cat_id;
    fsp >> prod.prod_name;
    fsp >> prod.prod_price;
    return fsp;
}


int Product::get_id() const{
	return prod_id; //AS-S1
} // MA-S3
int Product::get_cat_id() const{
	return cat_id; //AS-S1
} // MA-S3
string Product::get_name() const{
	return prod_name; //AS-S1
} // MA-S3
double Product::get_price() const{
	return prod_price; //AS-S1
} //MA-S3

int Product::product_id() const{
	return prod_id; //AS-S1
}

double Product::product_cost() const{
	return prod_price; //AS-S1
}



void Product::set_id(int id){
	this->prod_id = id; //AS-S1
}
void Product::set_cat_id(int cat_id){ //AS-S1
	this->cat_id = cat_id; //AS-S1
}
void Product::set_name(string name){
	this->prod_name = name; //AS-S1
}
void Product::set_price(double price){
	this->prod_price = price; //AS-S1
}

int Product::getProductById(const vector<Product>& products, int id) {
	for (int i=0; i<(int)products.size(); i++) {
		if (products[i].get_id() == id) return i;
	}
	return products.size();
}

int Product::getProductByName(const vector<Product>& products, const string& name) {
	for (int i=0; i<(int)products.size(); i++) {
		if (products[i].get_name() == name) return i;
	}
	return products.size();
}


double Product::getTotalSell(const vector<Cart_item>& cart_items) const {
	int temp = 0;
	for (int i = 0; i < (int)cart_items.size() ; i++ ) {
		if (prod_id == cart_items[i].prodId()) {
			temp = temp + cart_items[i].prodQty(); //AS-S1
		}
	}
	return prod_price*temp; //AS-S1
} // MA-S3
