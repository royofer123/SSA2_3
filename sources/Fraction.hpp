#ifndef Fraction_HPP
#define Fraction_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel {
    class Fraction{
        
        int numerator;
        int denominator;


        public:

        Fraction (int numerator,int denominator);
        Fraction();
        Fraction(float number);
        void reduce();

        Fraction operator+(const Fraction& other) const;
        Fraction operator+(const float& number) const;
        friend Fraction operator+(const float& number, const Fraction& other);

        Fraction operator-(const Fraction& other) const;
        Fraction operator-(const float& num) const;
        friend Fraction operator-(const float& num, const Fraction& other);

        Fraction operator*(const Fraction& other) const;
        Fraction operator*(const float& num) const;
        friend Fraction operator*(const float& num, const Fraction& other);

        Fraction operator/(const Fraction& other) const;
        Fraction operator/(const float& num) const;
        friend Fraction operator/(const float& num, const Fraction& other);

        bool operator==(const Fraction& other) const;
        bool operator==(const float& num) const;
        friend bool operator==(const float& num, const Fraction& other);

        bool operator>(const Fraction& other) const;
        bool operator>(const float& num) const;
        friend bool operator>(const float& num, const Fraction& other);

        friend bool operator<(const float &num, const Fraction &other);
        bool operator<(const Fraction &other) const;
        bool operator<(const float &num) const;

        friend bool operator>=(const float& num, const Fraction &other);
        bool operator>=(const float &num) const;
        bool operator>=(const Fraction &other) const;

        friend bool operator<=(const float &num, const Fraction &other);
        bool operator<=(const Fraction &other) const;
        bool operator<=(const float &num) const;

        Fraction &operator++();  
        Fraction operator++(int);
        Fraction &operator--();  
        Fraction operator--(int);

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& inpt, Fraction& fraction);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator); 
 };
}
#endif