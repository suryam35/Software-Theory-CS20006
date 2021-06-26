// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef TIER0_H
#define TIER0_H
#include <iostream>
#include "Seat.h"

// Abstract base class derived from the abstract base class Berth
// it stores the number of tiers for the class which in this case is 0


class Tier0 : public Seat {
protected:
    // const int numberOfTiers;
public:
    // virtual int GetNumberOfTiers() const = 0;
};


#endif