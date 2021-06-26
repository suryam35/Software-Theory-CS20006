// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include "Date.h"
using namespace std;

// Abstract base class for passenger

class Passenger {
    const string name_;
    const string aadhar_;
    const Date dateOfBirth_;
    const bool gender_;
    string mobileNumber_;
    string category_;
public:
    Passenger(string name , string aadhar , Date dob , bool gender , string category , string mobileNumber = "");
    ~Passenger();
    virtual void GetDetails() = 0;
};

#endif // PASSENGER_H