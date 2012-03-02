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
        int inp = 0;
        cout << "Show Menu" << endl;
        cout << "1. Show Category and Product" << endl;
        cout << "2. Show Customer Data" << endl;
        cout << "3. Show Cart Data" << endl;
        cout << "Input : ";
        cin >> inp;
        
        if (inp == 1) {
                for (int i = 0; i < (int)cats.size(); i++) {
                        cout << "Category ID : "<< cats[i].cat_id << endl;
                        cout << "Category Name : "<< cats[i].cat_name << endl;
                        cout << "+++++++++++++++++++++++++++++++" << endl;
                        cout << "Products : " << endl;
                        for (int j = 0; j < (int)prods.size(); j++) {
                                if (prods[j].get_cat_id() == cats[i].cat_id) {
                                        cout << prods[j].display();
                                }
                        }
                        cout << "--------------------------------" << endl;
                }
                cout << "Show queries \n";
        }
        else if (inp ==2) { // Customer
            for (int i = 0; i < (int)custs.size(); i++) {
              cout<<custs.at(i).display()<<endl;                  
            }
        }
        
        else if (inp ==3) { // Product
			vector<Product> tmp(prods);
			sort(tmp.begin(), tmp.end(), Product::cheaper);
			for (int i=0; i<(int)prods.size(); i++) {
				cout << "Product Name: "<< prods[i].get_name() << endl;
				cout << "Product ID: "<< prods[i].get_id() << endl;
				cout << "Product Price: "<< prods[i].get_price() << endl;			
			}
        }
        
        else {
                cout << "Wrong Input" << endl;
        }

}
void Menu::find() const 
{
    int inp = 0;
        cout << "Find Menu" << endl;
        cout << "1. Find Category and Product" << endl;
        cout << "2. Find Total sell of a Customer" << endl;
        cout << "3. Find Total sell Products by Category" << endl;
        cout << "Input : ";
        cin >> inp;
        
        if (inp == 1) { // Category
                int i = 0;
                int val = 0;
                int prod_id;
                int sold;
                cout << "Input Product ID :";
                cin >> prod_id;
				for (i = 0; i < prods.size() ; i++) {
					if (prods[i].get_id() == prod_id) {
					break;
					}
				}
                cout << "Total sales for given product : " << prods[i].getTotalSell(cart_items)*prods[i].get_price() << endl;	
        }
        else if (inp ==2) { // Customer
        }
        
        else if (inp ==3) { // total sales product by category // MA-SA3
        	string category_name;
        	int* category_id = NULL;
        	cout << "Input Category Name: ";  // MA-SA3
			cin >> category_name;
			for (int i=0; i<(int) cats.size(); i++) {
				if (category_name == cats[i].cat_name) {
					category_id = new int;
					*category_id = cats[i].cat_id;
				}
			}
			if (category_id == NULL) {
				cout << "There is no Category with name " + category_name << endl;
			} else {
				int m = 0;
				double total_sell = 0;
				vector<const Product*> products = Product::getProductsByCategory(prods,(int)*category_id);
				for (int i=0; i<(int)products.size(); i++) {
					total_sell += products[i]->getTotalSell(cart_items);
				}
				cout << "Total sell products by category " + category_name + " is " << total_sell << endl;
				delete category_id;
			}
        }
        
        else {
                cout << "Wrong Input" << endl;
        }
        


       // cout << "Find queries \n";
}
void Menu::update()  
{
     int inp = 0;
        cout << "Update Menu" << endl;
        cout << "1. Update Category and Product" << endl;
        cout << "2. Update Customer Data" << endl;
        cout << "3. Update Cart Data" << endl;
        cout << "Input : ";
        cin >> inp;
        
        if (inp == 1) { // Category
                int cat_id;
				int prod_id;
                string prod_name;
				double price;
                int val = 0;
                
                cout << "Input category ID :" ;
                cin >> cat_id;
                
                for (int i = 0; i < (int)cats.size(); i ++) {
                        if (cats[i].cat_id == cat_id) {
                                val = 1;
                                break;
                        }
                }
                if (val == 1) {
                        cout << "Input Product ID :" ;
                        cin >> prod_id;
                        cout << "Input Product Name :" ;
                        cin >> prod_name;
                        cout << "Input Product Price :" ;
                        cin >> price;
                        prods.push_back(Product(prod_id, cat_id, prod_name,price));
                }
                else {
                        cout << "Category ID not found" << endl;
                }
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
        	cart_items.push_back(Cart_item(cart_item_id, cart_id, prod_id, prod_qty));// MA-S3
        }
        
        else {
                cout << "Wrong Input" << endl;
        }
        
        
        
        //cout << "Update queries \n";


}


