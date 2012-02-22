#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
//created by MA-A2

class Date{
	int d, m, y;
	static Date default_date;
	static int _day_of_month[12];
	bool valid_date(int dd, int mm, int yy);
public:
	int day_of_month(int m);
	Date(int dd, int mm, int yy);
	Date();
	Date(const Date& dt);
	~Date();
	static void set_default(int dd, int mm, int yy);
	int day() const;
	int month() const;
	int year() const;
	Date& add_year(int n);
	Date& add_month(int n);
	Date& add_day(int n);
	static int leapyear(int n);
	string string_rep() const;
	class Bad_date{};
	
	Date& operator=(const Date&dt);
	
	bool operator!=(const Date&) const;
	bool operator<(const Date&) const;
	bool operator>(const Date&) const;
	
	Date& operator++();
	Date& operator--();
	
	Date& operator+=(int n);
	Date& operator-=(int n);
	
	Date operator+(int n);
	Date operator-(int n);
	
};

ostream& operator<<(ostream&, Date d);
istream& operator>>(istream&, Date& d);

#endif
