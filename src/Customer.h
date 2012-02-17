#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

// other types
//#include "Address.h"		//uncomment once you have added the type definition

using namespace std;

struct Customer {
public:
	// constructors
	//Customer (int id, string n, Address a)	//uncomment once you have added the type definition
	//	: cust_id(id), cust_name(n), addr(a) {}

   // utility functions
	string display() const;
	
private:
   //constants
     
   // private data
	int cust_id;
	string cust_name;
	//Address addr;			//uncomment once you have added the type definition
};


#endif //CUSTOMER_H_
