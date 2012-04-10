#include <string>

// other types
#include "Customer.h"  

Customer::Customer (int id, string n, Street_address a): cust_id(id), cust_name(n), addr(a) {
}
string Customer::get_name() const{
    return cust_name;
}
string Customer::display() const{ //SP-3
    stringstream ss;
    ss << cust_name<<endl;
    ss <<"Customer ID: "<<cust_id<<"    Address: "<< addr.display()<<endl;
    ss <<"---------------------------------\n";
    string s = ss.str();
    return s;
} 

string Customer::save() { //AS-C3
    stringstream ss;
	ss <<cust_id	<<"	";
	ss <<cust_name	<<"	";
	ss <<addr.display()<<endl;
	string s = ss.str();
	return s;
} 

bool Customer::SortCustomersByName(const Customer& a, const Customer & b){ // MA-S3
	return a.cust_name < b.cust_name;
}

int Customer::findCustomerByName(const vector<Customer>& cust, const string& name) {  // MA-S3
	for (int i=0; i<(int)cust.size(); i++) {
		if (name == cust[i].cust_name) {
			return i;
		}
	}
	return cust.size();
}

int Customer::get_id() const{  // MA-S3
	return cust_id;
}

int Customer::findCustomerById(const vector<Customer>& cust, const int id){
	for (int i=0; i<(int) cust.size(); i++) {
		if (id == cust[i].get_id()) {
			return i;
		}
	}
	return cust.size();
}
