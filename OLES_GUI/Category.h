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
    int get_id() const;
    // constructors
    Category () {}
    Category (int id, string name); //sp-c1
    string get_name() const;
    // utility functions
    string display() const;
    static bool SortCategoriesByID (const Category& a, const Category& b);
private:
    int cat_id;
    string cat_name;
   
};


#endif //CATEGORY_H_
