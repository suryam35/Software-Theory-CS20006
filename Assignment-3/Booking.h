// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include <vector>
#include "Date.h"
#include "Station.h"
#include "BookingClasses.h"
#include "Passenger.h"
using namespace std;

class Booking {
    int PNR_;
    Station fromStation_;
    Station toStation_;
    const Date date_;
    const BookingClasses& bookingClass;
    bool bookingStatus_;
    string bookingMessage_;
    Passenger *passenger_;
public:
    static float sBaseFarePerKM;         // base fare per km
    static vector<Booking*> sBookings;   // stores the booking made so far
    static int sBookingPNRSerial;
    static float sACSurcharge;
    static float sLuxuryTaxPercent;
    Booking(Station A , Station B , Date d , const BookingClasses& bookingclass , Passenger *psngr = 0 , bool bookingStatus = 1 , string bookingmsg = "BOOKING SUCCEEDED");
    Booking(const BookingClasses& booking) = delete;
    Booking& operator=(const Booking& other) = delete;
    virtual ~Booking();       // destructor made virtual to avoid slicing
    virtual float ComputeFare() const;      // made virtual in case polymorphic hierarchy is to be created
    friend ostream& operator<< (ostream& os, const Booking& b);
    static void UnitTestBooking();
};

#endif // BOOKING_H