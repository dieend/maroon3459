#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include <sstream>
// other types
#include "Address.h"  

using namespace std;

struct Customer {
public:
	// constructors
	Customer (int id, string n, Address a);

   // utility functions
	string display() const;
	string save(); //AS-C3
	int get_id() const;
   static bool lexicographic_name(const Customer& a, const Customer & b); // MA-S3
   static int findCustomerByName(const vector<Customer>& cust, const string& name);  // MA-S3
	
private:
   //constants
     
   // private data
	int cust_id;
	string cust_name;
	Address addr;
};


#endif //CUSTOMER_H_
