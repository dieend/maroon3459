#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

// other types
#include "Address.h"  

using namespace std;

struct Customer {
public:
	// constructors
	Customer (int id, string n, Address a)	
	 : cust_id(id), cust_name(n), addr(a) {}

   // utility functions
	string display() const{ //SP-3
   stringstream ss;
     ss << cust_name<<endl;
     ss <<"Customer ID: "<<cust_id<<"    Address: "<< addr.display()<<endl;
     ss <<"---------------------------------\n";
       string s = ss.str();
       return s;
       } 
   
	
private:
   //constants
     
   // private data
	int cust_id;
	string cust_name;
	Address addr;		
};


#endif //CUSTOMER_H_
