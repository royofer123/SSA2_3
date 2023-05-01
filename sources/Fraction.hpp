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
    int gcd(int num1,int num2);
    void reduction();          
  
    Fraction operator+(const Fraction &other) const;
    Fraction operator+(const float &number) const;
    friend Fraction operator+(const float &number, const Fraction &other);

    Fraction operator-(const Fraction &other) const;
    Fraction operator-(const float &num) const;
    friend Fraction operator-(const float &num, const Fraction &other);

    Fraction operator*(const Fraction &other) const;
    Fraction operator*(const float &num) const;
    friend Fraction operator*(const float &num, const Fraction &other);

    Fraction operator/(const Fraction &other) const;
    Fraction operator/(const float &num) const;
    friend Fraction operator/(const float &num, const Fraction &other);

    bool operator==(const Fraction &other) const;
    bool operator==(const float &num) const;
    friend bool operator==(const float &num, const Fraction &other);

    bool operator>(const Fraction &other) const;
    bool operator>(const float &num) const;
    friend bool operator>(const float &num, const Fraction &other);

    bool operator<(const Fraction &other) const;
    bool operator<(const float &num) const;
    friend bool operator<(const float &num, const Fraction &other);

    bool operator>=(const Fraction &other) const;
    bool operator>=(const float &num) const;
    friend bool operator>=(const float &num, const Fraction &other);

    bool operator<=(const Fraction &other) const;
    bool operator<=(const float &num) const;
    friend bool operator<=(const float &num, const Fraction &other);

    Fraction &operator++();  
    Fraction operator++(int);
    Fraction &operator--();  
    Fraction operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& inpt, Fraction& fraction);
    };
};
#endif //FRACTION_HPP