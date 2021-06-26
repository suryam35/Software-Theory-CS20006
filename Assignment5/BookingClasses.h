// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef BOOKINGCLASSES_H
#define BOOKINGCLASSES_H
#include <iostream>
using namespace std;

class BookingClasses {
protected:
    float loadFactor_;
    string name_;
public:
    virtual float GetLoadFactor() const = 0;
    virtual string GetName() const = 0;
    virtual bool IsAC() const = 0;       // they are made const since a const object of the class may be calling them
    virtual bool IsLuxury() const = 0;
    virtual bool IsSitting() const = 0;
    virtual int GetNumberOfTiers() const = 0;
    virtual int GetReservationCharge() const = 0;
    virtual int GetMinimumTatkalCharge() const = 0;
    virtual int GetMaximumTatkalCharge() const = 0;
    virtual int GetMinimumTatkalDistance() const = 0;
    virtual void ChangeLoadFactor() const {return;}    // for future in case we need to change the load factor of the class
};

#endif // BOOKINGCLASSES_H
