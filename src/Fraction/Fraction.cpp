#include "Fraction.h"

Fraction::Fraction() :
    mNumerator(0),
    mDenominator(1)
{
    //ctor
}

Fraction::~Fraction()
{
    //dtor
}

Fraction::Fraction(const Fraction& other)
{
    mNumerator = other.mNumerator;
    mDenominator = other.mDenominator;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    mNumerator = rhs.mNumerator;
    mDenominator = rhs.mDenominator;
    return *this;
}
