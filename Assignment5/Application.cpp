// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include<iostream>
#include "Date.h"
#include "Station.h"
#include "Passenger.h"
#include "Booking.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "SecondSitting.h"
#include "FirstClass.h"
#include "ACChairCar.h"
#include "FirstClass.h"
#include "Sleeper.h"
#include "AC3Tier.h"
#include "AC2Tier.h"
#include "ACFirstClass.h"
#include "ExecutiveChairCar.h"
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
#include "Exception.h"
using namespace std;

// Test application for booking
void BookingApplication() {
    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        Booking *b2 = Booking::ReserveBooking(Station::Construct("Mumbai") , Station::Construct("Delhi")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        // multiple booking -> same date of booking -> same passenger
        cout<<"MUTIPLE BOOKING WITH SAME PASSENGER : PASSED"<<endl;
    }
    catch(...){
        cout<<"MUTIPLE BOOKING WITH SAME PASSENGER : FAILED"<<endl;
    }
    
    try{
        Booking *b3 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b4 = Booking::ReserveBooking(Station::Construct("Kolkata") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple booking -> same date of booking -> different passenger
        cout<<"MULTIPLE BOOKING WITH SAME DOB(BOOKING) FOR DIFFERENT PASSENGER : PASSED"<<endl; 
    }
    catch(...){
        cout<<"MULTIPLE BOOKING WITH SAME DOB(BOOKING) FOR DIFFERENT PASSENGER : FAILED"<<endl;  
    }
    
    try{
        Booking *b5 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b6 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , Cancer::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // // multiple bookings -> same date of reservation -> same passenger
        cout<<"MULTIPLE BOOKING WITH SAME DOR(RESERVATION) FOR SAME PASSENGER : PASSED"<<endl;
    }
    catch(...){
        cout<<"MULTIPLE BOOKING WITH SAME DOR(RESERVATION) FOR SAME PASSENGER : FAILED"<<endl;
    }

    try{
        Booking *b7 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b8 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Bangalore")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple bookings -> same date of reservation -> different passenger
        cout<<"MULTIPLE BOOKING WITH SAME DOR(RESERVATION) FOR DIFFERENT PASSENGER : PASSED"<<endl;
    }
    catch(...){
        cout<<"MULTIPLE BOOKING WITH SAME DOR(RESERVATION) FOR DIFFERENT PASSENGER : FAILED"<<endl;
    }
    
    try{
        Booking *b9 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        Booking *b10 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , General::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // multiple bookings from the same departure station
        cout<<"MULTIPLE BOOKING FROM SAME DEPARTURE STATION : PASSED"<<endl;
    }
    catch(...){
        cout<<"MULTIPLE BOOKING FROM SAME DEPARTURE STATION : FAILED"<<endl;
    }
    
    try{
        Booking *b11 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b12 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Kolkata")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple bookings to the same arrival station
        cout<<"MULTIPLE BOOKING TO SAME ARRIVAL STATION : PASSED" <<endl;
    }
    catch(...){
        cout<<"MULTIPLE BOOKING TO SAME ARRIVAL STATION : FAILED" <<endl;
    }

    try{
        Booking *b13 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        Booking *b14 = Booking::ReserveBooking(Station::Construct("Bangalore") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Cancer::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // multiple bookings for the same booking class
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CLASS : PASSED"<<endl;
    }
    catch(...){
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CLASS : FAILED"<<endl;
    }
    
    try
    {
        Booking *b15 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b16 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Bangalore")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple booking for same booking category
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CATEGORY : PASSED"<<endl;
    }
    catch(...)
    {
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CATEGORY : FAILED"<<endl;
    }
    
    try{
        Booking *b17 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456781119" , Date::Construct(17,12,1901)));
        Booking *b18 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , General::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456781119" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // different booking class for same set of stations
        cout<<"DIFFERENT BOOKING FOR SAME SET OF STATION : PASSED"<<endl;
    }
    catch(...){
        cout<<"DIFFERENT BOOKING FOR SAME SET OF STATION : FAILED"<<endl;
    }
    
    try{
        Booking *b19 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b20 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // different booking category for same set of stations
        cout<<"DIFFERENT BOOKING CATEGORY FOR SAME SET OF STATION : PASSED"<<endl;
    }
    catch(...){
        cout<<"DIFFERENT BOOKING CATEGORY FOR SAME SET OF STATION : FAILED"<<endl;
    }
    
    try{
        Booking *b21 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(21 , 3 , 2021) , Date::Construct(13,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123451116789" , Date::Construct(17,12,2001)));
        Booking *b22 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Suryam" , Male::Type() , "123451116789" , Date::Construct(17,12,2001)));
        // fare independent of date
        if(b21->ComputeFare() != b22->ComputeFare())
            throw 1;
        cout<<"FARE INDEPENDENT OF DATE : PASSED"<<endl;
    }
    catch(int){
        cout<<"FARE INDEPENDENT OF DATE : FAILED"<<endl;
    }
    
    try{
        Booking *b23 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "121113456789" , Date::Construct(17,12,1901)));
        Booking *b24 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC2Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "121113456789" , Date::Construct(17,12,1901)));
        if(b23->ComputeFare() == b24->ComputeFare())
            throw 1;
        cout<<"FARE DEPENDENT ON BOOKING CLASS : PASSED"<<endl;
    }
    catch(...){
        cout<<"FARE DEPENDENT ON BOOKING CLASS : FAILED"<<endl;
    }

    try{
        Booking *b25 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456711189" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        Booking *b26 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Cancer::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456711189" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        if(b25->ComputeFare() == b26->ComputeFare())
            throw 1;
        cout<<"FARE DEPENDENT ON BOOKING CATEGORY : PASSED"<<endl;
    }
    catch(...){
        cout<<"FARE DEPENDENT ON BOOKING CATEGORY : FAILED"<<endl;
    }

    try{
        Booking *b27 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123456111789" , Date::Construct(17,12,1901)));
        Booking *b28 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Female::Type() , "123456111789" , Date::Construct(17,12,1901)));
        
        if(b27->ComputeFare() == b28->ComputeFare())
            throw 1;

        cout<<"FARE DEPENDENT ON PASSENGER GENDER : PASSED"<<endl;
    }
    catch(...){
        cout<<"FARE DEPENDENT ON PASSENGER GENDER : FAILED"<<endl;
    }
    
    try{
        Booking *b29 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123411156789" , Date::Construct(17,12,1951)));
        Booking *b30 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Suryam" , Male::Type() , "123411156789" , Date::Construct(17,12,2002)));
    
        if(b29->ComputeFare() == b30->ComputeFare())
            throw 1;
        cout<<"FARE DEPENDENT ON PASSENGER AGE : PASSED"<<endl;
    }
    catch(...){
        cout<<"FARE DEPENDENT ON PASSENGER AGE : FAILED"<<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("Suryam" , Male::Type() , "111123456789" , Date::Construct(17,12,2001), "Arnav", "Kalra", "7877474747","Cancer");
        Passenger p2 = Passenger::Construct("Suryam" , Male::Type() , "111123456789" , Date::Construct(17,12,2001), "Arnav", "Kalra", "7877474747","Blind");
        Booking *b31 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Cancer::Type() , p1);
        Booking *b32 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Blind::Type() , p2);
        if(b31->ComputeFare() == b32->ComputeFare())
            throw 1;
        cout<<"FARE DEPENDENT ON PASSENGER DISABILITY : PASSED"<<endl;
    }
    catch(...){
        cout<<"FARE DEPENDENT ON PASSENGER DISABILITY : FAILED"<<endl;
    }

    try{
        Booking *b33 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Handicapped::Type() , Passenger::Construct("Suryam" , Male::Type() , "111123456789" , Date::Construct(17,12,3000)));
        
        cout<<"BOOKING WITH WRONG PASSENGER DOB(BIRTH) (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"BOOKING WITH WRONG PASSENGER DOB(BIRTH) (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b34 = Booking::ReserveBooking(Station::Construct("") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Handicapped::Type() , Passenger::Construct("Suryam" , Male::Type() , "111123456789" , Date::Construct(17,12,2002)));
        
        cout<<"BOOKING WITH WRONG STATION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"BOOKING WITH WRONG STATION (NEGATIVE TEST) : FAILED"<<endl;
    }
    
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

void UnitTesting() {
    cout << "**** UNIT TEST FOR DATE ****";
    Date::UnitTestDate();
    cout << "\n**** UNIT TEST FOR STATION ****";
    Station::UnitTestStation();
    cout << "\n**** UNIT TEST FOR PASSENGER ****";
    Passenger::UnitTestPassenger();
    cout << "\n**** UNIT TEST FOR RAILWAYS ****";
    Railways::UnitTestRailways();
    cout << "\n**** UNIT TEST FOR BOOKING ****";
    Booking::UnitTestBooking();
    AC2Tier::UnitTestAC2Tier();
    ExecutiveChairCar::UnitTestExecutiveChairCar();
    AC3Tier::UnitTestAC3Tier();
    ACChairCar::UnitTestACChairCar();
    ACFirstClass::UnitTestACFirstClass();
    FirstClass::UnitTestFirstClass();
    SecondSitting::UnitTestSecondSitting();
    Sleeper::UnitTestSleeper();
}


int main() {
    BookingApplication();
    // UnitTesting();

    delete &ACFirstClass::Type();
    delete &AC2Tier::Type();
    delete &ExecutiveChairCar::Type();
    delete &AC3Tier::Type();
    delete &ACChairCar::Type();
    delete &FirstClass::Type();
    delete &Sleeper::Type();
    delete &SecondSitting::Type();
    delete &Railways::IndianRailways();
    return 0;
}
