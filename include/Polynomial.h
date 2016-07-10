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

        Polynomial(const Polynomial<coeff>& rhs); // copy ctor
        Polynomial& operator= (const Polynomial<coeff>& rhs); // assignment operator

        int getDegree() const;
        std::vector<coeff> getCoefficients() const;

        //Calculus
        //------------------------------------------------------------------
        Polynomial<coeff> derivative() const;
        Polynomial<coeff> antideriv(coeff C = 0) const; // C represents the constant after integrating
        coeff integral(coeff lower, coeff upper) const; // lower and upper are the boundaries for integration

        // Overloaded operators
        // -----------------------------------------------------------------
        coeff operator() (coeff input) const; // Function call on the polynomial. Plugs in the input value
        Polynomial<coeff> operator+ (const Polynomial<coeff>& other) const; // Adds two polynomials
        Polynomial<coeff> operator- (const Polynomial<coeff>& other) const; // Subtracts two polynomials
        Polynomial<coeff> operator* (const Polynomial<coeff>& other) const; // Multiplies two polynomials

        Polynomial<coeff> operator* (coeff constant) const; // Multiplies polynomial by a scalar constant

        virtual ~Polynomial();

    protected:

    private:
        std::vector<coeff> mCoeff;

};

#include "../src/Polynomial/Polynomial.cpp"

#endif // POLYNOMIAL_H
