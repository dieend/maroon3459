#include "Street_address.h"

string Street_address::display() const{
    stringstream ss;
    ss <<house_num<<" "<<street_name<<" "<<zip;
    string s = ss.str();
    return s;
}
