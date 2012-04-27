#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Text_Display.H>

#include "Store_menu.h"
#include "DisplayAS.h"
#include "DisplayMA.h"
#include "GraphicsSP.h"
#include <iostream>

using namespace std;
using namespace Store;
using namespace Graph_lib;

//types we need

namespace Graph_lib {
//------------------------------------------------------------------------------
	struct Window_text_display : Widget {
		Window_text_display(Point XY, int W, int H, string L, Callback cb): Widget(XY, W, H, L, cb)
		{}
		void set_buffer(string s);
		void attach(Window&);
	private:
		Fl_Text_Buffer data;
		Fl_Text_Display *ptd;

	};
	void Window_text_display::attach(Window& win)
	{
		ptd = new Fl_Text_Display(loc.x, loc.y, width, height, label.c_str());
		ptd->buffer(&data);
		pw  = (Fl_Widget*) ptd;
		pw->callback(reinterpret_cast<Fl_Callback*>(do_it), &win); // pass the window
		own = &win;
	}
	void Window_text_display::set_buffer(string s) 
	{
		data.text(s.c_str());
	}

//------------------------------------------------------------------------------
	struct Menu_bar : Widget {
		Menu_bar(Point XY, int W, int H, Callback cb): Widget(XY, W, H, "", cb)
		{}
		void menu(Fl_Menu_Item *ma);
		void attach(Window&);
	private:
		Fl_Menu_Bar *pmb;
		Fl_Menu_Item *ma;

	};
	void Menu_bar::attach(Window& win)
	{
		pmb = new Fl_Menu_Bar(loc.x, loc.y, width, height);
		pmb->menu(ma);
		pw  = (Fl_Widget*) pmb;
		pw->callback(reinterpret_cast<Fl_Callback*>(do_it), &win); // pass the window
		own = &win;
	}
	void Menu_bar::menu(Fl_Menu_Item *m) 
	{
		ma = m;
	}
}

//header declarations
void do_about_box(Graph_lib::Window&);
void do_read(Graph_lib::Window&, Store_menu&, string, string, Msg_type);
void Main_Window_CB(Fl_Widget*, void*);
void Menu_Bar_CB (Fl_Widget*, void*);

//global data
bool main_window_click = false;
bool menu_bar_click = false;
bool main_click_enabled = true;//force serialization on clicks
int window_userdata;

//main window menu bar
//Note: for expediancy sake to define the menu bar below we used an FLTK type Fl_Menu_Item. 
//This makes our program  directly depend on FLTK instead of our interface Graph_lib.
//We don't like this, but we did it to save time, which often happens in the real world.
//A better solution is to write code to hide this in the implementation of our Graph_lib::Menu_bar
//An interesting exercise is to see if you can eliminate direct references in our code to FLTK types 
Fl_Menu_Item menu_bar[] = {
 {"Read", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Customers", 0,  (Fl_Callback*)Main_Window_CB, Address (Read_customers), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Carts", 0,  (Fl_Callback*)Main_Window_CB, Address (Read_carts), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Category/Products", 0,  (Fl_Callback*)Main_Window_CB, Address (Read_category_products), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Show", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Categories", 0,  (Fl_Callback*)Main_Window_CB, Address (Show_categories), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Customers", 0,  (Fl_Callback*)Main_Window_CB, Address (Show_customers), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Products", 0,  (Fl_Callback*)Main_Window_CB, Address (Show_products), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Find", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Category Sales", 0,  (Fl_Callback*)Main_Window_CB, Address (Find_category_sales), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Customer Sales", 0,  (Fl_Callback*)Main_Window_CB, Address (Find_customer_sales), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Product Sales", 0,  (Fl_Callback*)Main_Window_CB, Address (Find_product_sales), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Update", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Add Cart Item", 0,  (Fl_Callback*)Main_Window_CB, Address (Update_add_cart_item), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Add Product", 0,  (Fl_Callback*)Main_Window_CB, Address (Update_add_product), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Add Customer", 0,  (Fl_Callback*)Main_Window_CB, Address (Update_add_customer), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"About", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Info", 0,  (Fl_Callback*)Main_Window_CB, Address (About_info), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Help", 0,  (Fl_Callback*)Main_Window_CB, Address (About_help), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Graph", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"C2", 0,  (Fl_Callback*)Main_Window_CB, Address (C2), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"C3", 0,  (Fl_Callback*)Main_Window_CB, Address (B2), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Display", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"B1", 0,  (Fl_Callback*)Main_Window_CB, Address (B1), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"B2", 0,  (Fl_Callback*)Main_Window_CB, Address (B2), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"B3", 0,  (Fl_Callback*)Main_Window_CB, Address (B3), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Exit", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Save and exit", 0,  (Fl_Callback*)Main_Window_CB, Address (Exit_program), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};


//call back functions
void cust_cb(Address addr, Address) // callback for customer button
{
	Main_Window_CB((Fl_Widget*) addr, Address (Customers_button));
}
void cart_cb(Address addr, Address) // callback for customer button
{
	Main_Window_CB((Fl_Widget*) addr, Address (Carts_button));
}
void cat_cb(Address addr, Address) // callback for customer button
{
	Main_Window_CB((Fl_Widget*) addr, Address (Categories_button));
}
void prod_cb(Address addr, Address) // callback for customer button
{
	Main_Window_CB((Fl_Widget*) addr, Address (Products_button));
}
void cart_items_cb(Address addr, Address) // callback for customer button
{
	Main_Window_CB((Fl_Widget*) addr, Address (Cart_items_button));
}
 void display_cb(Address addr, Address) // callback for display window
{
	Main_Window_CB((Fl_Widget*) addr, Address (Display_window));
}
 void menu_bar_cb(Address addr, Address)//callback for menu bar
 {
	 Menu_Bar_CB((Fl_Widget*) addr, Address (Menu_bar_cb));
 }

void Menu_Bar_CB (Fl_Widget*, void* ud) {
	cout << "Menu Bar Callback" << " Userdata=" << (int) ud << "\n";
	menu_bar_click = true;
}

void Main_Window_CB(Fl_Widget*, void* ud) {
	if(main_click_enabled)//don't signal the window click if main loop is active
	{
		cout << "Main Window Callback" << " Userdata=" << (int) ud << "\n";
		window_userdata = (int) ud;
		main_window_click = true;
		main_click_enabled = false; //main loop active on current click
	}
}
//wait functions for callbacks to be executed
void wait_for_main_window_click() {
	while (!main_window_click) 
		Fl::wait();
	main_window_click = false;
	Fl::redraw();
}

void wait_for_menu_bar_click() {
	while (!menu_bar_click)
		Fl::wait();
	menu_bar_click = false;
	Fl::redraw();
}

int main()
{
	//create the main window and display it
	Store_menu m;
    Graph_lib::Window sw(600, 500, "OnLine Store Report Program");
    Button cust(Point(40, 50), 100, 30, "Customers", cust_cb);
	sw.attach(cust);
	Button cart(Point(40, 100), 100, 30, "Carts", cart_cb);
	sw.attach(cart);
	Button cat(Point(40, 150), 100, 30, "Categories", cat_cb);
	sw.attach(cat);
	Button prod(Point(40, 200), 100, 30, "Products", prod_cb);
	sw.attach(prod);
	Button cart_items(Point(40, 250), 100, 30, "Cart Items", cart_items_cb);
	sw.attach(cart_items);
    sw.callback((Fl_Callback*)Main_Window_CB, Address (Exit_program));
	Menu_bar mb(Point(0, 0), 600, 30, menu_bar_cb);
    mb.menu(menu_bar);
	sw.attach(mb);

	Window_text_display t(Point(150,50),400, 400, "Data Display", display_cb );
	t.set_buffer("No Data Loaded\n");
	sw.attach(t);
 	sw.resizable(&sw);
	

	//main loop to execute user clicks on the main window
	try {
		
		while(true) {
			main_click_enabled = true;
			wait_for_main_window_click();
			cout << "Act on userdata = " << window_userdata << endl;
			switch(window_userdata) 
			{
				//need to complete all the menu cases
				case Read_customers:
					do_read(sw, m, "cust.dat", "Open Customer File", Read_customers);
					break;
				case Read_carts:
					do_read(sw, m, "carts.dat", "Open Carts Data File", Read_carts);
					break;
				case Read_category_products:
					do_read(sw, m, "catprd.dat", "Open Catelog/Product File", Read_category_products);
					break;
				case Show_categories:
					t.set_buffer(m.show_button((Msg_type) Categories_button).c_str());
					break;
				case Show_customers:
					t.set_buffer(m.show_button((Msg_type) Customers_button).c_str());
					break;
				case Show_products:
					t.set_buffer(m.show_button((Msg_type) Products_button).c_str());
					break;
				case About_info:
					do_about_box(sw);
					break;
				case Customers_button: case Carts_button: case Categories_button: case Cart_items_button: case Products_button:
					t.set_buffer(m.show_button((Msg_type) window_userdata).c_str());
					break;
				case Exit_program:
					cout << "save files and exit\n";
					m.write();
					exit(0); //exit program
					break;
				case C2:
				  GraphicsSP::display();
					break;
				case C3:
					//Put C3 code here
					break;
				case B1:
                    DisplayMA::display();
					break;
				case B2:
					DisplayAS::display();
					break;

				case B3:
					DisplaySP::display();
					break;
				default:
					cout << "case not implemented\n";
			}
		}
		return 0;
	}
	catch(exception& e) {
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
		return 2;
	}
}
//show about box info window
void do_about_box(Graph_lib::Window& w) //AS-1
{
	Graph_lib::Window ab(Point(w.x()+100, w.y()+50), 700, 400, "About Box");
	ab.color(Color::white);
	ab.callback((Fl_Callback*)Menu_Bar_CB, Address (Close_about_box));
	Text msg(Point(15,50), "Maroon-345-9: On-line Store Sales Reporting Program");
	msg.set_color(Color::black);
	ab.attach(msg);

	Image al(Point(10,100),"aldo.jpg");
    al.set_mask(Point(50,10),200,400);  
	ab.attach(al);
	Text msgal(Point(15,360), "Aldo Suwandi");
	msgal.set_color(Color::black);
	msgal.set_font_size(20);
	msgal.set_font(Graph_lib::Font::screen_bold);
	ab.attach(msgal);

	Image ad(Point(240,100),"adin.jpg");
    ad.set_mask(Point(50,10),200,400);  
	ab.attach(ad);
	Text msgad(Point(240,360), "Muhammad Adinata");
	msgad.set_color(Color::black);
	msgad.set_font_size(20);
	msgad.set_font(Graph_lib::Font::screen_bold);
	ab.attach(msgad);

	Image se(Point(470,100),"selvin.jpg");
    se.set_mask(Point(50,10),200,400);  
	ab.attach(se);
	Text msgse(Point(480,360), "Selvin Perez");
	msgse.set_color(Color::black);
	msgse.set_font_size(20);
	msgse.set_font(Graph_lib::Font::screen_bold);
	ab.attach(msgse);

	wait_for_menu_bar_click();
	ab.detach(msg);//clean up window
	return;
}


void do_read(Graph_lib::Window& w, Store_menu& m, string dfn, string msg, Msg_type type)
{
	//Here again we tied our code directly to the FLTK library instead of creating an interface in our Graph_lib interface to FLTK
	//We did it for lack of time, which reflects the real word. Unfortunately if we wanted to move our code to a different graphics
	//library, we have to change our code and not just our Graphic_lib implementation.
	Fl_File_Chooser fc(dfn.c_str(), "*.dat", Fl_File_Chooser::CREATE, msg.c_str());
	fc.show();
	while (fc.shown())
		Fl::wait();	//wait for OK or Cancel button
	if(0!=fc.value())//make sure there is a string to use as a filename
	{
		string fname = fc.value();
		switch(type) {
			case Read_customers:
				m.read_custs(fname);
				break;
			case Read_carts:
				m.read_carts(fname);
				break;
			case Read_category_products:
				m.read_catprds(fname);
				break;
			default:
				throw InvalidType();
		}
	}
	return;
}
