#include "doctest.h"
#include "sources/Fraction.hpp"
#include "sstream"
using namespace ariel ;

TEST_CASE("Constructor tests") {
    CHECK_THROWS(Fraction(1, 0));
    CHECK_NOTHROW(Fraction(0, 1));
    CHECK_NOTHROW(Fraction(-0, 1));
}

TEST_SUITE_BEGIN("Operators overloading tests") ;
TEST_CASE("== Operator"){
    Fraction f1(3, 4) ;
    Fraction f2(3,4) ;
    CHECK(f1 == f2) ;

    f1 = Fraction(12, 20) ;
    f2 = Fraction(3, 5) ;
    CHECK(f1 == f2) ;

    f1 = Fraction(-20, 4) ;
    f2 = Fraction(5, -1) ;
    CHECK(f1 == f2) ;

    f1 = Fraction(1, -1) ;
    f2 = Fraction(1, 1) ;
    CHECK(f1 != f2) ;

    f1 = Fraction(4,5) ;
    CHECK(0.8 == f1) ;

    f2 = Fraction(1,8) ;
    CHECK(f2 == 0.125) ;
}

TEST_CASE("Operator >="){
    Fraction f1(2,3) ;
    Fraction f2(1,2) ;
    CHECK(f1 >= f2) ;

    f2 = Fraction(3, 9) ;
    CHECK(f2 >= f1) ;

    f1 = Fraction(-1, 4) ;
    CHECK(f2 >= f1) ;

    f2 = Fraction(0, 2) ;
    CHECK(f2 >= -0.6) ;

    f2 = Fraction(-1, 2) ;
    CHECK(-0.5 >= f2) ;
}

TEST_CASE("Operator <="){
    Fraction f1(1,3) ;
    Fraction f2(1,2) ;
    CHECK(f1 <= f2) ;

    f2 = Fraction(3, 9) ;
    CHECK(f2 <= f1) ;

    f1 = Fraction(-1, 4) ;
    CHECK(f1 <= f2) ;

    f2 = Fraction(0, 2) ;
    CHECK(-0.1 <= f2) ;

    f2 = Fraction(-1, 2) ;
    CHECK(-0.5 <= f2) ;
}

TEST_CASE("Operator >"){
    Fraction f1(1,3) ;
    Fraction f2(1,2) ;
    CHECK(f2 > f1) ;

    f2 = Fraction(4, 9) ;
    CHECK(f2 > f1) ;

    f1 = Fraction(-1, 4) ;
    f2 = Fraction(0, 8) ;
    CHECK(f2 > f1) ;

    f2 = Fraction(1, 2) ;
    CHECK(f2 > 0.1) ;

    f2 = Fraction(-2, 3) ;
    CHECK(-0.5 > f2) ;
}

TEST_CASE("Operator <"){
    Fraction f1(1,3) ;
    Fraction f2(1,2) ;
    CHECK(f1 < f2) ;

    f2 = Fraction(4, 9) ;
    CHECK(f1 < f2) ;

    f1 = Fraction(-1, 4) ;
    f2 = Fraction(0, 8) ;
    CHECK(f1 < f2) ;

    f2 = Fraction(1, 2) ;
    CHECK(0.1 < f2) ;

    f2 = Fraction(-2, 3) ;
    CHECK(f2 < -0.5) ;
}

TEST_CASE("+ Operator"){
    Fraction f1(1, 3) ;
    Fraction f2(0, 7) ;
    Fraction sum = f1 + f2 ;
    Fraction expected(1,3) ;
    CHECK(sum == expected) ;

    Fraction f3(-4,6) ;
    sum = sum + f3 ;
    expected = Fraction(-1, 3) ;
    CHECK(sum == expected) ;

    sum = sum + 0.5 ;
    expected = Fraction(1, 6) ;
    CHECK(sum == expected) ;

    sum = 0.5 + sum ;
    expected = Fraction(2,3) ;
    CHECK(sum == expected) ;
}

TEST_CASE("- Operator"){
    Fraction f1(3, 4) ;
    Fraction f2(4, 8) ;
    Fraction sum = f1 - f2 ;
    Fraction expected(1,4) ;
    CHECK(sum == expected) ;

    Fraction f3(1,2) ;
    sum = sum - f3 ;
    expected = Fraction(-1,4) ;
    CHECK(sum == expected) ;

    sum = sum + 0.25 ;
    expected = Fraction(0, 1) ;
    CHECK(sum == expected) ;

    sum = 0.333 + sum ;
    expected = Fraction(333,1000) ;
    CHECK(sum == expected) ;
}

TEST_CASE("* Operator"){
    Fraction f1(2, 5) ;
    Fraction f2(3,2) ;
    Fraction product = f1 * f2 ;
    Fraction expected(3, 5) ;
    CHECK(product == expected) ;

    Fraction f3(-1, 2) ;
    product = product * f3 ;
    expected = Fraction(-3, 10) ;
    CHECK(product == expected) ;

    product = product * 0.75 ;
    expected = Fraction(-9, 40) ;
    CHECK(product == expected) ;

    product = -0.10 * product ;
    expected = Fraction(9, 400) ;
    CHECK(product == expected) ;
}

TEST_CASE("/ Operator"){
    Fraction f1(3, 5) ;
    Fraction f2(2,3) ;
    Fraction quotient = f1 / f2 ;
    Fraction expected(9, 10) ;
    CHECK(quotient == expected) ;

    Fraction f3(-1, 4) ;
    quotient = quotient / f3 ;
    expected = Fraction(-18, 5) ;
    CHECK(quotient == expected) ;

    quotient = quotient / 0.5 ;
    expected = Fraction(-36, 5) ;
    CHECK(quotient == expected) ;

    quotient = -2.25 / quotient ;
    expected = Fraction(45, 144) ;
    CHECK(quotient == expected) ;
}

TEST_CASE("Operator ++"){
    Fraction f(4,8) ;
    Fraction res(1, 2) ;
    CHECK(res == f++) ;

    res = Fraction(3, 2) ;
    CHECK(res == f) ;

    f = Fraction(-3, 4) ;
    res = Fraction(1, 4) ;
    CHECK(res == ++f) ;

    res = Fraction(5, 4) ;
    CHECK(res == ++f) ;
}

TEST_CASE("Operator --"){
    Fraction f(4,8) ;
    Fraction res(1, 2) ;
    CHECK(res == f--) ;

    res = Fraction(-1, 2) ;
    CHECK(res == f) ;

    f = Fraction(-3, 4) ;
    res = Fraction(-7, 4) ;
    CHECK(res == --f) ;

    res = Fraction(-11, 4) ;
    CHECK(res == --f) ;
}

TEST_CASE("Operator <<"){
    Fraction f1(4, 6);
    Fraction f2(-10, 12);
    Fraction f3(0, -3) ;

    std::ostringstream os1;
    os1 << f1;
    CHECK(os1.str() == "2/3");

    std::ostringstream os2;
    os2 << f2;
    CHECK(os2.str() == "-5/6");

    std::ostringstream os3;
    os3 << f3;
    CHECK(os2.str() == "0/1");
}

TEST_CASE("Operator >>"){
    std::istringstream is1("5 6");
    Fraction f1;
    is1 >> f1;
    CHECK(f1.getNumerator() == 5);
    CHECK(f1.getDenominator() == 6);

    std::istringstream is2("1 f");
    Fraction f2;
    CHECK_THROWS(is2 >> f2);

    std::istringstream is3("0.33333");
    Fraction f3;
    CHECK(f3.getNumerator() == 333);
    CHECK(f3.getDenominator() == 1000);
}

TEST_SUITE_END ;

TEST_SUITE_BEGIN("General testing") ;
TEST_CASE("Zero Operations"){
    Fraction f1(0, 1) ;
    Fraction f2(-0,9) ;
    Fraction f12 = f1 + f2 ;
    Fraction res(0,1) ;
    CHECK(f12 == res) ;

    f12 = f1 - f2 ;
    CHECK(f12 == res) ;

    f12 = f1 * f2 ;
    CHECK(f12 == res) ;

    f12 = f1 / f2 ;
    CHECK(f12 == res) ;
}

TEST_CASE("Negative Fractions"){
    Fraction f1(-3, 2) ;
    Fraction f2(5, -4) ;
    Fraction f12 = f1 + f2 ;
    Fraction res(-9, 4) ;
    CHECK(f12 == res) ;

    f12 = f1 - f2 ;
    res = Fraction(-1, 4) ;
    CHECK(f12 == res) ;

    f12 = f1 * f2 ;
    res = Fraction(15, 8) ;
    CHECK(f12 == res) ;

    f12 = f1 / f2 ;
    res = Fraction(6, 5) ;
    CHECK(f12 == res) ;

    f1++ ;
    res = Fraction(-1, 2) ;
    CHECK(f12 == res) ;

    f2-- ;
    res = Fraction(-9, 4) ;
    CHECK(f12 == res) ;
}
TEST_SUITE_END ;

