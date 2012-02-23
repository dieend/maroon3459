#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>


using namespace std;

struct Address	{
public:
	int house_num;
	string street_name;
	int zip;
	
	Address (int n, string s, int z): house_num(n), street_name(s), zip(z){}
};
#endif //ADDRESS_H_