#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <initializer_list>

template <typename coeff>
class Polynomial
{
    public:
        Polynomial(); // Constructs the 0 polynomial
        Polynomial(std::initializer_list<coeff> args);
        Polynomial(std::vector<coeff> coefficients);

        int getDegree() const;
        std::vector<coeff> getCoefficients() const;

        coeff operator() (coeff input) const;
        Polynomial<coeff> operator+ (const Polynomial<coeff>& other) const;
        Polynomial<coeff> operator- (const Polynomial<coeff>& other) const;
        Polynomial<coeff> operator* (const Polynomial<coeff>& other) const;

        Polynomial<coeff> operator+ (coeff constant);
        Polynomial<coeff> operator- (coeff constant);
        Polynomial<coeff> operator* (coeff constant);
        virtual ~Polynomial();

    protected:

    private:
        std::vector<coeff> mCoeff;

};

#include "../src/Polynomial.cpp"

#endif // POLYNOMIAL_H
