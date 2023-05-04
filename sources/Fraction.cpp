
#include "Fraction.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;
namespace ariel{
//~~~~~~~~~~~~~~~~~~~~~Constructors~~~~~~~~~~~~~~~~~~~
    Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
    }
    Fraction::Fraction(int numerator, int denominator){
     if (denominator == 0){
        throw invalid_argument("Denominator can't be 0");
    }
    if (numerator > INT_MAX || denominator > INT_MAX || numerator < INT_MIN || denominator < INT_MIN){
        throw overflow_error("Value is too large or too small, should be an int");
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
Fraction::Fraction(float number) {
    int tempNumerator=number;
    int tempDenominator=1000;
    Fraction tempFrac= Fraction(tempNumerator,tempDenominator);
    this->numerator=tempFrac.getNumerator();
    this->denominator=tempFrac.getNumerator();
}
 //~~~~~~~~~~~~~~~~~~~~~Helper Functions~~~~~~~~~~~~~~~~~
    void Fraction:: reduction(){
    int gcd = __gcd(abs(this->numerator), abs(this->denominator));
        this->numerator /= gcd;
        this->denominator /= gcd;
        if (this->denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        }
    }

    void Fraction::checkOverFlowLong(long lng1, long lng2) const{
        if(lng1>INT_MAX||lng1<INT_MIN||lng2>INT_MAX||lng2<INT_MIN)
            throw overflow_error("error : overflow");
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
    //~~~~~~~~~~~~~~~~Required Functions~~~~~~~~~~~~          
    Fraction Fraction::operator+(const Fraction &other) const{
        long checkNumerator=(long)(this -> numerator * other.denominator) + (long)(other.numerator* this -> denominator);
        long checkDenominator=(long)(this->denominator * other.denominator);
        checkOverFlowLong(checkNumerator,checkDenominator);
        int newNumerator= (this->numerator*other.denominator)+(other.numerator*this->denominator);
        int newDenominator=this->numerator*other.numerator;
        return Fraction(newNumerator,newDenominator);
    }

    Fraction Fraction::operator+(const float &num) const{
        Fraction tempFrac= Fraction(num);
        int newNumerator= (this->numerator*tempFrac.denominator)+(tempFrac.numerator*this->denominator);
        int newDenominator=this->numerator*tempFrac.numerator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction operator+(const float &num, const Fraction &other){
        return Fraction(num)+other;
    }

    Fraction Fraction:: operator-(const Fraction &other) const{
        long checkNumerator=(long)(this -> numerator * other.denominator) - (long)(other.numerator* this -> denominator);
        long checkDenominator=(long)(this->denominator * other.denominator);
        checkOverFlowLong(checkNumerator,checkDenominator);
        int newNumerator= (this->numerator*other.denominator)-(other.numerator*this->denominator);
        int newDenominator=this->numerator*other.numerator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction Fraction::operator-(const float &num) const{
        Fraction tempFrac= Fraction(num);
        int newNumerator= (this->numerator*tempFrac.denominator)-(tempFrac.numerator*this->denominator);
        int newDenominator=this->numerator*tempFrac.numerator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction operator-(const float &num, const Fraction &other){
        return Fraction(num)-other;
    }

    Fraction Fraction:: operator*(const Fraction &other) const{
        long checkNumerator=(long)(this -> numerator * other.numerator);
        long checkDenominator=(long)(this->denominator * other.denominator);
        checkOverFlowLong(checkNumerator,checkDenominator);
        int newNumerator= (this->numerator*other.numerator);
        int newDenominator=this->denominator*other.denominator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction Fraction::operator*(const float &num) const{
        Fraction tempFrac= Fraction(num);
        int newNumerator= this->numerator*tempFrac.numerator;
        int newDenominator=this->denominator*tempFrac.denominator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction operator*(const float &num, const Fraction &other){
        return Fraction(num)*other;
    }

    Fraction Fraction::operator/(const Fraction &other) const{
        if(other.numerator==0) throw runtime_error("Dividing by 0!!");
        long checkNumerator=(long)(this -> numerator * other.denominator);
        long checkDenominator=(long)(this->denominator * other.numerator);
        checkOverFlowLong(checkNumerator,checkDenominator);
        int newNumerator= (this->numerator*other.denominator);
        int newDenominator=this->denominator*other.numerator;
        return Fraction(newNumerator,newDenominator);
    }
    Fraction Fraction::operator/(const float &num) const{
        Fraction tempFrac= Fraction(num);
        if(tempFrac.getNumerator()==0) throw runtime_error ("Dividing by 0!!");
        int newNumerator= this->numerator*tempFrac.denominator;
        int newDenominator=this->denominator*tempFrac.numerator;
        return Fraction(newNumerator,newDenominator); 
    }
    Fraction operator/(float &num, const Fraction &other){
        return Fraction(num)/other;
    }

    bool Fraction::operator==(const Fraction &other) const{
        return this->numerator==other.numerator && this->denominator == other.denominator;
    }

    bool Fraction::operator==(const float &num) const{
        Fraction numFrac= Fraction(num);
        return (*this==numFrac);
    }
    bool operator==(const float &num, const Fraction &other){
        Fraction numFrac = Fraction(num);
        return other==numFrac;
    }

    bool Fraction::operator>(const Fraction &other) const{
        int mul = denominator * other.denominator;
        int Frac1 = numerator * (mul / denominator);
        int Frac2 = other.numerator * (mul / other.denominator);
        return Frac1 > Frac2;
}
    bool Fraction::operator>(const float &num) const{
         Fraction numFrac= Fraction(num);
        return (*this>numFrac);
    }
    bool operator>(const float &num, const Fraction &other){
        return Fraction(num)>other;
    }

    bool Fraction::operator<(const Fraction &other) const{
          int mul = denominator * other.denominator;
        int Frac1 = numerator * (mul / denominator);
        int Frac2 = other.numerator * (mul / other.denominator);
        return Frac1 < Frac2;
    }
    bool Fraction::operator<(const float &num) const{
        Fraction numFrac= Fraction(num);
        return (*this<numFrac);
    }
    bool operator<(const float &num, const Fraction &other){
        return Fraction(num)<other;
    }

    bool Fraction::operator>=(const Fraction &other) const{
           int mul = denominator * other.denominator;
        int Frac1 = numerator * (mul / denominator);
        int Frac2 = other.numerator * (mul / other.denominator);
        return Frac1 >= Frac2;
    }
    bool Fraction::operator>=(const float &num) const{
         Fraction numFrac= Fraction(num);
        return (*this>=numFrac);
    }
    bool operator>=(const float &num, const Fraction &other){
        return Fraction(num)>=other;
    }

    bool Fraction:: operator<=(const Fraction &other) const{
        int mul = denominator * other.denominator;
        int Frac1 = numerator * (mul / denominator);
        int Frac2 = other.numerator * (mul / other.denominator);
        return Frac1 <= Frac2;
    }
    bool Fraction::operator<=(const float &num) const{
        Fraction numFrac= Fraction(num);
        return (*this<=numFrac);
    }
    bool operator<=(const float &num, const Fraction &other){
        return Fraction(num)<=other;
    }

    Fraction &Fraction::operator++(){
        this->numerator+=this->denominator;
        return *this;
    }
    Fraction Fraction::operator++(int){
        Fraction tempFrac(*this);
        this->numerator+=this->denominator;
        return tempFrac;
    }
        
    Fraction &Fraction::operator--(){
       this->numerator-=this->denominator;
        return *this;
     } 
    Fraction Fraction::operator--(int){
          Fraction tempFrac(*this);
        this->numerator-=this->denominator;
        return tempFrac;
    }

    ostream &operator<<(ostream &output, const Fraction &fraction) {
        output << fraction.numerator << '/' << fraction.denominator;
        return output;
    }
    istream& operator>>(istream& inpt, Fraction& frc){
    int numerator, denominator;
    if (inpt.peek() == EOF){
        throw runtime_error ("No numbers entered!");
    }
    inpt >> numerator;
    if (inpt.peek() == EOF){
        throw runtime_error ("Please add another number");
    }
    inpt >> denominator;
    if (denominator < 0){
        numerator = -1* numerator;
        denominator = -1 * denominator;
    }
     if (denominator ==0) throw runtime_error("Dividing by 0!!");
    frc.setNumerator(numerator);
    frc.setDenominator(denominator);
	return inpt;
}
}




