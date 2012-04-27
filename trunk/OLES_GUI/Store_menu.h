#ifndef STORE_MENU_H_
#define STORE_MENU_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
//other types
#include "Category.h"
#include "Product.h"
#include "Customer.h"
#include "Cart.h"
#include "Cart_item.h"
#include "Menu.h"
#include "DisplayAS.h"
#include "DisplayMA.h"
#include "DisplaySP.h"
#include "GraphicsSP.h"
using namespace std;

namespace Store{   
	
	enum Msg_type{
	Exit_program=1, About_info, About_help, Close_about_box,
	Read_customers, Read_carts, Read_category_products,
	Show_categories, Show_customers, Show_products,
	Find_category_sales, Find_customer_sales, Find_product_sales,
	Update_add_cart_item, Update_add_product, Update_add_customer,
	Customers_button, Carts_button, Categories_button, Cart_items_button, Products_button,
	Display_window, Menu_bar_cb,C2,C3,B1,B2,B3,
	};
   
	struct InvalidType : std::runtime_error {
	  InvalidType(): runtime_error("Invalid type data") {}
	};

class Store_menu {
public:
   struct InvalidData : std::runtime_error {
      InvalidData(): runtime_error("Invalid input data format") {}
   };

   struct InvalidFile : std::runtime_error {
      InvalidFile(): runtime_error("Invalid input file name") {}
   };


   enum Main_menu_options{ Info=1, Read, Show, Find, Update, Exit }; 


   enum File_type{ Custs=Customers_button, 
					Cats=Categories_button, 
					Prds=Products_button, 
					Carts=Carts_button, 
					Items=Cart_items_button };
   Store_menu();
   
  
   void display_main_menu() const;
   void display_info() const;//display assignment info & your name plus "Project 1"
   void read();		 
   void update();
   void show() const;
   void find() const;
   void read_custs(string);
   void read_carts(string);
   void read_catprds(string);
   void write();
   void updatedisplay();

	//show functions added to support GUI interface
   string show_button(Msg_type);

	template <typename T>
	string show_func(T t, string s)
	{
		string r;
		if(0==t.size())
			r = "No "+s+" Data Loaded\n";
		else
			for(int i=0; i<t.size(); ++i)
			{
				r+=t[i].display();
				r+="\n";
			}
		return r;
	}
private:
   //private data
	vector<Category> cats;
	vector<Product> prods;
	vector<Customer> custs;
	vector<Cart> carts;
	vector<Cart_item> cart_items;

	int get_file_info(ifstream& ist, string prompt, string fn);	//A.1,2,3 merge added a function for common code
	void read_file(ifstream& file, int num_rec, Store_menu::File_type ftype);
	int	count_prods(int cid) const;	//B.1 count products in a given category
};
} //end namespace Store
#endif //STORE_MENU_H_