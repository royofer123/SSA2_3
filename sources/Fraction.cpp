#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

using namespace ariel ;
    int Fraction::gcd(int a, int b){
        if (b == 0)
            return a;
        if (a < b)
            return gcd(a, b % a);
        else
            return gcd(b, a % b);
    }
    Fraction::Fraction(int numerator, int denominator){
        if(denominator==0) throw "Cant divide by zero!! ";
        int GCD=gcd(numerator,denominator);
        this->numerator=numerator/GCD;
        this->denominator=denominator/GCD;
    }
    Fraction::Fraction(double number){

    }
    void Fraction::setNumerator(int){}
    void Fraction::setDenominator(int){}
    int Fraction::getDenominator ()const{}
    int Fraction::getNumerator ()const{}
    int Fraction::gcd(int a,int b){}          
    Fraction Fraction::operator-(Fraction& other){}
    double Fraction::operator-(double f){}
    Fraction Fraction::operator+(Fraction& other){}
    double Fraction:: operator+(double num){}
    Fraction Fraction:: operator/( Fraction& other){} 
    Fraction operator*(Fraction& other){}
    double Fraction:: operator*(double f){}  
    Fraction operator*(double f, const Fraction &frac){}   
    bool Fraction::operator==(const Fraction& other) const{} 
    bool Fraction::operator!=(const Fraction& other) const{}  
    bool Fraction::operator<(const Fraction& other) const{} 
    bool Fraction::operator>(const Fraction& other) const{} 
    bool Fraction::operator<=(const Fraction& other) const{}
    bool Fraction::operator>=(const Fraction& other) const{} 
    Fraction& Fraction::operator++(){}   
    Fraction& Fraction::operator--(){}   
    Fraction Fraction::operator++(int){}   
    Fraction Fraction::operator--(int){}   
    std::ostream& operator<<(std::ostream& out, const Fraction& fraction){}   
    std::istream& operator>>(std::istream& in, Fraction& fraction){}  


