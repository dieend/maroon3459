#include <string>

// other types
#include "Customer.h"  

Customer::Customer (int id, string n, Address a): cust_id(id), cust_name(n), addr(a) {
}

string Customer::display() const{ //SP-3
    stringstream ss;
	ss << cust_name<<endl;
	ss <<"Customer ID: "<<cust_id<<"    Address: "<< addr.display()<<endl;
	ss <<"---------------------------------\n";
	string s = ss.str();
	return s;
} 

bool Customer::lexicographic_name(const Customer& a, const Customer & b){ // MA-S3
	return a.cust_name < b.cust_name;
}

int Customer::findCustomerByName(const vector<Customer>& cust, const string& name) {
	for (int i=0; i<(int)cust.size(); i++) {
		if (name == cust[i].cust_name) {
			return i;
		}
	}
	return cust.size();
}

int Customer::get_id() const{
	return cust_id;
}
