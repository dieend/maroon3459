#include "Menu.h"
#include <iostream>
#include <fstream>
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
	cout << "Here is the Info requested \n";//display Project Part I, team name and team members
	cout << "Team name    : " << "Maroon-345-9\n";
	cout << "Team members : " << "Muhammad Adinata\n";
	cout << "               " << "Aldo Suwandi\n";
	cout << "               " << "Selvin Perez\n";
	cout << "\n";
}

void Menu::read()
{
	cout << "Read file name then read store data \n";
	
	int n;
	fstream fs;
	string filename;
	// reading carts data
	cout << "Enter file name for carts data : ";
	cin >> filename;
	// carts.dat
	fs.open(filename.c_str());
	fs >> n;
	carts.clear();
	Cart tmp;
	for (int i=0; i<n; i++) {
		fs >> tmp;
		carts.push_back(tmp);
	}
	
	// reading cart_items data
	fs >> n;
	cart_items.clear();
	Cart_item ci;
	for (int i=0; i<n; i++) {
		fs >> ci;
		cart_items.push_back(ci);
	}
	fs.close();
	// finish reading cart and cart item
   
   
    fstream fsp;
	int n1;
	string file_prod_name;
	Product prod;
	//-----------------------------------------
	cout << "--------------------------------\n";
	cout << "Reading product data\n";
	cout << "Enter file name for product data data : ";
	cin >> file_prod_name;
	fsp.open(file_prod_name.c_str());
	fsp >> n1;
	prods.clear();
	for (int i=0; i<n1; i++) {
		fsp >> prod.prod_id;
		fsp >> prod.cat_id;
		fsp >> prod.prod_name;
		fsp >> prod.prod_price;
		prods.push_back(prod);
		}
    fsp.close();
	cout << "Reading Successfull\n";
   
 cout<<"Please enter input file name: ";
    ifstream ifs;
    string name;
    cin>>name;
    ifs.open(name.c_str());
    if(!ifs)cerr<<("can't open file, ",name);
    int n;
    ifs>>n;
    int id;
    int house_n;
    int z;
    string cust_name;
    string strt;
    Address address(house_n, strt, z);
    custs.clear();
    for(int i=0; i<n;i++){
        ifs >> id;
        ifs >> cust_name;
        ifs >> house_n;
        ifs >> strt;
        ifs >> z;
        custs.push_back(Customer(id,cust_name,address));
    }
    ifs.close();
    cout<< "reading complete\n";  

   
}
void Menu::show() const 
{
	cout << "Show queries \n";
		
}
void Menu::find() const 
{
	cout << "Find queries \n";
}
void Menu::update()  
{
	cout << "Update queries \n";
}
