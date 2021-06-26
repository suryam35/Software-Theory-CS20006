// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef AC3TIER_H
#define AC3TIER_H

#include <iostream>
#include "Tier3.h"
using namespace std;

class AC3Tier : public Tier3 {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static AC3Tier *myclass;       // the singleton pointer to the class
    // constructor with default parameters
    AC3Tier(string name = "AC 3 Tier" , float loadfactor = 1.75f , bool seat = 0 , bool ac = 1 , int num_tiers = 3 , bool luxury = 0);

public:
    ~AC3Tier();
    static const AC3Tier& Type();       // returns the only singleton object of the class
    float GetLoadFactor() const;
    AC3Tier(const AC3Tier& other) = delete;
    AC3Tier& operator=(const AC3Tier& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;              // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestAC3Tier();      // unit test function for the class
    friend ostream& operator<<(ostream& os , const AC3Tier& ac3Tier);
};


#endif