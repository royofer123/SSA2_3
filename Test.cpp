#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>


using namespace std;
using namespace ariel;


TEST_CASE("Fraction constructor should handle zero as the denominator")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(-1, 0));
    CHECK_THROWS(Fraction(0, 0));
}

TEST_CASE("Checking the constructors") {
    Fraction a(1,4);
    Fraction b(5,3);
    Fraction c(0.4);
    Fraction d(0.5);
    CHECK(a.getNumerator() == 1);
    CHECK(b.getNumerator() == 5);
    CHECK(a.getDenominator() == 4);
    CHECK(b.getDenominator() == 3);
    CHECK(c==0.4);
    CHECK(d==0.5);
}


TEST_CASE("Check functions add and sub") {
    Fraction a(2,4);
    Fraction b(1,4);

    CHECK((a+b) == Fraction(3,4));
    CHECK((a-b) == Fraction(1,4));
}

TEST_CASE("Check functions add and sub-diffrent demonaitor ") {
    Fraction a(1,4);
    Fraction b(1,8);
    CHECK((a+b) == Fraction(3,8));
    CHECK((a-b) == Fraction(1,8));
}

TEST_CASE("Check functions add and sub- difficult") {
    Fraction a(1,4);
    Fraction b(1,3);

    Fraction sum(7,12);
    Fraction ans = a+b;
    CHECK(ans == sum);
    CHECK_NOTHROW(a+b);
    CHECK(a+2.1 == (2.35));
    CHECK(a-0.25 == (1/4));

}

TEST_CASE("Check multiplication and division") {
    Fraction a(1,4);
    Fraction b(2,4);

    Fraction ans = a*b;
    
    CHECK((a*b) == Fraction(1,8));
    CHECK((b/a) == Fraction(2));
}

TEST_CASE("Denominator cannot be zero") {
    Fraction frc(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(frc.setDenominator(0));

}

TEST_CASE("Fraction should be reduced") {
    CHECK(Fraction(4,8) == Fraction(1,2));
    CHECK(Fraction(0/1) == Fraction(0,2));
}

TEST_CASE("Make sure setting works properly") {
    Fraction a(1,4);
    Fraction b(5,3);

    CHECK_NOTHROW(a.setNumerator(5));
    CHECK(a.getNumerator() == 5);
    CHECK_NOTHROW(b.setDenominator(5));
    CHECK(b.getDenominator() == 5);
}

TEST_CASE("Make sure ++ and -- work properly on both sides") {
    Fraction a(1,4);
    Fraction b(5,3);

    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(a--);
    CHECK_NOTHROW(++b);
    CHECK_NOTHROW(--b);

    Fraction c(2,4);
    Fraction d(9,3);
    CHECK( c++ == Fraction(1,2));
    CHECK( d-- == Fraction(3,1));
    CHECK( ++c == Fraction(5,2));
    CHECK( --d == Fraction(1,1));

}

TEST_CASE("Check the reduce function") {
    Fraction a(2,4);
    Fraction b(9,3);

    a.reduction();
    b.reduction();

    CHECK( a == Fraction(1,2));
    CHECK( b == Fraction(3,1));

}

TEST_CASE("Check all multiplications") {
    Fraction a(2,4);
    Fraction b(9,3);

    CHECK( a*2 == Fraction(2,2));
    CHECK( 4*b == Fraction(12,1));
}

TEST_CASE("Test comparisons") {
    Fraction a(1,2);
    Fraction b(9,3);

    CHECK(a < 0.51);
    CHECK(a > 0.25);

    CHECK(b++ <= 4.1);
    CHECK(--b >= -1.2);

}
