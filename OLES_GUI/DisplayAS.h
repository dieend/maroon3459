#ifndef DISPLAYAS_H
#define DISPLAYAS_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Simple_window.h"
#include <iostream>
#include "Cart.h"
#include "Cart_item.h"
#include "Category.h"
#include "Product.h"


using namespace std;

	class DisplayAS {

	
	public :
		static int test;
		static vector<Cart_item> Acart_items;
		

		DisplayAS();
		static void display();
	};


#endif