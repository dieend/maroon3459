#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <cstdio>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <algorithm>
//other types
#include "Category.h"
#include "Product.h"
#include "Customer.h"
#include "Cart.h"
#include "Cart_item.h"
#include "Address.h"
using namespace std;

class Menu {
public:
   struct InvalidData : std::runtime_error {
      InvalidData(): runtime_error("Invalid input data format") {}
   };

   struct InvalidFile : std::runtime_error {
      InvalidFile(): runtime_error("Invalid input file name") {}
   };

   enum Main_menu_options{ Info=1, Read, Show, Find, Update, Exit }; 
		
	Menu();
   
   void display_main_menu() const;
   void display_info() const;
   void read();
   void read_test();  // MA-S3
   void update();
   void show() const;
   void find() const;
   int validate(); // AS-C3
   void write();
   void exit();

private:
   //private data
	vector<Category> cats;
	vector<Product> prods;
	vector<Customer> custs;
	vector<Cart> carts;
	vector<Cart_item> cart_items;
};

#endif //MENU_H_
