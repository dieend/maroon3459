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
        char num_buff [50], zip_buff [50];
        sprintf(num_buff,"%d", house_num);
        sprintf(zip_buff,"%d", zip);
        string num_string (num_buff), zip_string (zip_buff);
        return num_string +" "+ street_name +" "+ zip_string;
        }
};
#endif //ADDRESS_H_