#include <vector>
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
