#ifndef GRAPHICSSP_H
#define GRAPHICSSP_H

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

	class GraphicsSP {

	
	public :
		static int test;
		static vector<Cart> cartsV;
		static vector<Cart_item>cart_itemsV;
		GraphicsSP();
		static void display();
	};


#endif