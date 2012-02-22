#include "Date.h"
//created by MA-A2

Date Date::default_date = Date(1,1,1981);
int Date::_day_of_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(const Date& dt) {
	d = dt.day();
	m = dt.month();
	y = dt.year();
}
Date& Date::operator=(const Date&dt){
	d = dt.day();
	m = dt.month();
	y = dt.year();
	return (*this);
}
Date::Date(){
	d = default_date.day();
	m = default_date.month();
	y = default_date.year();
}
Date::Date(int dd, int mm, int yy){
	if (valid_date(dd,mm,yy)) {
		this->d = dd;
		this->m = mm;
		this->y = yy;
	} else {
		throw Bad_date();
	}
}

int Date::day_of_month(int m){
	if (m!=2) return _day_of_month[m-1];
	return _day_of_month[m-1]+leapyear(y);
}


void Date::set_default(int dd, int mm, int yy){
	default_date = Date(dd,mm,yy);
}

int Date::day() const{
	return d;
}

int Date::month() const{
	return m;
}

int Date::year() const{
	return y;
}

Date& Date::add_year(int n){
	y+=n;
	return (*this);
}

Date& Date::add_month(int n){
	m += n;
	y += (m-1)/12;
	m = ((m-1)%12) + 1;
	return (*this);
}

Date& Date::add_day(int n){
	while (n--) {
		operator++();
	}
	return *this;
}


int Date::leapyear(int n){
	if (n%100==0){
		return (n%400==0);
	} else {
		return (n%4==0);
	}
}

string Date::string_rep() const{
	stringstream ss (stringstream::in | stringstream::out);
	
	ss << day() << " ";
	switch (month()) {
		case 1:
			ss << "January";
			break;
		case 2:
			ss << "February";
			break;
		case 3:
			ss << "March";
			break;
		case 4:
			ss << "April";
			break;
		case 5:
			ss << "May";
			break;
		case 6:
			ss << "June";
			break;
		case 7:
			ss << "July";
			break;
		case 8:
			ss << "August";
			break;
		case 9:
			ss << "September";
			break;
		case 10:
			ss << "October";
			break;
		case 11:
			ss << "November";
			break;
		case 12:
			ss << "Desember";
			break;
	}
	ss << " " << year();

	return ss.str();
}

bool Date::operator!=(const Date& d) const{
	bool ret = false;
	ret |= (this->d != d.day());
	ret |= (this->m != d.month());
	ret |= (this->y != d.year());
	return ret;
}
bool Date::operator<(const Date& d) const{
	if (this->y != d.year()) return this->y < d.year();
	if (this->m != d.month()) return this->m < d.month();
	return (this->d < d.day());
}

bool Date::operator>(const Date& d) const{
	if (this->y != d.year()) return this->y > d.year();
	if (this->m != d.month()) return this->m > d.month();
	return (this->d > d.day());
}

Date& Date::operator++(){
	d++;
	if (d>day_of_month(m)) d=1,m++;
	if (m>12) y++, m=1;
	return(*this);
}
Date& Date::operator--(){
	d--;
	if (d==0) m--,d=day_of_month(m);
	if (m==0) y--;
	return(*this);
}

Date& Date::operator+=(int n){
	add_day(n);
	return *this;
}

Date& Date::operator-=(int n){
	while(n--) {
		operator--();
	}
	return(*this);
}

Date Date::operator+(int n){
	Date tmp = Date(d,m,y);
	tmp.add_day(n);
	return tmp;
}
Date Date::operator-(int n){
	Date tmp = Date(d,m,y);
	tmp-=(n);
	return tmp;
}

ostream& operator<<(ostream& c, Date d){
	return c<<d.string_rep();
}
istream& operator>>(istream& c, Date& d){
	int dd,mm,yy;
	c >> yy >> mm >> dd;
	d = Date(dd,mm,yy);
	return c;
}

bool Date::valid_date(int dd, int mm, int yy){
	int valid = true;
	valid &= (0 < mm && mm < 13);
	switch (mm){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			valid &= (0<dd && dd < 32);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			valid &= (0<dd && dd < 31);
			break;
		case 2:
			if (leapyear(y)){
				valid &= (0<dd && dd<30);
			} else {
				valid &= (0<dd && dd<29);
			}
			break;
	}
	return valid;
}
Date::~Date(){
}
/*
int main(){
	Date date;
	cin >> date;
	cout << date;
}
*/
