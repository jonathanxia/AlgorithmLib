#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <initializer_list>
namespace AlgLib
{
    /** \brief A class for Polynomials
    * \param coeff The type of the coefficients in the Polynomial.
    */
    template <typename coeff>
    class Polynomial
    {
    public:
        /** \brief Default constructor
        * Constructs the 0-polynomial
        */
        Polynomial(); // Constructs the 0 polynomial
        /** \brief Constructor with initializer list as coefficients
        * \param args The `std::initializer_list` with the args. Note that the coefficients should be in increasing degree
        *               so the degree of the term is equivalent to the index. So, the polynomial \f$ 1 + 2x + 3x^2 + 4x^3 \f$
        *               would have {1, 2, 3, 4} passed in.
        */
        Polynomial(std::initializer_list<coeff> args);
        /** \brief Constructor with vector storing the coefficients
        * \param coefficients The `std::vector<ceoff>` with coefficients. Note that the coefficients should be in increasing degree
                              so the degree of the term is equivalent to the index. So, the polynomial \f$ 1 + 2x + 3x^2 + 4x^3 \f$ would have
                              {1, 2, 3, 4} passed in.
        */
        Polynomial(std::vector<coeff> coefficients);

        /** \brief Copy constructor
        * \param rhs The Polynomial<coeff> to be copied
        */
        Polynomial(const Polynomial<coeff>& rhs); // copy ctor
        /** \brief The assignment operator
        * \param rhs The right hand side of the assignment
        */
        Polynomial& operator= (const Polynomial<coeff>& rhs); // assignment operator

        /** \brief Returns the degree of the polynomial
        *
        * Note that the degree is the highest **non zero** degree term in the Polynomial
        * \return The degree of the Polynomial
        */
        virtual int getDegree() const;
        /** \brief Returns the coefficients as a `std::vector`
        * \return The `std::vector` with the coefficients. The Polynomial \f$ 1 + 2x + 3x^2 + 4x^3 \f$ would return {1, 2, 3, 4}
        */
        virtual std::vector<coeff> getCoefficients() const;

        //Calculus
        //------------------------------------------------------------------

        /** \brief Returns the derivative of the Polynomial object */
        virtual Polynomial<coeff> derivative() const;
        /** \brief Returns the antiderivative of the Polynomial object
        * \param C The constant of integration. Default value is 0. Don't forget your +C.
        */
        virtual Polynomial<coeff> antideriv(coeff C = 0) const; // C represents the constant after integrating
        /** \brief Returns the integral from lower to upper of the Polynomial
        * \param lower The lower bound of integration
        * \param upper The upper bound of integration
        * \return The integral from lower to upper of the Polynomial
        */
        virtual coeff integral(coeff lower, coeff upper) const; // lower and upper are the boundaries for integration

        // Overloaded operators
        // -----------------------------------------------------------------

        /** \brief The () operator which would make it appear like a function call
        *
        * If we had a Polynomial object `P`, for example, writing `P(1)` would return the value when 1 is plugged into `P(x)`
        */
        virtual coeff operator() (coeff input) const; // Function call on the polynomial. Plugs in the input value

        /** \brief Adds two polynomials */
        virtual Polynomial<coeff> operator+ (const Polynomial<coeff>& other) const; // Adds two polynomials
        /** \brief Subtracts two polynomials */
        virtual Polynomial<coeff> operator- (const Polynomial<coeff>& other) const; // Subtracts two polynomials
        /** \brief Multiplies two polynomials */
        virtual Polynomial<coeff> operator* (const Polynomial<coeff>& other) const; // Multiplies two polynomials
        /** \brief Divides two polynomials and returns the quotient, disregarding the remainder */
        virtual Polynomial<coeff> operator/ (const Polynomial<coeff>& other) const; // Returns the polynomial quotient
        /** \brief Gives the remainder of the Polynomial */
        virtual Polynomial<coeff> operator% (const Polynomial<coeff>& other) const; // Returns the polynomial remainder
        /** \brief Multiplies the Polynomial by a constant */
        virtual Polynomial<coeff> operator* (coeff constant) const; // Multiplies polynomial by a scalar constant

        /** Default destructor */
        virtual ~Polynomial();

    protected:
        std::vector<coeff> mCoeff;

    private:
        coeff getLeadingCoeff() const;
        void stripZ();

    };

    /** The IntegerPolynomial is a Polynomial with int coefficients */
    class IntegerPolynomial : public Polynomial<int>
    {
    public:
        using Polynomial<int>::Polynomial;

        /** \brief The assignment operator which assigns from another Polynomial */
        IntegerPolynomial& operator=(const Polynomial<int>& other);

        /** \brief Takes the coefficients of the Polynomial modulo `mod`
        \param mod The modulus to take the coefficients of the Polynomial on
        \return An `IntegerPolynomial` with the coefficients reduced modulo mod is returned */
        virtual IntegerPolynomial operator% (int mod) const;

        /** \brief Returns the roots of an IntegerPolynomial in a certain mod
        * \param mod The modulus to find the roots of the IntegerPolynomial in
        * \return An `std::vector<int>` of the roots of the IntegerPolynomial
        */
        virtual std::vector<int> moduloRoots(int mod) const;
    };
}


#include "../src/Polynomial/Polynomial.inl"
#endif // POLYNOMIAL_H
