#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>


using namespace std;
using namespace ariel;

TEST_CASE("Check constructor"){//Checking all 3 constructors working with no errors
    CHECK_NOTHROW(Fraction frac);
    CHECK_NOTHROW(Fraction (0.8));
    CHECK_NOTHROW(Fraction (1,2));
}
TEST_CASE("Dividing by zero"){//Checking erros from dividing by zero
    CHECK_THROWS(Fraction(3, 0));
    CHECK_THROWS(Fraction(0, 0));
    CHECK_THROWS(Fraction(-3,0));
}
TEST_CASE("Checking reduction the fractions"){//Checking the constructor reduces the fractions to the basic form
    Fraction a(-4,8);
    Fraction b(12,2);
    Fraction c(8, -80);
    Fraction d(20, 150);
    CHECK(a==Fraction(-1,2));
    CHECK(b==Fraction(6,1));
    CHECK(c==Fraction(1,-10));
    CHECK(d==Fraction(2,15));
}


