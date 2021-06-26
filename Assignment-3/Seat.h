// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include "BookingClasses.h"
using namespace std;

// Abstract base class deriving the abstract base class BookingClasses
// which stores the class which have seats

class Seat : public BookingClasses {
protected:
    // const bool hasSeat;
public:
    // virtual bool IsSitting() = 0;
};

#endif