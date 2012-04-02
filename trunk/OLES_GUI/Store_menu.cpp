#include "Store_menu.h"
#include <iostream>
//added includes
#include <fstream>
#include <algorithm>

using namespace std;
using namespace Store;

Store_menu::Store_menu()
{
}

void Store_menu::display_main_menu() const 
{
	//A.3
	cout << "\nMAIN MENU \n";
	cout << "1-Info 2-Read 3-Show 4-Find 5-Update 6-Exit\n";
}
void Store_menu::display_info() const
{
	//A.3
	cout << "\nWard Project 1: On-line Store Sales Reporting Program\n";
}

void Store_menu::read_custs(string fname)
{
	//A.1, 2 & 3 merge
	ifstream ist;

	//A.1 read and store the customer data	//should error check for duplicates

	int num_custs = get_file_info(ist, "Please enter customer data file name: ", fname);
	custs.clear();	//start with an empty list
	read_file(ist, num_custs, Store_menu::Custs);
	cout << "read " << custs.size() << " customer records \n";
	ist.close();
	return;
}

void Store_menu::read_carts(string fname)
{
	//A.2 read and store the cart and cart item data 
	ifstream ist;
	int num_carts = get_file_info(ist, "Please enter cart data file name: ", fname);
	carts.clear();
	read_file(ist, num_carts, Store_menu::Carts);
	cout << "read " << carts.size() << " carts \n";

	//A.2 read cart item data	
	int num_items = 0;
	cart_items.clear();
	ist >> num_items;
	read_file(ist, num_items, Store_menu::Items);
	cout << "read " << cart_items.size() << " cart items \n";
	ist.close();
	return;
}

void Store_menu::read_catprds(string fname)
{
	ifstream ist;
	//A.3 read and store the category and product data
	int num_cats = get_file_info(ist, "Please enter category/products file name: ", fname);
	cats.clear();
	read_file(ist, num_cats, Store_menu::Cats);
	cout << "read " << cats.size() << " category items \n";
	int num_items;
	//A.3 read product data	//should error check for duplicates
	ist >> num_items;	//get number of products
	prods.clear();
	read_file(ist, num_items, Store_menu::Prds);
	cout << "read " << prods.size() << " products \n";
	ist.close();
	return;
}

void Store_menu::show() const 
{
	//B.1, 2, 3 merge	//cout << "Show queries \n";
	cout << "Enter show query number: 1-All Categories 2-All Customers 3-All Products\n";
	int query_num;
	cin >> query_num;
	switch (query_num) 
	{
	case 1:
		//cout << "Not implemented\n";
		//break;
		{
			//B.1 list all categories sorted by id
			cout << cats.size() << " categories sorted by id\n";
			vector<Category> cpycats = cats;
			sort(cpycats.begin(), cpycats.end(), SortCategoriesByID());
			for (int i = 0; i< (int) cpycats.size(); ++i)
				cout << cpycats[i].display() << " " << count_prods(cpycats[i].get_id()) << endl;// look up and print all cat info
			cout << endl;
			break;
		}
	case 2: 
		{
			//B.2 list all customers sorted by name
			cout << custs.size() << " customers sorted by name\n";
			vector<Customer> cpycusts = custs;
			sort(cpycusts.begin(), cpycusts.end(), SortCustomersByName());
			for (int i = 0; i< (int) cpycusts.size(); ++i)
				cout << cpycusts[i].display() << endl;// look up and print all customer info
			cout << endl;
			break;
		}
	case 3:
		//cout << "Not implemented\n";
		//break;
		{
			//B.3 list all products sorted by price
			cout << prods.size() << " products sorted by price\n";
			vector<Product> cpyprods = prods;
			sort(cpyprods.begin(), cpyprods.end(), SortProductsByPrice());
			for (int i = 0; i< (int) cpyprods.size(); ++i)
				cout << cpyprods[i].display() << endl;// look up and print all product info
			cout << endl;
			break;
		}
	default:
		cout << "Invalid request\n";
	}
	
}
void Store_menu::find() const 
{
	//B.1, 2, 3 merge //cout << "Find queries \n";
	cout << "Enter find query number: 1-Category Sales 2-Customer Sales 3-Product Sales\n";
	int find_num;
	cin >> find_num;
	switch (find_num) 
	{
	case 1:
		//cout << "Not implemented\n";
		//break;
		{
			//B.1 calculate total sales for a given category
			int cat_id=0;
			cout << "Enter Category ID: ";
			cin >> cat_id;
			//validate category id
			int n;
			for(n=0; n<(int)cats.size(); ++n)
				if(cats[n].get_id() == cat_id) break;
			if(!(n < (int)cats.size() || 0 == cats.size())||!cin) throw InvalidData();//B.3 added check for 0 and !cin
			double sales_total = 0;
			//total up all product sales for this category.
			for (int i = 0; i < (int)prods.size(); ++i)
			{
				//select a product in this category
				if(prods[i].get_cat_id() == cat_id)
				{
					//add this product sales to the sales total
					int prod_id = prods[i].product_id();
					double prod_price = prods[i].get_price();
					for (int j = 0; j < (int)cart_items.size(); ++j)
						//select a cart item for this product
						if(cart_items[j].get_prod_id() == prod_id)
							//add the sale of this item to the total
							sales_total += prod_price * cart_items[j].get_prod_qty();					
				}
			}
			cout << cats[n].get_name() << " total sales = "<< sales_total << endl;
			break;
		}
	case 2: 
		{
		//B.2 customer sales total
			int cust_id=0;
			cout << "Enter customer ID: ";
			cin >> cust_id;
			//validate customer id
			int n;
			for(n=0; n<(int)custs.size(); ++n)
				if(custs[n].get_id() == cust_id) break;
			if(!(n < (int)custs.size() || 0 == custs.size())||!cin) throw InvalidData();//B.3 added check for 0 and !cin
			double sales_total = 0;
			//total up cart sales for this customer.
			for (int i = 0; i < (int)carts.size(); ++i)
			{
				//select carts for this customer
				if(carts[i].get_cust_id() == cust_id)
				{
					//add this cart sales to the total
					int cart_id = carts[i].get_cart_id();
					for (int j = 0; j < (int)cart_items.size(); ++j)
					{
						if(cart_items[j].get_cart_id() == cart_id)
						{
							//add sales of this product to the total
							int prod_id = cart_items[j].get_prod_id();
							int quantity = cart_items[j].get_prod_qty();
							double price = 0.0;
							for (int k = 0; k < (int)prods.size(); ++k)
							{
								if(prod_id == prods[k].product_id())
								{
									price = prods[k].product_cost();
									break;
								}
							}
							sales_total += quantity * price;
						}
					}
				}
			}
			cout << custs[n].get_name() << " total sales = "<< sales_total << endl;
			break;
		}
	case 3:
		//cout << "Not implemented\n";
		//break;
		{
			//B.3 calculate total sales for a given product
			int prod_id=0;
			cout << "Enter Product ID: ";
			cin >> prod_id;
			//validate Product id
			int n;
			for(n=0; n<(int)prods.size(); ++n)
				if(prods[n].product_id() == prod_id) break;
			if(!(n < (int)prods.size() || 0 == prods.size())||!cin) throw InvalidData();//B.3 added check for 0 and !cin
			double sales_total = 0;
			double prod_price = prods[n].get_price();
			//total up all product sales for this product
			for (int j = 0; j < (int)cart_items.size(); ++j)
				//select a cart item for this product
				if(cart_items[j].get_prod_id() == prod_id)
					//add the sale of this item to the total
					sales_total += prod_price * cart_items[j].get_prod_qty();					

			cout << prods[n].get_name() << " total sales = "<< sales_total << endl;
			break;
		}
	default:
		cout << "Invalid request\n";
	}
}
void Store_menu::update()  
{
	//B.1, 2, 3 merge //cout << "Update queries \n";
	cout << "Enter update query number: 1-Add Cart Item 2-Add Product 3-Add Customer\n";
	int query_num;
	cin >> query_num;
	switch (query_num) 
	{
	case 1:
		//cout << "Not implemented\n";
		//break;
		{
			//B.1 Add new cart item to an existing cart
			int cart_item_id, cart_id, prod_id, prod_qty;
			cout << "Enter cart_id cart_item_id product_id prod_quantity\n";
			cin >> cart_id >> cart_item_id >> prod_id >> prod_qty;
			if(!cin) throw InvalidData();
			//check that cart id exists
			int n = 0;
			for(n=0; n<(int)carts.size(); ++n)
				if(carts[n].get_cart_id() == cart_id) break;
			if(!(n < (int)carts.size())||!cin) throw InvalidData();
			//check that product id exists
			n = 0;
			for(n=0; n<(int)prods.size(); ++n)
				if(prods[n].product_id() == prod_id) break;
			if(!(n < (int)prods.size())||!cin) throw InvalidData();
			//check that quantity is positive
			if(prod_qty < 1) 
				throw InvalidData();
			//check that item id is not a duplicate
			n = 0;
			for(n=0; n<(int)cart_items.size(); ++n)
				if(cart_items[n].get_cart_id() == cart_id) //make sure we are in the right cart
					if(cart_items[n].get_item_id() == cart_item_id) throw InvalidData();
			
			//add cart item
			cart_items.push_back(Cart_item(cart_item_id, cart_id, prod_id,prod_qty));

			cout << "Number of cart items is now " << cart_items.size() << endl;
			break;
		}
	case 2: 
		{
			//B.2 Add new product to exisiting category
			int pid, cid;
			string pname;
			double price;
			cout << "Enter product_id category_id prod_name product_price\n";
			cin >> pid >> cid >> pname >> price;
			//validate category id
			int n;
			for(n=0; n<(int)cats.size(); ++n)
				if(cats[n].get_id() == cid) break;
			if(!(n < (int)cats.size() || 0 == cats.size())||!cin) throw InvalidData();//B.3 added check for 0
			//add product to category
			prods.push_back(Product(pid, cid, pname, price));
			//count products in that category now
			//int num_prod=0;									//merge eliminated this counting code
			//for(int i=0; i< (int)prods.size(); ++i)
			//	if(prods[i].get_cat_id() == cid)
			//		++num_prod;
			cout << "Number of products in that category is now " << /*num_prod*/count_prods(cid) << endl;
			break;
		}
	case 3:
		//cout << "Not implemented\n";
		//break;
		{
			//B.3 Add new customer
			int cid,snum, zc;
			string cname, sname;
			cout << "Enter customer_id customer_name street_number street_name zip_code\n";
			cin >> cid >> cname >> snum >> sname >> zc;
			//check that customer id is not a duplicate
			int n;
			for(n=0; n<(int)custs.size(); ++n)
				if(custs[n].get_id() == cid) break;
			if(!(n < (int)custs.size() || 0 == custs.size())||!cin) throw InvalidData();
			//add customer
			custs.push_back(Customer(cid, cname, Street_address(snum, sname, zc)));

			cout << "Number of customers is now " << custs.size() << endl;
			break;
		}
	default:
		cout << "Invalid request\n";
	}
}

//open a file and return the expected number of records
int Store_menu::get_file_info(ifstream& ist, string prompt, string fname)
{	
	//A.1, 2 & 3 merge
	//string fname;
	//cout << prompt;
	//cin >> fname;
	ist.clear();
	ist.open(fname.c_str());
	if (!ist) throw InvalidFile();
	int num;
	ist >> num;
	if (!ist) throw InvalidData();
	return num;
}
void Store_menu::read_file(ifstream& file, int num_rec, Store_menu::File_type ftype)
{
	//A.1, 2 & 3 merge
	//example customer data: 1000	Xerox	111	Silicon	17829
	int cust_id, st_num, zip_code;
	string cust_name, st_name;
	//example cart data:	3001	1030	2010	2	2		cart_id	cust_id	cart_date
	int cart_id, cart_year, cart_month, cart_day;
	//example cart item data:	5007	3001	100015	10	item_id cart_id prod_id prod_qty
	int item_id, prod_id, prod_qty;
	//example category data: 2300	Cellphones		cat_id	cat_name
	int cat_id;
	string cat_name;
	//example product data:	120012	2300	ExpressMusic	249	prod_id cat_id prod_name prod_price
	string prod_name;
	double prod_price;

	int i = 0; 
	while(file && i < num_rec)
	{
		switch(ftype) {	
			case Store_menu::Custs:
				file >> cust_id >> cust_name >> st_num >> st_name >> zip_code;
				custs.push_back(Customer(cust_id, cust_name, Street_address(st_num, st_name, zip_code)));
				break;
			case Store_menu::Carts:
				file >> cart_id >> cust_id >> cart_year >> cart_month >> cart_day;
				carts.push_back(Cart(cart_id, cust_id, Date(cart_year, (Date::Month)cart_month, cart_day)));
				break;
			case Store_menu::Items:
				file >> item_id >> cart_id >> prod_id >> prod_qty;
				cart_items.push_back(Cart_item(item_id, cart_id, prod_id, prod_qty));
				break;
			case Store_menu::Cats:
				file >> cat_id >> cat_name;
				cats.push_back(Category(cat_id, cat_name));
				break;
			case Store_menu::Prds:
				file >> prod_id >> cat_id >> prod_name >> prod_price;
				prods.push_back(Product(prod_id, cat_id, prod_name, prod_price));
				break;
			default:
				throw InvalidData();
		}
		++i;
	}
	if(i != num_rec || !file) throw InvalidData();
}
//B.1 Count number of products for given category
int	Store_menu::count_prods(int cid)const
{
	int count = 0;
	for (int i = 0; i < (int) prods.size(); ++i)
		if(cid == prods[i].get_cat_id())
			++count;
	return count;
}

//show functions added to support GUI interface

string Store_menu::show_button(Msg_type type)
{
	switch(type) {
	case Customers_button:
		return show_func(custs, "Customer");
	case Carts_button:
		return show_func(carts, "Cart");
	case Categories_button:
		return show_func(cats, "Category");
	case Products_button:
		return show_func(prods, "Product");
	case Cart_items_button:
		return show_func(cart_items, "Cart Item");
	default:
		throw InvalidType();
}
}
/*
string Store_menu::show_customers(void)
{
	string r;
	if(0==custs.size())
		r = "No Customer Data Loaded\n";
	else
		for(int i=0; i<custs.size(); ++i)
		{
			r+=custs[i].display();
			r+="\n";
		}
	return r;
}
string Store_menu::show_carts(void)
{
	string r;
	if(0==carts.size())
		r = "No Cart Data Loaded\n";
	else
		for(int i=0; i<carts.size(); ++i)
		{
			r+=carts[i].display();
			r+="\n";
		}
	return r;
}
string Store_menu::show_categories(void)
{
	string r;
	if(0==cats.size())
		r = "No Category Data Loaded\n";
	else
		for(int i=0; i<cats.size(); ++i)
		{
			r+=cats[i].display();
			r+="\n";
		}
	return r;
}
string Store_menu::show_cart_items(void)
{
	string r;
	if(0==cart_items.size())
		r = "No Cart Item Data Loaded\n";
	else
		for(int i=0; i<cart_items.size(); ++i)
		{
			r+=cart_items[i].display();
			r+="\n";
		}
	return r;
}
string Store_menu::show_products(void)
{
	string r;
	if(0==prods.size())
		r = "No Product Data Loaded\n";
	else
		for(int i=0; i<prods.size(); ++i)
		{
			r+=prods[i].display();
			r+="\n";
		}
	return r;
}
*/