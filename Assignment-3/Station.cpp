// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include<iostream>
#include "Station.h"
#include "Railways.h"

using namespace std;

Station::Station(string name) : name_(name) {}
Station::~Station() {}

string Station::GetName() const {
    return (*this).name_;                // returns the name of the station
}

Station::Station(const Station& other) {
    name_ = other.name_;
}

Station& Station::operator=(const Station& other) {
    name_ = other.name_;
    return *this;
}

bool Station::operator==(const Station &other) {
    return (*this).name_ == other.name_;
}

int Station::GetDistance(const Station& other) {
    int distance = Railways::IndianRailways().GetDistance(*this , other);
    return distance;
}

ostream& operator<<(ostream& os , const Station& other) {
    os << "Station : " << other.name_ << endl;
    return os;
}

void Station::UnitTestStation() {
    Station s1("Mumbai");
    Station s2("Delhi");
    Station s3("Mumbai");
    if(s1.name_ != "Mumbai" || s2.name_ != "Delhi") {
        cout << "Station construction wrong !" << endl;        // checks if the constructor are working properly
    }
    if(s1 == s3) {
        // cout << "Station operator== correct !" << endl;
    }
    else {
        cout << "Station operator== wrong !" << endl;      // check if the equality operator is working correctly
    }
    if(s1.GetName() != "Mumbai") {
        cout << "Station name function wrong" << endl;
    }
    if(s1.GetDistance(s2) != 1447) {
        cout << "Station GetDistance function wrong" << endl;
    }
}