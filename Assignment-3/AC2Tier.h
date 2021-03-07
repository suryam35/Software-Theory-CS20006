// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef AC2TIER_H
#define AC2TIER_H

#include <iostream>
#include "Tier2.h"
using namespace std;

class AC2Tier : public Tier2 {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static AC2Tier *myclass;       // the singleton pointer to the class
    // constructor with default parameters
    AC2Tier(string name = "AC 2 Tier" , float loadfactor = 2.0f , bool seat = 0 , bool ac = 1 , int num_tiers = 2 , bool luxury = 0);

public:
    ~AC2Tier();
    static const AC2Tier& Type();       // returns the only singleton object of the class
    float GetLoadFactor() const;
    AC2Tier(const AC2Tier& other) = delete;
    AC2Tier& operator=(const AC2Tier& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;              // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestAC2Tier();      // unit test function for the class
    friend ostream& operator<<(ostream& os , const AC2Tier& ac2Tier);
};


#endif
