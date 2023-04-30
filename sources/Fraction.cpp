#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace std;
using namespace ariel ;
    int Fraction::gcd(int a,int b){
        if (b == 0)
            return a;
        if (a < b)
            return gcd(a, b % a);
        else
            return gcd(b, a % b);
    }
    Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
    }
    void Fraction:: reduction(){
     int GCD=gcd(numerator,denominator);
     numerator=numerator/GCD;
     denominator=denominator/GCD;   
    }

    Fraction::Fraction(int numerator, int denominator){
       if(denominator==0) throw invalid_argument("Cannot divide by zero");
        reduction();  
    }
    Fraction::Fraction(double number){

    }
    void Fraction::setNumerator(int){}
    void Fraction::setDenominator(int){}
    int Fraction::getDenominator ()const{
        return denominator;
    }
    int Fraction::getNumerator ()const{
        return numerator;
    }          
    Fraction Fraction::operator+(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator+(const float num) const{
        return Fraction(1, 2);
    }
    Fraction operator+(const float num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction:: operator-(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator-(const float num) const{
        return Fraction(1, 2);
    }
    Fraction operator-(const float num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction:: operator*(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator*(const float num) const{
        return Fraction(1, 2);
    }
    Fraction operator*(const float num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction::operator/(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator/(const float num) const{
        return Fraction(1, 2);
    }
    Fraction operator/(const float num, const Fraction &other){
        return Fraction(1, 2);
    }

    bool Fraction::operator==(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator==(const float num) const{
        return true;
    }
    bool operator==(const float num, const Fraction &other){
        return true;
    }

    bool Fraction::operator>(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator>(const float num) const{
        return true;
    }
    bool operator>(const float num, const Fraction &other){
        return true;
    }

    bool Fraction::operator<(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator<(const float num) const{
        return true;
    }
    bool operator<(const float num, const Fraction &other){
        return true;
    }

    bool Fraction::operator>=(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator>=(const float num) const{
        return true;
    }
    bool operator>=(const float num, const Fraction &other){
        return true;
    }

    bool Fraction:: operator<=(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator<=(const float num) const{
        return true;
    }
    bool operator<=(const float num, const Fraction &other){
        return true;
    }

    Fraction &Fraction::operator++(){
        return *this;
    }
    Fraction Fraction::operator++(int){
        return Fraction(1,2);
    }
        
    Fraction &Fraction::operator--(){
        return *this;
     } 
    Fraction Fraction::operator--(int){
         return Fraction(1,2);
    }

std::ostream& operator<<(std::ostream& output, const Fraction& fraction){
    return (output << fraction.numerator<< '/' << fraction.denominator);
}

std::istream& operator>>(std::istream& inpt, Fraction& frc){
    int numerator, denominator;
    if (inpt.peek() == EOF){
        throw std::runtime_error ("No numbers entred!");
    }
    inpt >> numerator;
    if (inpt.peek() == EOF){
        throw std::runtime_error ("Please add another number");
    }
    inpt >> denominator;
    if (denominator < 0){
        numerator = -1* numerator;
        denominator = -1 * denominator;
    }
    frc.setNumerator(numerator);
    frc.setDenominator(denominator);
	return inpt;
}



