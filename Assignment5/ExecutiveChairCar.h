// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef ExecutiveChairCar_H
#define ExecutiveChairCar_H

#include <iostream>
#include "BookingClasses.h"
using namespace std;

class ExecutiveChairCar : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static ExecutiveChairCar *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // constructor with default parameters
    ExecutiveChairCar(string name = "Executive Chair Car" , float loadfactor = 5.0f , bool seat = 1 , bool ac = 1 , int num_tiers = 0 , bool luxury = 1 , int mintatkal = 400 , int maxtatkal = 500 , int mindistance = 250 , int reservationcharge = 60);

public:
    ~ExecutiveChairCar();
    static const ExecutiveChairCar& Type();       // returns the only singleton object of the class
    float GetLoadFactor() const;
    ExecutiveChairCar(const ExecutiveChairCar& other) = delete;
    ExecutiveChairCar& operator=(const ExecutiveChairCar& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;              // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestExecutiveChairCar();      // unit test function for the class
    friend ostream& operator<<(ostream& os , const ExecutiveChairCar& ExecutiveChairCar);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};


#endif