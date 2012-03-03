#include "Menu.h"
//additional includes


using namespace std;

Menu::Menu()
{
}

void Menu::display_main_menu() const  //AS-A3
{
  cout << "-------Main Menu---------\n"; //AS-A3
  cout << "1.Display Info\n"; //AS-A3
  cout << "2.Read\n"; //AS-A3
  cout << "3.Show\n"; //AS-A3
  cout << "4.Find\n"; //AS-A3
  cout << "5.Update\n"; //AS-A3
  cout << "6.Exit\n"; //AS-A3
  cout << "Please insert your choice :\n"; //AS-A3
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
void Menu::read_test()   // MA-S3
{
	cout << "Read file name then read store data \n";
        //MA-A2
        int n;
        fstream fs;
        string filename;
        // reading carts data
        cout << "--------------------------------\n";
        cout << "Reading cart data :\n";
        cout << "Enter file name for carts data : ";
       	filename = "carts.dat";
        cout << filename << endl;
        // carts.dat
        fs.open(filename.c_str());
        if (!fs) {
                cerr << "can't open file " << filename << endl;
        } else {
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
                cout << "Reading Successfull\n";
        }
        // finish reading cart and cart item
   		//MA-A2
   
	    fstream fsp;
        int n1,n2;
        string file_prod_name;
        Product prod;
        //-----------------------------------------
        cout << "--------------------------------\n";
        cout << "Enter file name for category & product data: "; //MA-A2
        //cin >> file_prod_name;
        file_prod_name = "catprd.dat";
        cout << file_prod_name << endl;
        cout << "Reading category data...\n";
        //cout << "Enter file name for product data data : "; MA-A2
        fsp.open(file_prod_name.c_str());
        if (!fsp) {
                cerr<< "can't open file " << file_prod_name << endl;  // MA-A2
        } 
        else {
                fsp >> n1;
                for (int i=0; i<n1; i++) {
                        Category cat;
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
                //for (int i=0; i<n1; i++) { //AS-S1
                for (int i=0; i<n2; i++) { //MA-S2: you should loop by n2
                        fsp >> prod;
                        prods.push_back(prod);
                }
                cout << "Reading Product Successfull\n";
        }       
        fsp.close();

        
        cout << "--------------------------------\n";   
        cout << "Reading customer data\n";
        //cout<<"Please enter input file name: "; MA-A2
        cout << "Enter file name for customer data: "; //MA-A2
    ifstream ifs;
    string name;
    name = "cust.dat";
    cout << name << endl;
    //cin>>name;
    ifs.open(name.c_str());
    //if(!ifs)cerr<<("can't open file, ",name); MA-A2
    if(!ifs) { // MA-A2
        // cerr<<("can't open file, ",name); //MA-A2
        cerr<< "can't open file " << name << endl;
    } else {
                int n3;
                ifs>>n3;
                int id;
                int house_n;
                int z;
                string cust_name;
                string strt;
                //Address address(house_n, strt, z); MA-A2
                custs.clear();
                for(int i=0; i<n3;i++){
                    ifs >> id;
                    ifs >> cust_name;
                    ifs >> house_n;
                    ifs >> strt;
                    ifs >> z;
                    Address address(house_n, strt, z); // MA-A2
                    custs.push_back(Customer(id,cust_name,address));
                }
                ifs.close();
                //cout<< "reading complete\n";
                cout<< "Reading Successfull\n"; // MA-A2
        }
}
void Menu::read()
{
        cout << "Read file name then read store data \n";
        
        int n;
        fstream fs;
        string filename;
        // reading carts data
        cout << "--------------------------------\n";
        cout << "Reading cart data :\n";
        cout << "Enter file name for carts data : ";
        cin >> filename;
        // carts.dat
        fs.open(filename.c_str());
        if (!fs) {
                cerr << "can't open file " << filename << endl;
        } else {
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
                cout << "Reading Successfull\n";
        }
        // finish reading cart and cart item
   
   
	    fstream fsp;
        int n1,n2;
        string file_prod_name;
        Product prod;
        //-----------------------------------------
        cout << "--------------------------------\n";
        cout << "Enter file name for category & product data: "; //MA-A2 AS-A3
        cin >> file_prod_name; //AS-A3
        cout << "Reading category data...\n";
        //cout << "Enter file name for product data data : "; MA-A2
        fsp.open(file_prod_name.c_str());  //AS-A3
        if (!fsp) {
                cerr<< "can't open file " << file_prod_name << endl;  // MA-A2
        } 
        else {
                fsp >> n1; //AS-A3
                for (int i=0; i<n1; i++) {
                        Category cat;
                        fsp >> cat.cat_id;
                        fsp >> cat.cat_name;
                        cats.push_back(cat);
                }
                cout << "Reading Category Successfull\n";
				cout << "-----------------------------------\n";
				cout << "Reading product data...\n";
				//cout << "Enter file name for product data data : "; MA-A2
                prods.clear();
				fsp >> n2;
                for (int i=0; i<n2; i++) { //MA-S2: you should loop by S2
                        fsp >> prod;
                        prods.push_back(prod); //AS-A3
                }
                cout << "Reading Product Successfull\n";
        }       
        fsp.close(); //AS-A3

        
        cout << "--------------------------------\n";   
        cout << "Reading customer data\n"; 
        //cout<<"Please enter input file name: "; MA-A2
        cout << "Enter file name for customer data: "; //MA-A2
    ifstream ifs;
    string name;
    cin>>name;
    ifs.open(name.c_str());
    //if(!ifs)cerr<<("can't open file, ",name); MA-A2
    if(!ifs) { // MA-A2
        // cerr<<("can't open file, ",name); //MA-A2
        cerr<< "can't open file " << name << endl;
    } else {
                int n3;
                ifs>>n3;
                int id;
                int house_n;
                int z;
                string cust_name;
                string strt;
                //Address address(house_n, strt, z); MA-A2
                custs.clear();
                for(int i=0; i<n3;i++){
                    ifs >> id;
                    ifs >> cust_name;
                    ifs >> house_n;
                    ifs >> strt;
                    ifs >> z;
                    Address address(house_n, strt, z); // MA-A2
                    custs.push_back(Customer(id,cust_name,address));
                }
                ifs.close();
                //cout<< "reading complete\n";
                cout<< "Reading Successfull\n"; // MA-A2
        }
}
void Menu::show() const 
{
        //cout << "Show queries \n";
        int inp = 0; //AS-S1
        cout << "Show Menu" << endl;  //AS-S1
        cout << "1. Show Category and Product" << endl; //AS-S1
        cout << "2. Show Customer Data" << endl;
        cout << "3. Show Product Data" << endl;
        cout << "Input : "; //AS-S1
        cin >> inp; //AS-S1
        
        if (inp == 1) { //AS-S1
                for (int i = 0; i < (int)cats.size(); i++) { //AS-S1
                        cout << "Category ID : "<< cats[i].cat_id << endl; //AS-S1
                        cout << "Category Name : "<< cats[i].cat_name << endl; //AS-S1
                        cout << "+++++++++++++++++++++++++++++++" << endl;
                        cout << "Products : " << endl; //AS-S1
                        for (int j = 0; j < (int)prods.size(); j++) {
                                if (prods[j].get_cat_id() == cats[i].cat_id) {
                                        cout << prods[j].display();
                                }
                        }
                        cout << "--------------------------------" << endl;
                } //AS-S1
                cout << "Show queries \n"; //AS-S1
        }
        else if (inp ==2) { // Customer
        	vector<Customer> tmp(custs); //MA-S3
        	sort(tmp.begin(), tmp.end(), Customer::lexicographic_name); //MA-S3
            for (int i = 0; i < (int)tmp.size(); i++) { //MA-S3
              cout<<tmp.at(i).display()<<endl;          //MA-S3        
            }//MA-S3
            
            /** //SP-S2
            for (int i = 0; i < (int)tmp.size(); i++) {
              cout<<cust.at(i).display()<<endl;                  
            }
            */
        }
        
        else if (inp ==3) { // Product
        	//MA-S3
			vector<Product> tmp(prods);
			sort(tmp.begin(), tmp.end(), Product::cheaper);	
			for (int i=0; i<(int)tmp.size(); i++) {
				cout << tmp[i].display();
			}
			//MA-S3
        }
        
        else {
                cout << "Wrong Input" << endl;
        }

}
void Menu::find() const 
{
    int inp = 0;
        cout << "Find Menu" << endl; //AS-S1
        cout << "1. Find Total sell of a Product" << endl; //AS-S1
        cout << "2. Find Total sell of a Customer" << endl;
        cout << "3. Find Total sell of products by a Category" << endl;
        cout << "Input : ";
        cin >> inp; //AS-S1
        
        if (inp == 1) { // Category
                int i = 0;
                int prod_id;
                //AS-S1
                cout << "Input Product ID :";
                cin >> prod_id; //AS-S1
				for (i = 0; i < (int)prods.size() ; i++) {
					if (prods[i].get_id() == prod_id) { //AS-S1
					break;
					}
				} //AS-S1
				if (i>= (int) prods.size()) { //MA-S3
					cout << "There is no such product.\n";
					return;
				}
                cout << "Total sales for given product : " << prods[i].getTotalSell(cart_items)<< endl;	 //AS-S1
        }
        else if (inp ==2) { // Customer
        	//MA-S3
        	int cust_id;
        	cout << "Input Customer ID : ";
        	cin >> cust_id;
        	vector<int> cart_ids_of_customer;
        	for (int i=0; i<(int)carts.size(); i++) {
        		if (cust_id == carts[i].get_cust_id()) {
        			cart_ids_of_customer.push_back(carts[i].get_cart_id());
        		}
        	}
        	double total_money = 0;
        	for (int i=0; i<(int)cart_ids_of_customer.size(); i++) {
        		for (int j=0; j<(int)cart_items.size();j++) {
        			if (cart_items[j].cartId() == cart_ids_of_customer[i]) {
        				int prod_loc = Product::getProductById(prods, cart_items[j].prodId());
        				if (prod_loc >= (int) prods.size()) {
        					cout << "There is no such product.\n";
        					return;
        				}
        				const Product& prod = prods[prod_loc];
        				total_money += cart_items[j].prodQty()*prod.get_price();
        			}
        		}
        	}
        	cout << "Total sales for a given customer : " << total_money << endl;
        	//MA-S3
        }
        
        else if (inp ==3) { // total sales product by category // MA-S3
	        //MA-S3
        	string category_name;
        	int* category_id = NULL;
        	cout << "Input Category Name: ";  // MA-SA3
			cin >> category_name;
			for (int i=0; i<(int) cats.size(); i++) { //MA-S3
				if (category_name == cats[i].cat_name) {
					category_id = new int;
					*category_id = cats[i].cat_id; //MA-S3
				}
			}
			if (category_id == NULL) {
				cout << "There is no Category with name " + category_name << endl; //MA-S3
			} else {
				double total_sell = 0;
				vector<const Product*> products = Product::getProductsByCategory(prods,(int)*category_id); //MA-S3
				for (int i=0; i<(int)products.size(); i++) {
					total_sell += products[i]->getTotalSell(cart_items); //MA-S3
				}
				cout << "Total sell products by category " + category_name + " is " << total_sell << endl; //MA-S3
				delete category_id;
			}
			//MA-S3
        }
        
        else {
                cout << "Wrong Input" << endl;
        }
        


       // cout << "Find queries \n";
}
void Menu::update()  
{
     int inp = 0; //AS-S1
        cout << "Update Menu" << endl; //AS-S1
        cout << "1. Add Category and Product" << endl; //AS-S1
        cout << "2. Add Customer Data" << endl;
        cout << "3. Add Cart Data" << endl;
        cout << "Input : "; //AS-S1
        cin >> inp;
        
        if (inp == 1) { // Category
                int cat_id; //AS-S1
				int prod_id;
                string prod_name; //AS-S1
				double price;
                int val = 0;
                
                cout << "Input category ID :" ; //AS-S1
                cin >> cat_id; //AS-S1
                
                for (int i = 0; i < (int)cats.size(); i ++) { //AS-S1
                        if (cats[i].cat_id == cat_id) {
                                val = 1;
                                break; //AS-S1
                        } //AS-S1
                }
                if (val == 1) {
                        cout << "Input Product ID :" ; //AS-S1
                        cin >> prod_id;
                        cout << "Input Product Name :" ; //AS-S1
                        cin >> prod_name;
                        cout << "Input Product Price :" ; //AS-S1
                        cin >> price;
                        prods.push_back(Product(prod_id, cat_id, prod_name,price)); //AS-S1
                }
                else {
                        cout << "Category ID not found" << endl;
                }//AS-S1
        }
        else if (inp ==2) { // Customer
                int new_id;
                int new_house_n;
                int new_zip;
                string new_cust_name;
                string new_street;
            
            cout<<" Enter customer name: ";
            cin>> new_cust_name;
            cout<<"   Enter customer id: ";
            cin>> new_id;
            cout<<"  Enter house number: ";
            cin>> new_house_n;
            cout<<"   Enter street name: ";
            cin>> new_street;
            cout<<"      Enter zip code: ";
            cin>> new_zip;
            
            Address new_address(new_house_n,new_street,new_zip);
            Customer new_cust(new_id,new_cust_name,new_address);
            custs.push_back(new_cust);
        }
        
        else if (inp ==3) { // new Cart item
        	int cart_item_id,cart_id, prod_id,prod_qty; // MA-S3
        	cout << " Enter cart item id: ";// MA-S3
        	cin >> cart_item_id;// MA-S3
        	cout << "      Enter cart id: ";// MA-S3
        	cin >> cart_id;// MA-S3
        	cout << "   Enter product id: ";// MA-S3
        	cin >> prod_id;// MA-S3
        	cout << "  Enter product Qty: ";// MA-S3
        	cin >> prod_qty;// MA-S3
        	bool valid = false;
        	for (int i=0; valid || i<(int)carts.size(); i++) {
        		if (carts[i].get_cart_id() == cart_id) valid = true;
        	}
        	if (!valid) {
        		cout << "There is no such cart.\n";
        		return;
        	}
        	valid = false;
        	for (int i=0; valid || i<(int)prods.size(); i++) {
        		if (prods[i].get_id() == prod_id) valid = true;
        	}
        	if (!valid) {
        		cout << "There is no such product.\n";
        		return;
        	}        	
        	cart_items.push_back(Cart_item(cart_item_id, cart_id, prod_id, prod_qty));// MA-S3
        }
        
        else {
                cout << "Wrong Input" << endl;
        }
        
        
        
        //cout << "Update queries \n";


}


