#include "Fraction.h"
#include <sstream>
AlgLib::Fraction::Fraction() :
    mNumerator(0),
    mDenominator(1)
{
    //ctor
}

AlgLib::Fraction::~Fraction()
{
    //dtor
}

AlgLib::Fraction::Fraction(const Fraction& other)
{
    mNumerator = other.mNumerator;
    mDenominator = other.mDenominator;
    this->simplify();
}

AlgLib::Fraction& AlgLib::Fraction::operator=(const Fraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    mNumerator = rhs.mNumerator;
    mDenominator = rhs.mDenominator;
    this->simplify();
    return *this;
}

AlgLib::Fraction AlgLib::Fraction::operator+(const Fraction& other) const
{
    return Fraction(mNumerator * other.mDenominator + mDenominator * other.mNumerator, mDenominator * other.mDenominator);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
AlgLib::Fraction::Fraction(int n, int d) :
    mNumerator(n),
    mDenominator(d)
{
    this->simplify();
}

int AlgLib::Fraction::gcd(int a, int b)
{
    // Now we use the Euclidean algorithm
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp; // Does the switcheroo
    }
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int AlgLib::Fraction::lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

std::string AlgLib::Fraction::toString()
{
    std::ostringstream ostr;
    ostr << mNumerator << "/" << mDenominator;
    return ostr.str();
}

void AlgLib::Fraction::simplify()
{
    int g = gcd(mNumerator, mDenominator);
    mNumerator /= g;
    mDenominator /= g;
}
