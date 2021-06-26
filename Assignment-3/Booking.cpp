// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include <iostream>
#include <cmath>
#include "Booking.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "Railways.h"
#include "AC3Tier.h"
using namespace std;

Booking::Booking(Station A , Station B , Date d , const BookingClasses& bookingclass, Passenger *psngr, bool bookingStatus , string bookingmsg ) : fromStation_(A) , toStation_(B) , date_(d) , bookingClass(bookingclass){
    // bookingClass = bookingclass;
    passenger_ = psngr;
    bookingStatus_ = bookingStatus;
    bookingMessage_ = bookingmsg;
    PNR_ = ++Booking::sBookingPNRSerial;
    Booking::sBookings.push_back(this);
}

Booking::~Booking() {
    Booking::sBookings.pop_back();     // remove the booking from the vector
    Booking::sBookingPNRSerial = static_cast<int>(Booking::sBookings.size());    // make the pnr correct
}

float Booking::ComputeFare() const {
    if(const_cast<Station&>(fromStation_) == const_cast<Station&>(toStation_)) {
        return 0;
    }
    int distance = Railways::IndianRailways().GetDistance(fromStation_ , toStation_);     // return the distance
    float base_fare = distance * Booking::sBaseFarePerKM;       // base_fare = distance*(base fare per km)
    float loadFactor = bookingClass.GetLoadFactor();        // get the load factor
    float loaded_fare = base_fare*loadFactor;          // loaded_fare = base_Fare*loaded_factor
    if(bookingClass.IsAC()) {
        loaded_fare += Booking::sACSurcharge;      // if AC add the AC surcharge
    }
    if(bookingClass.IsLuxury()) {
        loaded_fare = loaded_fare*(1 + Booking::sLuxuryTaxPercent/100);    // if luxury add the Luxury tax
    }
    return round(loaded_fare);     // round of to the nearest integer
}

ostream& operator<<(ostream& os , const Booking& b) {
    os << "\n" << b.bookingMessage_ << ":\n";
    os << "PNR Number = " << b.PNR_ << endl;
    os << "From Station = " << b.fromStation_.GetName() << endl;
    os << "To Station = " << b.toStation_.GetName() << endl;
    os << "Travel Date = ";
    (b.date_).print();
    os << "\n";
    os << "Travel Class = " << b.bookingClass.GetName() << endl;
    if(b.bookingClass.IsSitting()) {
        os << " : Mode: Sitting\n";
    }
    else {
        os << " : Mode: Sleeping\n";
    }
    if(b.bookingClass.IsAC()) {
        os << " : Comfort: AC\n";
    }
    else {
        os << " : Comfort: Non-AC\n";
    }
    os << " : Bunks: " << b.bookingClass.GetNumberOfTiers() << endl;
    if(b.bookingClass.IsLuxury()) {
        os << " : Luxury: Yes\n";
    }
    else {
        os << " : Luxury: No\n";
    }
    os << "Fare = " << (int)(b.ComputeFare()) << endl;
    return os;
}

float Booking::sBaseFarePerKM = 0.5;
int Booking::sBookingPNRSerial = 0;
float Booking::sACSurcharge = 50.0;
float Booking::sLuxuryTaxPercent = 25.0;
vector<Booking*> Booking::sBookings;

void Booking::UnitTestBooking() {
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    if(!(b1.fromStation_ == Station("Mumbai"))) {
        cout << "Booking from station is wrong ! " << endl;
    }
    if(!(b1.toStation_ == Station("Delhi"))) {
        cout << "Booking to station is wrong !" << endl;
    }
    if(const_cast<Date&>(b1.date_ )!= Date(23,3,2021)) {
        cout << "Booking Date is wrong ! " <<endl;
    }
    if(b1.bookingStatus_ != 1) {
        cout << "Booking Status is wrong !" << endl;
    }
    if(b1.bookingMessage_ != "BOOKING SUCCEEDED") {
        cout << "Booking Message is wrong !" << endl;
    }
    // since unit tests have been done for the derived classes
    // no need to test for b1.bookingclass
}