#include "Category.h"

string Category::display()const{ //AS-C3
	stringstream ret;
	ret << cat_id << "	";
	ret <<  cat_name << endl;
	return ret.str();
}
