#include "Category.h"

Category::Category(int id, string name): cat_id(id), cat_name(name){} //sp-c1

string Category::display()const{ //AS-C3
	stringstream ret;
	ret << cat_id << "	";
	ret <<  cat_name << endl;
	return ret.str();
}
