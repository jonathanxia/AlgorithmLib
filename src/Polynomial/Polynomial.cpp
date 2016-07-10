#include <initializer_list>

template <typename coeff>
Polynomial<coeff>::Polynomial() :
    mCoeff(1) //mCoeff is the vector storing the coefficients, constructs a 0 polynomial
{

}
template <typename coeff>
Polynomial<coeff>::Polynomial(std::initializer_list<coeff> args)
{
    mCoeff.reserve(args.size());
    for(auto c : args)
    {
        mCoeff.push_back(c);
    }
}
template <typename coeff>
Polynomial<coeff>::Polynomial(std::vector<coeff> coefficients) :
    mCoeff(coefficients)
{

}
//copy ctor
template <typename coeff>
Polynomial<coeff>::Polynomial(const Polynomial<coeff>& rhs) :
    mCoeff(rhs.mCoeff)
{

}
//assignment operator
template <typename coeff>
Polynomial<coeff>& Polynomial<coeff>::operator= (const Polynomial<coeff>& rhs)
{
    mCoeff.resize(rhs.mCoeff.size());
    for(unsigned int i = 0; i < rhs.mCoeff.size(); i++)
    {
        mCoeff[i] = rhs.mCoeff[i];
    }
    return *this;
}

template <typename coeff>
int Polynomial<coeff>::getDegree() const
{
    return mCoeff.size() - 1;
}
template <typename coeff>
std::vector<coeff> Polynomial<coeff>::getCoefficients() const
{
    return mCoeff;
}

template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::derivative() const
{
    std::vector<coeff> derivCoeff(mCoeff.size() - 1);
    for(unsigned int i = 0; i < derivCoeff.size(); i++)
    {
        derivCoeff[i] = (i + 1) * mCoeff[i+1];
    }
    return Polynomial(derivCoeff);
}
template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::antideriv(coeff C) const
{
    std::vector<coeff> retCoeff(mCoeff.size() + 1);
    for(int i = 1; i < retCoeff.size(); i++)
    {
        retCoeff[i] = mCoeff[i-1] / i;
    }
    retCoeff[0] = C;
    return Polynomial(retCoeff);
}
template <typename coeff>
coeff Polynomial<coeff>::integral(coeff lower, coeff upper) const
{
    Polynomial<coeff> f = this->antideriv();
    return f(upper) - f(lower);
}

template <typename coeff>
coeff Polynomial<coeff>::operator() (coeff input) const
{
    coeff sum = mCoeff[mCoeff.size() - 1];
    for(int i = mCoeff.size() - 2; i >= 0; i--)
    {
        sum *= input;
        sum += mCoeff[i];
    }
    return sum;
}
template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::operator+(const Polynomial<coeff>& other) const
{
    std::vector<coeff> ret;
    int i;
    for(i = 0; i < other.mCoeff.size() && i < mCoeff.size(); i++)
    {
        ret.push_back(mCoeff[i] + other.mCoeff[i]);
    }
    while (i < mCoeff.size())
    {
        ret.push_back(mCoeff[i]);
        i++;
    }
    while (i < other.mCoeff.size())
    {
        ret.push_back(other.mCoeff[i]);
        i++;
    }
    return ret;
}
template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::operator-(const Polynomial<coeff>& other) const
{
    std::vector<coeff> ret = other.mCoeff;
    for(int i = 0; i < ret.size(); i++)
    {
        ret[i] *= -1;
    }
    Polynomial<coeff> poly(ret);
    return *this + poly;
}
template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::operator* (const Polynomial<coeff>& other) const
{
    // Time to multiply polynomials! Here we go
    std::vector<coeff> ret(mCoeff.size() + other.mCoeff.size()); // We must add the degrees together

    for(int i = 0; i < other.mCoeff.size(); i++)
    {
        for(int j = 0; j < mCoeff.size(); j++)
        {
            ret[i+j] += other.mCoeff[i] * mCoeff[j];
        }
    }
    return Polynomial(ret);
}
template <typename coeff>
Polynomial<coeff> Polynomial<coeff>::operator* (const coeff constant) const
{
    std::vector<coeff> kek(mCoeff.size());

    for(unsigned int i = 0; i < mCoeff.size(); i++)
    {
        kek[i] = mCoeff[i] * constant;
    }
    return Polynomial(kek);
}
template <typename coeff>
Polynomial<coeff>::~Polynomial()
{
    //dtor
}
