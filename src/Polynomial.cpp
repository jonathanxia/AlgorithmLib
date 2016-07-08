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
Polynomial<coeff>::~Polynomial()
{
    //dtor
}
