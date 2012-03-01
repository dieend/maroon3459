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
	string display() const{
   char id_buffer [50];
        sprintf(id_buffer, "%d" ,cust_id);
        string id_string (id_buffer);
        return cust_name+"    Customer ID: "+id_string+"    Address: "+ addr.display();
       } 
   
	
private:
   //constants
     
   // private data
	int cust_id;
	string cust_name;
	Address addr;		
};


#endif //CUSTOMER_H_
