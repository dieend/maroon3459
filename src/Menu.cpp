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
        cout << "4. Show Product in Cart" << endl;
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
        } else if (inp==4){ // product in cart
			int loc = 0;
			int cart_id;
			cout << "Enter cart id: ";
			cin >> cart_id;
			for (loc = 0; loc < (int) carts.size(); loc++) {
				if (carts[loc].get_cart_id() == cart_id) {
					break;
				}
			}
			if (loc >= (int)carts.size()) {
					cout << "There is no such cart.\n";
					return;
			}
			
			for (int i=0; i<(int)cart_items.size(); i++) {
				if (cart_items[i].cartId() == cart_id) {
					const Product& p = prods[Product::getProductById(prods, cart_items[i].prodId())];
					const char* name = p.get_name().c_str();
					double price = p.get_price();
					int qty = cart_items[i].prodQty();
					double total = price*qty;
					printf("%-15s @%10.2lf %6d %10.2lf\n", name, price, qty, total);
				}
			}
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
        //cout << "1. Add Category and Product" << endl; //AS-S1
        cout << "1. Add Product to existing Category" << endl; //sp-c1
        cout << "2. Add Customer Data" << endl;
        cout << "3. Add Cart Item" << endl;
		cout << "4. Add Category" << endl;//sp-c1
		cout << "5. Change Product Price" << endl; //sp-c1
		cout << "6. Delete Product" << endl; //sp-c1
		cout << "7. Add Cart" << endl; //MA-C2
        cout << "8. Delete Cart Item" << endl;

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

			if(cin.fail()){
				cout<<'\n'<<"invalid input"<<endl;
				cin.clear();
				cin.ignore(1000,'\n');
					return;
			}
            
            Address new_address(new_house_n,new_street,new_zip);
            Customer new_cust(new_id,new_cust_name,new_address);
            custs.push_back(new_cust);
        }
        
        else if (inp ==3) { // new Cart item
        	int cart_item_id,cart_id, prod_id,prod_qty; // MA-S3
        	bool valid = false;
        	cout << " Enter cart item id: ";// MA-S3
        	cin >> cart_item_id;// MA-S3
        	cout << "      Enter cart id: ";// MA-S3
        	cin >> cart_id;// MA-S3
        	
        	for (int i=0; !valid && i<(int)carts.size(); i++) {
	    		if (carts[i].get_cart_id() == cart_id) valid = true;
        	}
        	if (!valid) {
        		cout << "There is no such cart.\n";
        		return;
        	}

        	
        	cout << "   Enter product id: ";// MA-S3
        	cin >> prod_id;// MA-S3
        	
        	valid = false;
        	for (int i=0; !valid && i<(int)prods.size(); i++) {
        		if (prods[i].get_id() == prod_id) valid = true;
        	}
        	if (!valid) {
        		cout << "There is no such product.\n";
        		return;
        	}        	
        	
        	
        	cout << "  Enter product Qty: ";// MA-S3
        	cin >> prod_qty;// MA-S3

        	cart_items.push_back(Cart_item(cart_item_id, cart_id, prod_id, prod_qty));// MA-S3
        }         
		else if (inp==4){// new category sp-c1
			int cat_id;
			string cat_name;
			cout<<"Input new category ID: ";
			cin>> cat_id;
			if(cin.fail()){
				cout<<'\n'<<"invalid input; Input intergers only"<<endl;
				cin.clear();
				cin.ignore(1000,'\n');
					return;
			}
			cout<<"Input new category name: ";
			cin>>cat_name;
			cats.push_back(Category(cat_id,cat_name));

		}

		else if (inp ==5){ // change product price  sp-c1
			int prod_id, prod_price,cat_id;
			string prod_name;
			bool valid = false;
			cout << "Enter product id: ";
        	cin >> prod_id;
        	
        	valid = false;
        	for (int i=0; !valid && i<(int)prods.size(); i++) {
        		if (prods[i].get_id() == prod_id) {				
					valid = true;
					cout<<prods[i].display();
				}
        	}
        	if (!valid) {
        		cout << "There is no such product.\n";
        		return;
        	}
			cout<<"\nEnter new product price: ";
			cin >> prod_price;
			
			if (prod_price <0 || cin.fail()){ 
				cout<<"Invalid product price \n";
				cin.clear();
				cin.ignore(1000,'\n');
					return;	
			}

			 for (int i = 0; i < (int)prods.size(); i ++) {
                        if (prods[i].get_id() == prod_id) {
							prod_id= prods[i].get_id();
							 cat_id= prods[i].get_cat_id();
					      prod_name= prods[i].get_name();
						    prods.erase(prods.begin()+i);
			
						}
			 }
						  
			 prods.push_back(Product(prod_id, cat_id, prod_name,prod_price));
			 cout<<"\nPrice change successfull\n"; 
			
        	
		}

		else if (inp==6){ //delete product sp-c1
			int prod_id, y_n;
			bool valid = false;
			cout << "   Enter product id to delete product: ";
        	cin >> prod_id;
        	
        	valid = false;
        	for (int i=0; !valid && i<(int)prods.size(); i++) {
        		if (prods[i].get_id() == prod_id) {
					cout<<prods[i].display()<<endl;
					valid = true;
        		}
			}
        	if (!valid) {
        		cout << "There is no such product.\n";
        		return;
        	}

			cout<<"Are you sure you want to delete this product?\n";
			cout<<"1.Yes\n2.No"<<endl;
			cout<<"Please enter your choice: ";
			cin>>y_n;
			if(y_n==1){
				for (int i=0; i<(int)prods.size(); i++){
					if (prod_id == prods.at(i).get_id()){
						prods.erase(prods.begin()+i);
					}
				}
				// also delete product in cart items
				for (vector<Cart_item>::iterator i=cart_items.begin(); 
							i!=cart_items.end(); ) { //MA-C2
					if (prod_id == (*i).prodId()){ // MA-C2
						i = cart_items.erase(i); // MA-C2
					} else {// MA-C2
						i++;// MA-C2
					}
				}
				cout<<"Deletion successfull \n";
			}
			else if (y_n== 2) return;
			else {
				cout<<"invalid input\n";
				cin.clear();
				cin.ignore(1000,'\n');
					return;	
			}

		}
		else if (inp == 7) { // add a new cart MA-C2
			int cust_id;
			cout << "Enter customer id: ";
			cin >> cust_id;
			int loc = Customer::findCustomerById(custs, cust_id);
			if (loc >= (int)custs.size()) {
				cout << " There is no such customer.\n";
				return;
			}
			try {
				cout << "Enter date of purchase (YY MM DD): ";
				Date* d = new Date();
				cin >> (*d);
				int latest_id = custs[custs.size()-1].get_id();
				carts.push_back(Cart(latest_id+1, cust_id, *d)); 
				
			} catch (const Date::Bad_date& e) {
				cout << "The date format is invalid.\n";
				return;
			}
		} else if (inp == 8) { // delete cart item MA-C2
			int cart_item;
			cout << "Enter cart item id :";
			cin >> cart_item;
			for (int i=0; i<(int)cart_items.size(); i++) {
				if (cart_items[i].cartItemId() == cart_item) {
					cart_items.erase(cart_items.begin() + i);
					cout << "Cart item deleted.\n";
					return;
				}
			}
			cout << "There is no such cart item.\n";
		}

        else {
                cout << "Wrong Input" << endl;
        }
        
        
        
        //cout << "Update queries \n";


}

int Menu::validate() { //AS-C3
	int stat = 0;
	int val = 0;
	cout << "Validating data . . ." << endl;
	for (int i = 0; i < (int)cart_items.size(); i++) { //AS-C3
		for (int j = 0; j < (int)prods.size(); j++) {
			if (cart_items[i].prodId() != prods[j].get_id()) {
			val++;
			} //AS-C3
		}
		if (val == (int)prods.size()-1) { //AS-C3
			break;
			stat = 1;
			cout << "Cart_ item refers to a non-existent Product" << endl; //AS-C3
		}
		else val = 0; //AS-C3
	}
	for (int i = 0; i < (int)cart_items.size()-1; i++) { //AS-C3
		for (int j = i+1; j < (int)cart_items.size(); j++) { 
			if (cart_items[i].cartId() == cart_items[j].cartId()) {
			val++; //AS-C3
			}
		}
		if (val == 0) { //AS-C3
			break;
			stat = 1;
			cout << "There is a Cart has less one Cart_item" << endl; //AS-C3
		}
		else val = 0; //AS-C3
	}
	if (stat == 0) return 1;
	else return 1;
	

}



void Menu::write() { // AS-C3
	FILE * pFile;
	//char buffer [33]; // AS-C3
	pFile = fopen ("carts.dat","w");
	if (pFile!=NULL)
	{
		fprintf(pFile, "%d", carts.size()); // MA-C2
		//itoa (carts.size(),buffer,10); // AS-C3
		//fputs (buffer,pFile);
		fputs ("\n",pFile);
		for (int i=0; i<(int)carts.size(); i++) { // AS-C3
			
            fputs (carts[i].save().c_str(),pFile);
        }
		fputs ("\n",pFile);
		//itoa (cart_items.size(),buffer,10); // AS-C3
		//fputs (buffer,pFile);
		fprintf(pFile, "%d",cart_items.size()); // MA-C2
		fputs ("\n",pFile);
		for (int i=0; i<(int)cart_items.size(); i++) { // AS-C3
			
            fputs (cart_items[i].save().c_str(),pFile);
        }
		cout << "Saving carts.dat ...." << endl;
		fclose (pFile); // AS-C3
	}
	
	pFile = fopen ("catprd.dat","w"); // AS-C3
	{
		//itoa (cats.size(),buffer,10);
		//fputs (buffer,pFile); // AS-C3
		fprintf(pFile, "%d", cats.size());
		fputs ("\n",pFile);
		for (int i=0; i<(int)cats.size(); i++) {
            fputs (cats[i].display().c_str(),pFile); // AS-C3
        }
		fputs ("\n",pFile);
		//itoa (prods.size(),buffer,10);
		//fputs (buffer,pFile);
		fprintf(pFile, "%d", prods.size());
		fputs ("\n",pFile);
		for (int i=0; i<(int)prods.size(); i++) { // AS-C3

            fputs (prods[i].save().c_str(),pFile);
        }
		cout << "Saving catprd.dat ...." << endl;
		fclose (pFile); // AS-C3
	}
	
		pFile = fopen ("cust.dat","w");
	{
		//itoa (custs.size(),buffer,10);
		//fputs (buffer,pFile);
		fprintf(pFile,"%d",custs.size());
		fputs ("\n",pFile); // AS-C3
		for (int i=0; i<(int)custs.size(); i++) {
            fputs (custs[i].save().c_str(),pFile);
        }
		fputs ("\n",pFile); // AS-C3
		cout << "Saving cust.dat ...." << endl;
		fclose (pFile);
	}
}


void Menu::exit() {
	

}
