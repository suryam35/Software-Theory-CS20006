// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include <iostream>
#include "Passenger.h"
#include "Date.h"
#include "Gender.h"
#include <string>
#include <algorithm>
#include "Exception.h"

Passenger::Passenger(const string firstname ,const Gender& gender, const string aadhar , Date dob  ,  string middlename  , string lastname  ,string mobileNumber  , string disabilitytype , string disabilityid) : firstName_(firstname) , middleName_(middlename) , lastName_(lastname) , aadhar_(aadhar) , dateOfBirth_(dob) , gender_(gender){
    mobileNumber_ = mobileNumber;
    disabilityType_ = disabilitytype;
    disabilityId_ = disabilityid;
}

Passenger::Passenger(const Passenger& p) : firstName_(p.firstName_) , middleName_(p.middleName_) , lastName_(p.lastName_) , aadhar_(p.aadhar_) , dateOfBirth_(p.dateOfBirth_) , gender_(p.gender_) {
    mobileNumber_ = p.mobileNumber_;
    disabilityType_ = p.disabilityType_;
    disabilityId_ = p.disabilityId_;
}

Passenger::~Passenger() {}

int Passenger::GetAge(const Date& d) const {
    return d.GetYear()-(*this).dateOfBirth_.GetYear();
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

Passenger Passenger :: Construct(const string firstname ,const Gender& gender,const string aadhar , Date dob  ,  string middlename, string lastname, string mobileNumber, string disabilitytype, string disabilityid){
    bool ok = true;
    if(!dob.IsValidDate()){         // check if dob is valid
        ok = false;
    }
    if(!is_digits(aadhar) || (aadhar.size() != 12)){      // check if aadhar is valid
        ok = false;
    }
    if((mobileNumber.size() != 10 && mobileNumber.size() != 0) || !is_digits(mobileNumber)){     // check if mobile is valid
        ok = false;
    }
    if((firstname == "" && lastname == "")){       // check if name is valid
        ok = false;
    }
    try{
        if(!ok){
            BadPassenger ex;    //throw exception if not ok
            throw ex;
        }
        else{
            Passenger *p = new Passenger(firstname , gender, aadhar , dob,  middlename, lastname, mobileNumber, disabilitytype, disabilityid);
            return *p;
        }
    }
    catch(BadPassenger &ex){
        throw;
    }
}

void Passenger :: UnitTestPassenger(){
    try{
        Passenger p1 = Passenger :: Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,1901));
        cout<<"PASSENGER CONSTRUCTION : PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER CONSTRUCTION : FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("Suryam" , Female::Type() , "123456789111" , Date::Construct(17,12,3000));
        cout<<"PASSENGER WRONG DOB (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"PASSENGER WRONG DOB (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "787658902" ,"Blind");
        cout<<"PASSENGER WRONG MOBILE LENGTH (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER WRONG MOBILE LENGTH (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "" , "787658902" ,"Blind");
        cout<<"PASSENGER EMPTY FIRST AND LAST NAME (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER EMPTY FIRST AND LAST NAME (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("Suryam" , Female::Type() , "1234a6728911" , Date::Construct(17,12,2002));
        cout<<"PASSENGER WRONG AADHAR CHARACTERS (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER WRONG AADHAR CHARACTERS (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("Suryam" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "78a7658902" ,"Blind");
        cout<<"PASSENGER WRONG MOBILE CHARACTERS (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER WRONG MOBILE CHARACTERS (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("Suryam" , Female::Type() , "12345678911" , Date::Construct(17,12,2002));
        cout<<"PASSENGER WRONG AADHAR LENGTH (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"PASSENGER WRONG AADHAR LENGTH (NEGATIVE TEST): FAILED" <<endl;
    }

}

ostream& operator<<(ostream &os , const Passenger& passenger) {
    os << "Passenger Details : \n";
    os << "Name : " << passenger.firstName_ + " "+ passenger.middleName_ + " " + passenger.lastName_ << endl;
    os << "Date of Birth : ";
    os << passenger.dateOfBirth_ << endl;
    os << "Gender : ";
    if(passenger.IsMale()) {
        os << "Male\n";
    }
    else {
        os << "Female\n";
    }
    os << "Aadhar Number : " << passenger.aadhar_<< endl;
    if(passenger.mobileNumber_ != "") {
        os << "Mobile Number : " << passenger.mobileNumber_<<endl;
    }
    if(passenger.disabilityType_ != "") {
        os << "Disability Type : " << passenger.disabilityType_<<endl;
    }
    if(passenger.disabilityId_ != "") {
        os << "Disability Id : " << passenger.disabilityId_ << endl;
    }
    return os;
}