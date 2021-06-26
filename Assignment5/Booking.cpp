// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include <iostream>
#include <cmath>
#include "Booking.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "Railways.h"
#include "Gender.h"
#include "BookingCategory.h"
#include "Tatkal.h"
#include "PremiumTatkal.h"
#include "General.h"
#include "SeniorCitizen.h"
#include "Ladies.h"
#include "Blind.h"
#include "TB.h"
#include "Cancer.h"
#include "Handicapped.h"
#include "AC3Tier.h"
#include "Exception.h"
using namespace std;

Booking* Booking::ReserveBooking(Station A , Station B , Date d1 , Date d2 , const BookingClasses& bookingclass , const BookingCategory& bookingcategory, Passenger psngr , bool bookingStatus, string bookingmsg) {
    bool ok = true;
    int counter = 1;
    
    // check if from station is present in the railways
    for(Station s : Railways::sStations) {
        if(s.GetName() == A.GetName()) {
            counter = 0;
            break;
        }
    }
    
    if(counter) ok = false;

    counter = 1;

    // check if to station is present in the railways
    for(Station s : Railways::sStations) {
        if(s.GetName() == B.GetName()) {
            counter = 0;
            break;
        }
    }
    
    if(counter) ok = false;

    counter = 1;

    // check if the distance between these two stations is present in the railways
    for(pair<pair<Station,Station> , int> p : Railways::sDistStations) {
        if((p.first.first.GetName() == A.GetName() && p.first.second.GetName() == B.GetName()) || (p.first.first.GetName() == B.GetName() && p.first.second.GetName() == A.GetName())) {
            counter = 0;
            break;
        }
    }

    if(counter) ok = false;

    // check if date of booking > date of reservation
    if(d2 > d1) ok = false;

    // check if date of reservation is within one year
    if(d1.GetYear() - d2.GetYear() > 1) ok = false;
    
    try{
        if(!ok){     // if booking is not ok then throw exception
            BadBooking ex;
            throw ex;
        }
        else{
            return bookingcategory.CreateBooking(A , B , d1 , d2 , psngr ,  bookingclass);
        }
    }
    catch(BadBooking &ex){
        throw;
    }    
    return bookingcategory.CreateBooking(A , B , d1 , d2 , psngr ,  bookingclass);
}

Booking::Booking(Station A , Station B , Date d1 , Date d2, const BookingClasses& bookingclass, Passenger psngr, bool bookingStatus , string bookingmsg ) : fromStation_(A) , toStation_(B) , dateOfBooking_(d1) , dateOfReservation_(d2) , bookingClass(bookingclass) , passenger_(psngr){
    // bookingClass = bookingclass;
    bookingStatus_ = bookingStatus;
    bookingMessage_ = bookingmsg;
    PNR_ = ++Booking::sBookingPNRSerial;
    Booking::sBookings.push_back(this);
}

Booking::~Booking() {
    Booking::sBookings.pop_back();     // remove the booking from the vector
    Booking::sBookingPNRSerial = static_cast<int>(Booking::sBookings.size());    // make the pnr correct
}


ostream& operator<<(ostream& os , const Booking& b) {
    os << "\n" << b.bookingMessage_ << ":\n";
    os << "PNR Number = " << b.PNR_ << endl;
    os << "From Station = " << b.fromStation_.GetName() << endl;
    os << "To Station = " << b.toStation_.GetName() << endl;
    os << "Travel Date = ";
    (b.dateOfBooking_).print();
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
    os << b.passenger_<<endl;
    return os;
}

float Booking::sBaseFarePerKM = 0.5;
int Booking::sBookingPNRSerial = 0;
float Booking::sACSurcharge = 50.0;
float Booking::sLuxuryTaxPercent = 25.0;
vector<Booking*> Booking::sBookings;

void Booking::UnitTestBooking() {
    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"CORRECT BOOKING: PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"CORRECT BOOKING: FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"BOOKING DUE TO WRONG FROM STATION(NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"BOOKING DUE TO WRONG FROM STATION(NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,02,2020) , Date::Construct(17 , 3 , 2002) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2005)));
        cout<<"BOOKING WITH DOR(RESERVATION) < DOB(BIRTH) (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"BOOKING WITH DOR(RESERVATION) < DOB(BIRTH) (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2020) , Date::Construct(17 , 3 , 2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"BOOKING WITH DOR(RESERVATION) > DOB(BOOKING) (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"BOOKING WITH DOR(RESERVATION) > DOB(BOOKING) (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"BOOKING DUE TO WRONG END STATION(NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"BOOKING DUE TO WRONG END STATION(NEGATIVE TEST) : FAILED"<<endl;
    }

    Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
    for(auto p : Railways::sDistStations) {
        if((p.first.first.GetName() == "Delhi" && p.first.second.GetName() == "Mumbai") || (p.first.first.GetName() == "Mumbai" && p.first.second.GetName() == "Delhi")) {        // compares the stations and if they are found same 
            if(p.second == 0){
                cout<<"BOOKING DUE TO NO DISTANCE BETWEEN STATION(NEGATIVE TEST) : PASSED"<<endl;
            }
            else{
                cout<<"BOOKING DUE TO NO DISTANCE BETWEEN STATION (NEGATIVE TEST) : FAILED"<<endl;
            }                                  
        }
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,02,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,3000)));
        cout<<"BOOKING WITH WRONG PASSENGER DOB (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"BOOKING WITH WRONG PASSENGER DOB (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123459111" , Date::Construct(17,12,2001)));
        cout<<"BOOKING WITH WRONG PASSENGER CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"BOOKING WITH WRONG PASSENGER CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

}
