// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef ACCHAIRCAR_H
#define ACCHAIRCAR_H

#include <iostream>
#include "Tier0.h"
using namespace std;

class ACChairCar : public Tier0 {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static ACChairCar *myclass;       // the singleton pointer to the class
    // constructor with default parameters
    ACChairCar(string name = "AC Chair Car" , float loadfactor = 1.25f , bool seat = 1 , bool ac = 1 , int num_tiers = 0 , bool luxury = 0);

public:
    ~ACChairCar();
    static const ACChairCar& Type();        // returns the only singleton object of the class
    float GetLoadFactor() const;
    ACChairCar(const ACChairCar& other) = delete;
    ACChairCar& operator=(const ACChairCar& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;          // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestACChairCar();      // unit test function for the class
    friend ostream& operator<<(ostream& os , const ACChairCar& acchairCar);
};


#endif