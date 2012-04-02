/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <string>
#include <sstream>

using namespace std;

struct Category {
public:
   //data
	int cat_id;
	string cat_name;
	// constructors
	Category () {}
	Category (int id, string name); //sp-c1

    // utility functions
	string display() const;
	int get_id() const;
	string get_name() const;


private:
   //constants	
};


#endif //CATEGORY_H_
