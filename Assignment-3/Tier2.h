// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef TIER2_H
#define TIER2_H
#include <iostream>
#include "Berth.h"


// Abstract base class derived from the abstract base class Berth
// it stores the number of tiers for the class which in this case is 2

class Tier2 : public Berth {
protected:
    // const int numberOfTiers;
public:
    // virtual int GetNumberOfTiers() const = 0;
};


#endif