// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include<iostream>
#include "Station.h"
#include "Railways.h"
#include "Exception.h"

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

Station Station::Construct(string name){
    int flag = 0;
    if(name == "")
        flag = 1;

    try{
        if(flag){
            BadStation ex;
            throw ex;
        }
        else{
            Station s(name);
            return s;
        }
    }
    catch(BadStation &ex){
        throw;
    }
}

void Station::UnitTestStation() {
    try{
        Station s1 = Station :: Construct("Mumbai");
        Station s2 = Station :: Construct("Delhi");
        Station s3 = Station :: Construct("Mumbai");
        if(s1.name_ != "Mumbai" || s2.name_ != "Delhi") {
            cout << "STATION CONSTRUCTION : FAILED" << endl;        // checks if the constructor are working properly
        }
        else{
            cout << "STATION CONSTRUCTION : PASSED" << endl;
        }
        if(s1 == s3) {
            cout << "STATION OPERATOR( == ) : PASSED" << endl;   // check if the equality operator is working correctly
        }
        else{
            cout << "STATION OPERATOR( == ) : FAILED" << endl;    // check if the equality operator is not working correctly
        }
        
        if(s1.GetName() != "Mumbai") {
            cout << "STATION GETNAME() : FAILED" << endl;
        }
        else{
            cout<<"STATION GETNAME() : PASSED"<<endl;
        }
        if(s1.GetDistance(s2) == 1447) {
            cout << "STATION GETDISTANCE() : PASSED" << endl;
        }
        else{
            cout << "STATION GETDISTANCE() : FAILED" << endl;
        }
    }
    catch(BadStation &ex){
        cout<<"STATION CONSTRUCTION FAILED"<<endl;
    }

    try{
        Station s1 = Station :: Construct("");
        cout<<"EMPTY NAME (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"EMPTY NAME (NEGATIVE TEST) : FAILED"<<endl;
    }
}