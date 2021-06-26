// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include<iostream>
#include "Date.h"
using namespace std;

string Date::monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun" , "Jul", "Aug", "Sep" , "Oct", "Nov" , "Dec"};
string Date::dayNames[7] = {"Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"};

Date::Date(unsigned int d , unsigned int m , unsigned int y) : date_(d) , month_(Month(m)) , year_(y) {}

Date::Date(const Date& d) : date_(d.date_) , month_(d.month_) , year_(d.year_) {}

Date& Date::operator=(const Date& d) {
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
    return *this;
}

void Date::print() const {
    cout << date_ << "/" << Date::monthNames[month_-1] << "/" << year_;
}

Date::~Date() {}

void Date::UnitTestDate() {
    Date d1(17 , 12 , 2001);
    if(d1.date_ != 17 || d1.year_ != 2001 || d1.month_ != 12) {
        cout << "Constructor of date is wrong !" << endl;
    }
}

bool Date::operator!=(const Date& d) {
    if(date_ == d.date_ && month_ == d.month_ && year_ == d.year_) {
        return 0;
    }
    return 1;
}
