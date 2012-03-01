/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <string>

using namespace std;

struct Category {
public:
   //data
	int cat_id;
	string cat_name;
	// constructors
	Category () {}

    // utility functions
	string display() const;

private:
   //constants	
   //moved to public data
};


#endif //CATEGORY_H_
