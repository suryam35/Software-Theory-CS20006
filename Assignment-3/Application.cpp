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
using namespace std;

// Test application for booking
void BookingApplication() {
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

void BookingApplicationTest() {
    Booking b1(Station("Delhi"), Station("Delhi"), Date(22, 8, 2021), SecondSitting::Type());

    Booking b2(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b3(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), ACFirstClass::Type());

    Booking b4(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b5(Station("Mumbai"), Station("Kolkata"), Date(5, 3, 2021), FirstClass::Type());

    Booking b6(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b7(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());

    Booking b8(Station("Kolkata"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b9(Station("Bangalore"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());

    Booking b10(Station("Chennai"), Station("Bangalore"), Date(20, 4, 2021), ACFirstClass::Type());
    Booking b11(Station("Mumbai"), Station("Kolkata"), Date(15, 10, 2021), ACFirstClass::Type());

    Booking b12(Station("Delhi"), Station("Kolkata"), Date(7, 12, 2021), Sleeper::Type());
    Booking b13(Station("Delhi"), Station("Kolkata"), Date(23, 3, 2021), AC3Tier::Type());

    Booking b14(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b15(Station("Mumbai"), Station("Delhi"), Date(17, 10, 2021), ACFirstClass::Type());
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

void UnitTesting() {
    Date::UnitTestDate();

    Station::UnitTestStation();

    Railways::UnitTestRailways();

    Booking::UnitTestBooking();

    AC2Tier::UnitTestAC2Tier();
    AC3Tier::UnitTestAC3Tier();
    ACChairCar::UnitTestACChairCar();
    ACFirstClass::UnitTestACFirstClass();
    FirstClass::UnitTestFirstClass();
    SecondSitting::UnitTestSecondSitting();
    Sleeper::UnitTestSleeper();
}


int main() {
    BookingApplication();
    // BookingApplicationTest();
    // UnitTesting();

    delete &ACFirstClass::Type();
    delete &AC2Tier::Type();
    delete &AC3Tier::Type();
    delete &ACChairCar::Type();
    delete &FirstClass::Type();
    delete &Sleeper::Type();
    delete &SecondSitting::Type();
    delete &Railways::IndianRailways();
    return 0;
}
