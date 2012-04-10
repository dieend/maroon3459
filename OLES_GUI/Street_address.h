#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

struct Street_address  {
public:
        int house_num;
        string street_name;
        int zip;
        
        Street_address(int n, string s, int z): house_num(n), street_name(s), zip(z){}

        string display() const;
};
#endif //ADDRESS_H_
