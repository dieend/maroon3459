#include "Menu.h"
//additional includes


using namespace std;

Menu::Menu()
{
}

void Menu::display_main_menu() const 
{
	cout << "-------Main Menu---------\n";
  cout << "1.Display Info\n";
  cout << "2.Read\n";
  cout << "3.Show\n";
  cout << "4.Find\n";
  cout << "5.Update\n";
  cout << "6.Exit\n";
  cout << "Please insert your choice :\n";
}
void Menu::display_info() const
{

}

void Menu::read()
{
    fstream fsp;
	int n1,n2;
	string file_prod_name;
	Product prod;
	Category cat;
	//-----------------------------------------
	cout << "--------------------------------\n";
	cout << "Enter file name for category & product data: "; //MA-A2
	cin >> file_prod_name;
	cout << "Reading category data...\n";
	//cout << "Enter file name for product data data : "; MA-A2
	fsp.open(file_prod_name.c_str());
	if (!fsp) {
		cerr<< "can't open file " << file_prod_name << endl;  // MA-A2
	} 
	else {
		fsp >> n1;
		for (int i=0; i<n1; i++) {
			fsp >> cat.cat_id;
			fsp >> cat.cat_name;
			cats.push_back(cat);
		}
		cout << "Reading Category Successfull\n";
	cout << "-----------------------------------\n";
	cout << "Reading product data...\n";
	//cout << "Enter file name for product data data : "; MA-A2
		fsp >> n2;
		prods.clear();
		for (int i=0; i<n1; i++) {
			fsp >> prod.prod_id;
			fsp >> prod.cat_id;
			fsp >> prod.prod_name;
			fsp >> prod.prod_price;
			prods.push_back(prod);
		}
		cout << "Reading Product Successfull\n";
	}	
	fsp.close();
}
void Menu::show() const 
{
	int inp = 0;
	cout << "Show Menu" << endl;
	cout << "1. Show Category and Product" << endl;
	cout << "2. Show Customer Data" << endl;
	cout << "3. Show Cart Data" << endl;
	cout << "Input : ";
	cin >> inp;
	
	if (inp == 1) {
		for (int i = 0; i < cats.size(); i++) {
			cout << "Category ID : "<< cats[i].cat_id << endl;
			cout << "Category Name : "<< cats[i].cat_name << endl;
			cout << "+++++++++++++++++++++++++++++++" << endl;
			cout << "Products : " << endl;
			for (int j = 0; j < prods.size(); j++) {
				if (prods[j].cat_id == cats[i].cat_id) {
					cout << "Product ID: "<< prods[i].prod_id << endl;
					cout << "Product Name: "<< prods[i].prod_name << endl;
					cout << "Product Price: "<< prods[i].prod_price << endl;
				}
			}
			cout << "--------------------------------" << endl;
		}
		cout << "Show queries \n";
	}
	else if (inp ==2) { // Customer
	
	}
	
	else if (inp ==3) { // Cart
	
	}
	
	else {
		cout << "Wrong Input" << endl;
	}
		
}
void Menu::find() const 
{
	int inp = 0;
	cout << "Show Menu" << endl;
	cout << "1. Find Category and Product" << endl;
	cout << "2. Find Customer Data" << endl;
	cout << "3. Find Cart Data" << endl;
	cout << "Input : ";
	cin >> inp;
	
	if (inp == 1) { // Category
		int i = 0;
		int val = 0;
		int prod_id;
		int sold;
		cout << "Input Product ID :";
		cin >> prod_id;
		cout << "Input sold number for the given product :" ;
		cin >> sold;
		for (i = 0; i < prods.size(); i ++) {
			if (prods[i].prod_id == prod_id) {
				val = 1;
				break;
			}
		}
		if (val == 1) cout << "Total Sales =" << prods[i].prod_price*sold << endl;
		else cout << "Product not found!" << endl;
		
	}
	else if (inp ==2) { // Customer
	
	}
	
	else if (inp ==3) { // Cart
	
	}
	
	else {
		cout << "Wrong Input" << endl;
	}
	

}
void Menu::update()  
{
	int inp = 0;
	cout << "Show Menu" << endl;
	cout << "1. Update Category and Product" << endl;
	cout << "2. Update Customer Data" << endl;
	cout << "3. Update Cart Data" << endl;
	cout << "Input : ";
	cin >> inp;
	
	if (inp == 1) { // Category
		int cat_id;
		string prod_name;
		int prod_price;
		int val = 0;
		Product prod;
		
		cout << "Input category ID :" ;
		cin >> cat_id;
		
		for (int i = 0; i < cats.size(); i ++) {
			if (cats[i].cat_id == cat_id) {
				val = 1;
				break;
			}
		}
		if (val == 1) {
			cout << "Input Product ID :" ;
			cin >> prod.prod_id;
			cout << "Input Product Name :" ;
			cin >> prod.prod_name;
			cout << "Input Product Price :" ;
			cin >> prod.prod_price;
			cat_id >> prod.cat_id;
			prods.push_back(prod);
		}
		else {
			cout << "Category ID not found" << endl;
		}
	}
	else if (inp ==2) { // Customer
	
	}
	
	else if (inp ==3) { // Cart
	
	}
	
	else {
		cout << "Wrong Input" << endl;
	}
	
	
	
	cout << "Update queries \n";
}
