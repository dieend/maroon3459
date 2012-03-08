#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>
#include <stdio.h>
using namespace std;

struct Address  {
public:
        int house_num;
        string street_name;
        int zip;
        
        Address (int n, string s, int z): house_num(n), street_name(s), zip(z){}

		string display() const{
        stringstream ss;
		ss <<house_num<<" "<<street_name<<" "<<zip;
		string s = ss.str();
		return s;
        }
};
#endif //ADDRESS_H_
