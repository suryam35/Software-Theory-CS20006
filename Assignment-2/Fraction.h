#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;

class Fraction {
    private:
        int num;
        unsigned int den;
    public:
        inline Fraction() {num = 1 , den = 1;};      // default initialization
        inline Fraction(int p) {num = p , den = 1;};    // sets to p/1
        Fraction(int p , int q);    // sets to p/q with normalization
        Fraction(double d);    // sets double to fraction using precision
        inline Fraction(const Fraction& f) {num = f.num , den = f.den;};   // usual copy constructor -> call by reference to avoid making copy
        ~Fraction() {};     // no memory to be freed so it is an empty destructor
        Fraction& operator=(const Fraction& f);  // copy assignment operator -> call by reference to avoid making a copy , return by reference since the object can be changed
        inline Fraction operator+() {return Fraction(num , den);};// unary + operator  -> returns (+p)/q
        inline Fraction operator-() {return Fraction(-num , den);};// unary - operator  -> return (-p)/q
        Fraction& operator--();// pre decrement ---> --f        ----> return by reference since the fraction first gets changed and then is returned
        Fraction& operator++();// pre increment ---> ++f        ----> return by reference since the fraction first gets changed and then is returned
        Fraction operator++(int);// post increment ---> f++     ----> return by value since a copy of the original fraction has to be returned
        Fraction operator--(int);// post decrement ---> f--     ----> return by value since a copy of the original function has to be returned
        friend Fraction operator+(const Fraction& f1 , const Fraction& f2); // binary addition   ---> call by const reference to avoid making copies
        friend Fraction operator-(const Fraction& f1 , const Fraction& f2); // binary subtraction   ---> call by const reference to avoid making copies
        friend Fraction operator*(const Fraction&f1 , const Fraction& f2); // binary multiplication ---> call by const reference to avoid making copies
        friend Fraction operator/(const Fraction&f1 , const Fraction& f2); // binary division   ---> call by const reference to avoid making copies
        friend Fraction operator%(const Fraction& f1 , const Fraction& f2); // binary remainder ---> call by const reference to avoid making copies
        bool operator==(const Fraction& f); // logical equal to   ----> call by const reference to avoid making copy and changing it
        bool operator!=(const Fraction& f); // logical not equal to     ----> call by const reference to avoid making copy and changing it
        bool operator<(const Fraction& f); // logical less than     ----> call by const reference to avoid making copy and changing it
        bool operator<=(const Fraction& f); // logical less than equal to   ----> call by const reference to avoid making copy and changing it
        bool operator>(const Fraction& f); // logical greater than      ----> call by const reference to avoid making copy and changing it
        bool operator>=(const Fraction& f); // logical greater than equal to    ----> call by const reference to avoid making copy and changing it
        Fraction operator!();   //unary ! operator   ---> returns q/p
        friend ostream& operator<<(ostream& os , const Fraction& f);    // call by reference to avoid making copies , return by reference to enable chain output
        friend istream& operator>>(istream& is , Fraction& f);      // call by reference to avoid making copies , return by reference to enable chain input
        static Fraction sc_fUnity;       // unity fraction constant
        static Fraction sc_fZero;       // zero fraction constant
        static int precision();    // returns precision for converting double to fraction
        static int gcd(int x , int y);        // computes the gcd of the values
        static int lcm(int x ,  int y);      // computes the lcm of the values
};

#endif // end of FRACTION_H