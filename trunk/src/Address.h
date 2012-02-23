#include <string>


using namespace std;

struct Address	{
	int house_num;
	string street_name;
	int zip;
	
	Address (int n, string s, int z): house_num(n), street_name(s), zip(z){}
};