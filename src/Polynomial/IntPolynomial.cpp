#include <vector>
#include <stdexcept>
#include "Polynomial.h"

namespace AlgLib
{
    IntegerPolynomial IntegerPolynomial::operator%(int mod) const
    {
        std::vector<int> mCoeff = this->getCoefficients();
        for(unsigned int i = 0; i < mCoeff.size(); i++)
        {
            mCoeff[i] %= mod;
        }
        return AlgLib::IntegerPolynomial(mCoeff);
    }

    IntegerPolynomial& IntegerPolynomial::operator=(const Polynomial<int>& rhs)
    {
        mCoeff = rhs.getCoefficients();
        return *this;
    }

    std::vector<int> IntegerPolynomial::moduloRoots(int mod) const
    {
        if(mod < 2)
        {
            throw std::invalid_argument("Modulus must be at least 2");
        }
        std::vector<int> roots;
        for(int i = 0; i < mod; i++)
        {
            if( (*this)(i) % mod == 0 )
            {
                roots.push_back(i);
            }
        }
        return roots;
    }
}
