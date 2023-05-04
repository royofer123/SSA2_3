#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

using namespace std;
namespace ariel{

    class Fraction{

    private:

    int numerator;
    int denominator;

    public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(float number);
    
    void setNumerator(int numerator);
    void setDenominator(int denominator) ;
    int getNumerator() const;
    int getDenominator()const;
    void checkOverFlowLong(long lng1, long lng2) const;
    void reduction(); 

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

    friend bool operator>=(const float num, const Fraction &other);
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
    };
};
#endif //FRACTION_HPP