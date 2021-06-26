// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include <iostream>
#include "Tier2.h"
using namespace std;

class FirstClass : public Tier2 {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static FirstClass *myclass;       // the singleton pointer to the class
    // constructor with default parameters
    FirstClass(string name = "First Class" , float loadfactor = 2.0f , bool seat = 0 , bool ac = 0 , int num_tiers = 2 , bool luxury = 1);

public:
    ~FirstClass();
    static const FirstClass& Type();            // returns the only singleton object of the class
    float GetLoadFactor() const;
    FirstClass(const FirstClass& other) = delete;
    FirstClass& operator=(const FirstClass& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;                  // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestFirstClass();      // unit test function for the FirstClass class
    friend ostream& operator<<(ostream& os , const FirstClass& firstClass);
};


#endif