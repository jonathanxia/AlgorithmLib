#include <vector>
#include <stdexcept>
/** @brief Takes modulo something
  *
  * Return Polynomial that takes the mod of the coefficients
  */
AlgLib::IntegerPolynomial AlgLib::IntegerPolynomial::operator%(int mod) const
{
    std::vector<int> mCoeff = this->getCoefficients();
    for(unsigned int i = 0; i < mCoeff.size(); i++)
    {
        mCoeff[i] %= mod;
    }
    return AlgLib::IntegerPolynomial(mCoeff);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
AlgLib::IntegerPolynomial::IntegerPolynomial(std::vector<int>& coefficients) :
    Polynomial<int>(coefficients)
{
}
AlgLib::IntegerPolynomial& AlgLib::IntegerPolynomial::operator=(const Polynomial<int>& rhs)
{
    mCoeff = rhs.getCoefficients();
    return *this;
}
AlgLib::IntegerPolynomial::IntegerPolynomial(const Polynomial<int>& rhs) :
    Polynomial<int>(rhs)
{
}
AlgLib::IntegerPolynomial::IntegerPolynomial(std::initializer_list<int>args) :
    Polynomial<int>(args)
{
}
AlgLib::IntegerPolynomial::IntegerPolynomial() :
    Polynomial<int>()
{
}

std::vector<int> AlgLib::IntegerPolynomial::moduloRoots(int mod) const
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
