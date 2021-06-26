// Name : Suryam Arnav Kalra
// Roll No. : 19CS30050

#include<iostream>
#include "Railways.h"
#include "Station.h"
#include<vector>
#include<unordered_map>
using namespace std;

Railways::Railways() {}
Railways::~Railways() {}

Railways *Railways::myRailways = 0;

const Railways& Railways::IndianRailways() {
    if(!myRailways) {
        myRailways = new Railways();           // returns the only singleton object of the class
    }
    return *myRailways;
}

int Railways::GetDistance(Station A , Station B) const {
    for(pair<pair<Station , Station> , int> p : Railways::sDistStations) {
        if(p.first.first == A && p.first.second == B) {        // compares the stations and if they are found same 
            return p.second;                                   // returns the distance between them
        }
    }
    return 0;              // if no matching record found returns 0
}

// it stores the list of stations
const vector<Station> Railways::sStations = {Station("Mumbai") , Station("Delhi") , Station("Bangalore") , Station("Kolkata") , Station("Chennai")};

// it stores the pairwise distance between two stations
const vector<pair<pair<Station , Station> , int>> Railways::sDistStations = {
    {{Station("Mumbai") , Station("Mumbai")} , 0} , 
    {{Station("Mumbai") , Station("Delhi")} , 1447} , 
    {{Station("Mumbai") , Station("Bangalore")} , 981} , 
    {{Station("Mumbai") , Station("Kolkata")} , 2014} , 
    {{Station("Mumbai") , Station("Chennai")} , 1338} , 
    {{Station("Delhi") , Station("Mumbai")} , 1447} , 
    {{Station("Delhi") , Station("Delhi")} , 0} ,
    {{Station("Delhi") , Station("Bangalore")} , 2150} ,
    {{Station("Delhi") , Station("Kolkata")} , 1472} ,
    {{Station("Delhi") , Station("Chennai")} , 2180} , 
    {{Station("Bangalore") , Station("Mumbai")} , 981} ,
    {{Station("Bangalore") , Station("Delhi")} , 2150} ,
    {{Station("Bangalore") , Station("Bangalore")} , 0} ,
    {{Station("Bangalore") , Station("Kolkata")} , 1871} ,
    {{Station("Bangalore") , Station("Chennai")} , 350} ,
    {{Station("Kolkata") , Station("Mumbai")} , 2014} ,
    {{Station("Kolkata") , Station("Delhi")} , 1472} ,
    {{Station("Kolkata") , Station("Bangalore")} , 1871} ,
    {{Station("Kolkata") , Station("Kolkata")} , 0} ,
    {{Station("Kolkata") , Station("Chennai")} , 1659} , 
    {{Station("Chennai") , Station("Mumbai")} , 1338} ,
    {{Station("Chennai") , Station("Delhi")} , 2180} ,
    {{Station("Chennai") , Station("Bangalore")} , 350} ,
    {{Station("Chennai") , Station("Kolkata")} , 1659} ,
    {{Station("Chennai") , Station("Chennai")} , 0}
};

void Railways::UnitTestRailways() {
    Station s1("Mumbai");
    int found = 0;
    for(Station s : Railways::sStations) {
        if(s == s1) {
            found = 1;
            break;                                  // similarly can be done for other stations
        }
    }
    if(!found) {
        cout << "Mumbai station was not found !" << endl;
    }
    Station s2("Delhi");
    if(Railways::IndianRailways().GetDistance(s1 , s2) != 1447) {       // similarly can be done for other stations to get the distance
        cout << "Check your get distance function in railways class !" << endl;
    }
}