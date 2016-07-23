#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <initializer_list>
namespace AlgLib
{
    template <typename coeff>
    class Polynomial
    {
    public:
        Polynomial(); // Constructs the 0 polynomial
        Polynomial(std::initializer_list<coeff> args);
        Polynomial(std::vector<coeff> coefficients);

        Polynomial(const Polynomial<coeff>& rhs); // copy ctor
        Polynomial& operator= (const Polynomial<coeff>& rhs); // assignment operator

        virtual int getDegree() const;
        virtual std::vector<coeff> getCoefficients() const;

        //Calculus
        //------------------------------------------------------------------
        virtual Polynomial<coeff> derivative() const;
        virtual Polynomial<coeff> antideriv(coeff C = 0) const; // C represents the constant after integrating
        virtual coeff integral(coeff lower, coeff upper) const; // lower and upper are the boundaries for integration

        // Overloaded operators
        // -----------------------------------------------------------------
        virtual coeff operator() (coeff input) const; // Function call on the polynomial. Plugs in the input value
        virtual Polynomial<coeff> operator+ (const Polynomial<coeff>& other) const; // Adds two polynomials
        virtual Polynomial<coeff> operator- (const Polynomial<coeff>& other) const; // Subtracts two polynomials
        virtual Polynomial<coeff> operator* (const Polynomial<coeff>& other) const; // Multiplies two polynomials
        virtual Polynomial<coeff> operator/ (const Polynomial<coeff>& other) const; // Returns the polynomial quotient
        virtual Polynomial<coeff> operator% (const Polynomial<coeff>& other) const; // Returns the polynomial remainder

        virtual Polynomial<coeff> operator* (coeff constant) const; // Multiplies polynomial by a scalar constant

        virtual ~Polynomial();

    protected:
        std::vector<coeff> mCoeff;

    private:
        coeff getLeadingCoeff() const;
        void stripZ();

    };

    class IntegerPolynomial : public Polynomial<int>
    {
    public:
        IntegerPolynomial(std::vector<int>& coefficients);
        IntegerPolynomial(std::initializer_list<int> args);
        IntegerPolynomial(const Polynomial<int>& other);
        IntegerPolynomial& operator=(const Polynomial<int>& other);
        IntegerPolynomial();

        virtual IntegerPolynomial operator% (int mod) const;

        virtual std::vector<int> moduloRoots(int mod) const;
    };
}


#include "../src/Polynomial/Polynomial.cpp"

#endif // POLYNOMIAL_H
