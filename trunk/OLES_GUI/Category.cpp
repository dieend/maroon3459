#include "Category.h"

Category::Category(int id, string name): cat_id(id), cat_name(name){} //sp-c1

string Category::display()const{ //AS-C3
	stringstream ret;
	ret << cat_id << "\t";
	ret <<  cat_name << endl;
	return ret.str();
}

bool Category::SortCategoriesByID(const Category& a, const Category& b){
    return a.cat_id < b.cat_id;
}

int Category::get_id() const{
    return cat_id;
}
string Category::get_name() const{
    return cat_name;
}