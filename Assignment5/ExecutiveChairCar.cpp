// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include <iostream>
#include <cmath>
#include "ExecutiveChairCar.h"
using namespace std;

ExecutiveChairCar *ExecutiveChairCar::myclass = 0;      // the static singleton pointer to the  class

ExecutiveChairCar::ExecutiveChairCar(string name , float loadfactor, bool seat , bool ac, int num_tiers , bool luxury , int mintatkal, int maxtatkal, int mindistance, int reservationcharge): hasSeat_(seat) , isAC_(ac) , numberOfTiers_(num_tiers) {
    name_ = name;
    loadFactor_ = loadfactor;
    isLuxury_ = luxury;
    minTatkalCharge = mintatkal;
    maxTatkalCharge = maxtatkal;
    reservationCharges = reservationcharge;
    minTatkalDistance = mindistance;
}

const ExecutiveChairCar& ExecutiveChairCar::Type() {
    if(!myclass) {
        myclass = new ExecutiveChairCar();            // returns the only instance of the  class thereby making it singleton
    }
    return *myclass;
}

float ExecutiveChairCar::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string ExecutiveChairCar::GetName() const{
    return (*this).name_;
}

int ExecutiveChairCar::GetNumberOfTiers() const{
    return (*this).numberOfTiers_;
}

bool ExecutiveChairCar::IsSitting() const{
    return (*this).hasSeat_;
}

bool ExecutiveChairCar::IsAC() const{
    return (*this).isAC_;
}

bool ExecutiveChairCar::IsLuxury() const{
    return (*this).isLuxury_;
}

ExecutiveChairCar::~ExecutiveChairCar() {}


ostream& operator<<(ostream& os , const ExecutiveChairCar& ExecutiveChairCar) {      // prints the ExecutiveChairCar class object
    os << "\nName : " << ExecutiveChairCar.name_ << endl;
    os << "Load Factor : " << ExecutiveChairCar.loadFactor_ << endl;
    os << "Is Sitting : " << ExecutiveChairCar.hasSeat_ << endl;
    os << "Is AC : " << ExecutiveChairCar.isAC_ << endl;
    os << "Is Luxury : " << ExecutiveChairCar.isLuxury_ << endl;
    os << "Number of Tiers : " << ExecutiveChairCar.numberOfTiers_ << "\n" << endl;
    return os;
}

void ExecutiveChairCar::UnitTestExecutiveChairCar() {            // checks for different use cases of the ExecutiveChairCar class
    if(ExecutiveChairCar::Type().name_ != "Executive Chair Car") {
        cout << "Name of the ExecutiveChairCar class is wrong !" << endl; // start of the data member tests
    }
    if(fabs(ExecutiveChairCar::Type().loadFactor_ - 5.0f) > 0.01f) {
        cout << "Load Factor of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().hasSeat_ != 1) {
        cout << "Has Seat of the ExecutiveChairCar class is wrong !" << endl;          // these 6 tests check the data members of the ExecutiveChairCar class
    }
    if(ExecutiveChairCar::Type().isAC_ != 1) {
        cout << "AC of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().isLuxury_ != 1) {
        cout << "Luxury of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().numberOfTiers_ != 0) {
        cout << "Number of Tiers of the ExecutiveChairCar class is wrong !" << endl; //  end of the data member tests
    }
    if(ExecutiveChairCar::Type().GetName() != "Executive Chair Car") {
        cout << "Name function of the ExecutiveChairCar class is wrong !" << endl;   // start of the member function tests
    }
    if(ExecutiveChairCar::Type().GetLoadFactor() != 5.0f) {
        cout << "Load Factor function of the ExecutiveChairCar class is wrong !" << endl;         // these 6 tests check the member functions of the ExecutiveChairCar class
    }
    if(ExecutiveChairCar::Type().IsSitting() != 1) {
        cout << "IsSitting function of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().IsAC() != 1) {
        cout << "IsAC function of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().IsLuxury() != 1) {
        cout << "IsLuxury function of the ExecutiveChairCar class is wrong !" << endl;
    }
    if(ExecutiveChairCar::Type().GetNumberOfTiers() != 0) {
        cout << "GetNumberOfTiers function of the ExecutiveChairCar class is wrong !" << endl;   // end of the member function tests
    }
}