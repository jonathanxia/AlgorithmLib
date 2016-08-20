#include "Fraction.h"
#include <sstream>
namespace AlgLib
{
    Fraction operator+(const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.mNumerator * f2.mDenominator + f2.mNumerator * f1.mDenominator, f1.mDenominator * f2.mDenominator);
    }
    Fraction operator-(const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.mNumerator * f2.mDenominator - f2.mNumerator * f1.mDenominator, f1.mDenominator * f2.mDenominator);
    }
    Fraction operator*(const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.mNumerator * f2.mNumerator, f1.mDenominator * f2.mDenominator);
    }
    Fraction operator/(const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.mNumerator * f2.mDenominator, f1.mDenominator * f2.mNumerator);
    }

    Fraction Fraction::operator-() const
    {
        return Fraction(-mNumerator, mDenominator);
    }
    Fraction Fraction::operator+() const
    {
        return *this;
    }
    double Fraction::getValue() const
    {
        return (double) mNumerator / mDenominator;
    }
    bool Fraction::operator<=(const Fraction& other) const
    {
        return mNumerator * other.mDenominator <= mDenominator * other.mNumerator;
    }

    bool Fraction::operator>=(const Fraction& other) const
    {
        return mNumerator * other.mDenominator >= mDenominator * other.mNumerator;
    }

    bool Fraction::operator!=(const Fraction& other) const
    {
        return mNumerator * other.mDenominator != mDenominator * other.mNumerator;
    }

    bool Fraction::operator==(const Fraction& other) const
    {
        return mNumerator * other.mDenominator == mDenominator * other.mNumerator;
    }

    bool Fraction::operator<(const Fraction& other) const
    {
        return mNumerator * other.mDenominator < mDenominator * other.mNumerator;
    }

    bool Fraction::operator>(const Fraction& other) const
    {
        return mNumerator * other.mDenominator > mDenominator * other.mNumerator;
    }

    std::ostream& operator<<(std::ostream& ostr, const Fraction& frac)
    {
        ostr << frac.mNumerator;
        if(frac.mDenominator != 1)
            ostr << "/" << frac.mDenominator;
        return ostr;
    }
}


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

AlgLib::Fraction& AlgLib::Fraction::operator+=(const int other)
{
    *this = *this + other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator-=(const int other)
{
    *this = *this - other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator*=(const int other)
{
    *this = *this * other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator/=(const int other)
{
    *this = *this / other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator+=(const Fraction& other)
{
    *this = *this + other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator-=(const Fraction& other)
{
    *this = *this - other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator*=(const Fraction& other)
{
    *this = *this * other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator/=(const Fraction& other)
{
    *this = *this / other;
    return *this;
}

AlgLib::Fraction& AlgLib::Fraction::operator=(const int n)
{
    mDenominator = 1;
    mNumerator = n;
    return *this;
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
    // First take the absolute value of a and b
    if(a < 0) {a *= -1;}
    if(b < 0) {b *= -1;}
    //Now switch in case a < b
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp; // Does the switcheroo
    }
    //Termination condition
    if(b == 0)
    {
        return a;
    }
    else // EA recursion
    {
        return gcd(b, a % b);
    }
}

int AlgLib::Fraction::lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void AlgLib::Fraction::simplify()
{
    int g = gcd(mNumerator, mDenominator);
    mNumerator /= g;
    mDenominator /= g;
    if(mDenominator < 0)
    {
        mDenominator *= -1;
        mNumerator *= -1;
    }
}
