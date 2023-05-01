
#include "Fraction.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;
namespace ariel{
    int Fraction::gcd(int num1,int num2){
       return num2 == 0 ? num1 : gcd(num2, num1 % num2);
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
     if (denominator == 0){
        throw invalid_argument("Denominator can't be 0");
    }
    if (numerator > INT_MAX || denominator > INT_MAX){
        throw overflow_error("Num is too large, should be an int");
    }
    if (denominator < 0){
        this ->numerator = -1* numerator;
        this ->denominator = -1 * denominator;
    }
    else{
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    reduction();

} 
Fraction::Fraction(float numerator) {
    this -> numerator = round(numerator*1000);
    this -> denominator = 1000;
    reduction();
}

    void Fraction::setNumerator(int numerator){
        this->numerator=numerator;
    }
    void Fraction::setDenominator(int denominator){
        if(denominator!=0) this->denominator=denominator;
        else throw invalid_argument("Denominator can't be 0");
    }
    int Fraction::getDenominator ()const{
        return denominator;
    }
    int Fraction::getNumerator ()const{
        return numerator;
    }          
    Fraction Fraction::operator+(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator+(const float &num) const{
        return *this + Fraction(num);
    }
    Fraction operator+(const float &num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction:: operator-(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator-(const float &num) const{
        return Fraction(1, 2);
    }
    Fraction operator-(const float &num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction:: operator*(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator*(const float &num) const{
        return Fraction(1, 2);
    }
    Fraction operator*(const float &num, const Fraction &other){
        return Fraction(1, 2);
    }

    Fraction Fraction::operator/(const Fraction &other) const{
        return Fraction(1, 2);
    }
    Fraction Fraction::operator/(const float &num) const{
        return Fraction(1, 2);
    }
    Fraction operator/(const float &num, const Fraction &other){
        return Fraction(1, 2);
    }

    bool Fraction::operator==(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator==(const float &num) const{
        return true;
    }
    bool operator==(const float &num, const Fraction &other){
        return true;
    }

    bool Fraction::operator>(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator>(const float &num) const{
        return true;
    }
    bool operator>(const float &num, const Fraction &other){
        return true;
    }

    bool Fraction::operator<(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator<(const float &num) const{
        return true;
    }
    bool operator<(const float &num, const Fraction &other){
        return true;
    }

    bool Fraction::operator>=(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator>=(const float &num) const{
        return true;
    }
    bool operator>=(const float &num, const Fraction &other){
        return true;
    }

    bool Fraction:: operator<=(const Fraction &other) const{
        return true;
    }
    bool Fraction::operator<=(const float &num) const{
        return true;
    }
    bool operator<=(const float &num, const Fraction &other){
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

std::ostream &operator<<(ostream &output, const Fraction &fraction) {
        output << fraction.numerator << '/' << fraction.denominator;
        return output;
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
}




