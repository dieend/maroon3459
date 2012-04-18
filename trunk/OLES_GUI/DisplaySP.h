#ifndef DISPLAYSP_H
#define DISPLAYSP_H

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
#include "Customer.h"


using namespace std;

	class DisplaySP {

	
	public :
		static int test;
		static vector<Cart> Cart_v;
		DisplaySP();
		static void display();
	};


#endif