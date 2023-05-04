#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>
#include "Fraction.hpp"

using namespace std;
namespace ariel{
//~~~~~~~~~~~~~~~~Constructors~~~~~~~~~~~~~~~~~~~~~~~~~
   Fraction::Fraction(int numerator, int denominator) {

    if (denominator == 0)
        throw invalid_argument("Error: divide by zero");
    this->numerator = numerator;
    this->denominator = denominator;

    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }

    reduce();
}
Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
}

Fraction::Fraction(float num) {
    int num1 = num * 1000;
    int den1 = 1000;
    Fraction other = Fraction(num1, den1);
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
}
//~~~~~~~~~~~~~~~~Helper && Getters&& Setters functions~~~~~~~~~~~~~~~~~~~~~~~~~
    void Fraction::reduce() {
        int gcd = __gcd(abs(this->numerator), abs(this->denominator));
        this->numerator /= gcd;
        this->denominator /= gcd;
        if (this->denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        }
    }

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}

void Fraction::setNumerator(int numerator) 
{
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator can't be zero.");
    }
    this->denominator = denominator;
}
//~~~~~~~~~~~~~~~~Required functions~~~~~~~~~~~~~~~~~~~~~~~~~
Fraction Fraction ::operator+(const Fraction& other) const{
    long numCheck = (long(this -> numerator) * other.denominator) + (long(other.numerator) * this -> denominator);
    long denCheck = long(this->denominator) * other.denominator;
     if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error!! overflow, number is too big/small!! use int");
        
    }
    int denominator = this->denominator * other.denominator;
    int numerator = this->numerator * (denominator / this->denominator) + other.numerator * (denominator / other.denominator);
    return Fraction(numerator, denominator);
}
Fraction operator+(const float& num, const Fraction &Frac){
    return (Fraction(num)+Frac);
}
Fraction Fraction::operator+ (const float& number) const {
    Fraction other = Fraction(number);
    int num = (this->getNumerator() * other.getDenominator()) + (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}
Fraction Fraction ::operator-(const Fraction& other) const
{
    long numCheck = (long(this -> numerator) * other.denominator) - (long(other.numerator) * this -> denominator);
    long denCheck = long(this->denominator) * other.denominator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error!! overflow, number is too big/small!! use int");
        
    }
    int num = (this-> numerator * other.getDenominator()) - (other.getNumerator() * this -> denominator);
    int den = this -> denominator * other.getDenominator();
    return Fraction(num, den);    
}
Fraction operator-(const float& num,const Fraction &Frac){
    return (Fraction(num)-Frac);
}

Fraction Fraction::operator- (const float& number) const {
    Fraction other = Fraction(number);
    int num = (this->getNumerator() * other.getDenominator()) - (other.getNumerator() * this->getDenominator());
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const{
    long numCheck = long(this->numerator) * other.numerator;
    long denCheck = long(this->denominator) * other.denominator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error!! overflow, number is too big/small!! use int");
        
    }
    int numerator = this->numerator * other.numerator;
    int denominator = this->denominator * other.denominator;
    return Fraction(numerator, denominator);
}
Fraction operator*(const float& num,const Fraction &Frac)
{
    return (Fraction(num)*Frac);;
}

Fraction Fraction::operator* (const float& number) const {
    Fraction other = Fraction(number);
    int num = this->getNumerator() * other.getNumerator() ;
    int den = this->getDenominator() * other.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const
{
    
    if (other.getNumerator() == 0)
        throw runtime_error("Error!! can't divde by Zero!!");

    long numCheck = long(this->numerator) * other.denominator;
    long denCheck = long(this->denominator) * other.numerator;
    if (numCheck > INT_MAX || denCheck > INT_MAX || numCheck < INT_MIN || denCheck< INT_MIN) {
            throw overflow_error("Error!! overflow, number is too big/small!! use int");
        
    }
    int numerator = this->numerator * other.denominator;
    int denominator = this->denominator * other.numerator;
    return Fraction(numerator, denominator);
}
Fraction operator/(const float& num,const Fraction &Frac){
    return (Fraction(num)/Frac);
}
Fraction Fraction::operator/ (const float& number) const {
    Fraction other = Fraction(number);
    int num = (this->getNumerator() * other.getDenominator());
    int den = this->getDenominator() * other.getNumerator();

    if (other.getNumerator() == 0)
        throw std::runtime_error("Error!! can't divde by Zero!!");
        
    return Fraction(num, den);
}
bool Fraction::operator>(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 > num2;
}
bool operator>(const float& num,const Fraction &Frac)
{
    return (Fraction(num)>Frac);
}
bool Fraction :: operator>(const float& number) const
{
    Fraction other = Fraction(number);
    return *this > other;
}

bool Fraction::operator<(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 < num2;
}
bool operator<(const float& num,const Fraction &Frac)
{
    return (Fraction(num)<Frac);
}
bool Fraction :: operator<(const float& number) const
{
    Fraction other = Fraction(number);
    return *this < other;
}
bool Fraction::operator>=(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 >= num2;
}
bool operator>=(const float& num,const Fraction &Frac)
{
    return (Fraction(num)>=Frac);
}
bool Fraction :: operator>=(const float& number) const
{
    Fraction other = Fraction(number);
    return *this >= other;
}

bool Fraction::operator<=(const Fraction& other) const
{
    int mul = denominator * other.denominator;
    int num1 = numerator * (mul / denominator);
    int num2 = other.numerator * (mul / other.denominator);
    return num1 <= num2;
}
bool operator<=(const float& num,const Fraction &Frac)
{
    return (Fraction(num)<=Frac);
}
bool Fraction :: operator<=(const float& number) const
{
    Fraction other = Fraction(number);
    return *this <= other;
}
bool Fraction :: operator==(const Fraction &other) const{
    return this->numerator== other.numerator && this->denominator == other.denominator;
}
bool operator==(const float& num,const Fraction &Frac)
{
    Fraction other =Fraction(num);
    return (other==Frac);
}
bool Fraction :: operator==(const float& number) const
{
    Fraction other = Fraction(number);
    return (*this == other);
}
ostream& operator<<(ostream &output, const Fraction &fraction) {
    
    return (output << fraction.getNumerator() << '/' << fraction.getDenominator());
}
istream& operator>>(istream &input, Fraction &obj) {
    input >> obj.numerator >> obj.denominator;
    if(!input)  throw runtime_error("error : invalid input");
    if (obj.denominator < 0) {
            obj.numerator = -obj.numerator;
            obj.denominator = -obj.denominator;
    }  
    if (obj.denominator == 0)
        throw runtime_error("Denominator can't be zero.");  

    if (obj.numerator == 0)
        obj.denominator =1;
    return input;
}   
Fraction& Fraction ::operator++(){
    this ->numerator += this ->denominator;
    return *this;
    
}
Fraction Fraction::operator++(int) { 
    Fraction temp(*this);
    this->numerator += this->denominator;
    return temp; 
}
Fraction &Fraction ::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
    Fraction temp(*this);
    this->numerator -= this->denominator;
    return temp;       
}
}