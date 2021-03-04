#include<iostream>
#include<math.h>
#include "Fraction.h"
using namespace std;


// CONSTRUCTORS
Fraction::Fraction(int p , int q) {
    if(q == 0) {
        exit(1);          // denominator is zero so not a valid fraction
    }
    if(q < 0) {
        p = -p;
        q = -q;          // denominator should be positive
    }
    if(p == 0) {
        q = 1;            // if numerator is 0 then keep the denominator to 0
    }
    num = p;
    den = q;
    int g = Fraction::gcd(abs(num) , den);      // get the gcd of numerator and denominator so that it becomes a fraction in normalized form
    num /= g , den /= g;
    //check pdf for different implementations
}

Fraction::Fraction(double d) {
    // implement precision for double value
    int pre = Fraction::precision();          // return the precision for converting double values to fraction
    num = floor(d*pre);
    den = pre;
    int g = Fraction::gcd(abs(num) , den);    // usual normalization part
    num /= g , den /= g;
}


// COPY ASSIGNMENT OPERATOR
Fraction& Fraction::operator=(const Fraction& f) {
    num = f.num;         
    den = f.den;
    return *this;      // returns this value since this fraction is made equal to another one
}


//UNARY ARITHMETIC OPERATORS
Fraction& Fraction::operator++() {       // pre-increment operator
    num += den;
    return *this;          // returns (p+q)/q
}

Fraction& Fraction::operator--() {    // pre-increment operator
    num -= den;
    return *this;          // returns (p-q)/q;
}

Fraction Fraction::operator++(int) {      // post-increment operator
    Fraction f = *this;
    num += den;     // original fraction is updated to (p+q)/q
    return f;       // returns a copy to the original fraction
}

Fraction Fraction::operator--(int) {     // post-decrement operator
    Fraction f = *this;
    num -= den;     // original fraction is updated to (p-q)/q
    return f;      // returns a copy to the original fraction
}


//BINARY ARITHMETIC OPERATORS
Fraction operator+(const Fraction& f1 , const Fraction& f2) {       // binary addition operator
    int num , den;
    num = f1.num*f2.den + f2.num*f1.den;   // adds two fractions a/b + c/d ---> (ad+bc)/bd
    den = f1.den*f2.den;
    return Fraction(num , den);      // returns a fraction object of this newly computed fraction
}

Fraction operator-(const Fraction& f1 , const Fraction& f2) {    //binary subtraction operator
    int num , den;
    num = f1.num*f2.den - f2.num*f1.den;   // subtracts two fractions a/b - c/d ---> (ad-bc)/bd
    den = f1.den*f2.den;
    return Fraction(num , den);     // returns a fraction object of this newly computed fraction
}

Fraction operator*(const Fraction& f1 , const Fraction& f2) {    // binary multiplication operator
    int num , den;
    num = f1.num*f2.num;       // multiplies two fractions a/b * c/d ---> ac/bd
    den = f1.den*f2.den;
    return Fraction(num , den);      // returns a fraction object of this newly computed fraction
}

Fraction operator/(const Fraction& f1 , const Fraction& f2) {      // binary division operator
    //throw exception
    try {
        if(f2.num == 0) {
            throw 1;       // catches the exception that the divisor is zero
        }
        int num , den;
        num = f1.num*f2.den;     // divides two fractions a/b / c/d ----> ad/bc
        den = f1.den*f2.num;
        return Fraction(num , den);     // returns a fraction object of this newly computed fraction
    }
    catch(int) {
        cout << "Division by zero , hence defaulting f3 to 1\n";     // displays exception error
    } 
    return Fraction();        // if exception occurred return a default fraction
}

Fraction operator%(const Fraction& f1 , const Fraction& f2) {     // binary residue operator
    //throw exception for zero
    try {
        if(f2.num == 0) {
            throw 1;        // catches the exception that the divisor is zero
        }
        int num , den;
        num = f1.num*f2.den;       
        den = f1.den*f2.num;
        int res = num/den;         // calculates the integer result of division
        Fraction temp = Fraction(res*f2.num , f2.den);
        Fraction ans = f1 - temp;      // finds f1 % f2  ---> f1 - (int)(f1/f2)*f2
        return ans;
    }
    catch(int) {
        cout << "Division by zero , hence defaulting f3 to 1\n";      // displays exception error
    }
    return Fraction();      // if exception occurred return a default fraction
}


// BINARY RELATIONAL OPERATORS
bool Fraction::operator==(const Fraction& f) {     // logical equal to operator
    if(num == f.num && den == f.den) {
        return true;      // if both the numerator and denominator are same then they are equal
    } 
    return false;
}

bool Fraction::operator!=(const Fraction& f) {   // logical not equal to operator
    if(num == f.num && den == f.den) {
        return false;      // if both the numerator and denominator are equal then they are equal
    }                      // and hence should return false
    return true;
}

bool Fraction::operator<(const Fraction& f) {    // logical less than operator
    if(num*f.den < den*f.num) {
        return true;        // a/b < c/d ---->  ad < bc
    }
    return false;
}

bool Fraction::operator<=(const Fraction& f) {     // logical less than equal to operator
    if(num*f.den <= den*f.num) {
        return true;     // a/b <= c/d ----> ad <= bc
    }
    return false;
}

bool Fraction::operator>(const Fraction& f) {   // logical greater than operator
    if(num*f.den > den*f.num) {
        return true;   // a/b > c/d -----> ad > bc
    }
    return false;
}

bool Fraction::operator>=(const Fraction& f) {    // logical greater than equal to operator
    if(num*f.den >= den*f.num) {
        return true;       // a/b >= c/d ----> ad >= bc
    }
    return false;
}


// SPECIAL OPERATORS
Fraction Fraction::operator!() {       // logical ! operator with new semantics
    // throw exception if num = 0
    try {
        if(num == 0) {
            throw 1;        // if num is 0 then inverse fraction does not exist
        }
        return Fraction(den , num);
    }
    catch(int) {
        cout << "Inversion of zero hence defualting to 1\n";     // exception caught
    }
    return Fraction();                                          // return default fraction if exception occurred
}


// I/O OPERATORS
ostream& operator<<(ostream& os , const Fraction& f) {       // output operator
    if(f.den == 1) {
        cout << f.num;       // this means that the fraction is a whole number
        return os;
    }
    os << f.num << " / " << f.den;       // output ---> p/q
    return os;        // return the same ostream object to enable chain output
}

istream& operator>>(istream& is , Fraction& f) {        // input operator
    int p , q;
    is >> p >> q;    // takes input the numerator and denominator
    Fraction temp(p , q);      // makes a temporary fraction so that it is normalized and well formed
    f = temp;       // make the input fraction same as this temp
    return is;    // return istream object to enable chain input
}


// STATIC CONSTANTS
Fraction Fraction::sc_fUnity = Fraction();       // unity fraction
Fraction Fraction::sc_fZero = Fraction(0);    // zero fraction


// UTILITY FUNCTIONS
int Fraction::precision() {
    return 1000;      // precision for converting the double to fraction
}

int Fraction::gcd(int x , int y) {     // function to compute the gcd of two numbers
    if(y == 0) {
        return x;        // this means that gcd is 0     
    }
    return Fraction::gcd(y , x%y);      // using euclidean gcd algorithm
}

int Fraction::lcm(int x , int y) {       // function to comput the lcm of two numbers
    int g = Fraction::gcd(x , y);
    return (x*y)/g;         // since  a*b = gcd(a,b)*lcm(a,b)
}