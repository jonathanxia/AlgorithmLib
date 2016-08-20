#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
namespace AlgLib
{
    /** A Fraction class that represents ratios of integers. This class comes equipped with arithmetic operations! */
    class Fraction
    {
        public:
            /** Default constructor */
            Fraction();
            /** Default destructor */
            virtual ~Fraction();
            /** Copy constructor
             *  \param other Fraction to copy from
             */
            Fraction(const Fraction& other);
            /** \brief Constructor that takes in numerator and denominator
            * \param n The value of the numerator
            * \param d The value of the denominator. Default value is 1.
            */
            Fraction(int n, int d = 1);

            /** \brief Adds two Fractions
            * \param f1 The first Fraction
            * \param f2 The second Fraction
            * \return The Fraction that is equal to the sum of the two Fractions
            */
            friend Fraction operator+(const Fraction& f1, const Fraction& f2);
            /** \brief Subtracts two Fractions
            * \param f1 The first Fraction
            * \param f2 The second Fraction
            * \return The Fraction that is equal to the difference of the two Fractions
            */
            friend Fraction operator-(const Fraction& f1, const Fraction& f2);
            /** \brief Multiplies two Fractions
            * \param f1 The first Fraction
            * \param f2 The second Fraction
            * \return The Fraction that is equal to the product of the two Fractions
            */
            friend Fraction operator*(const Fraction& f1, const Fraction& f2);
            /** \brief Divides two Fractions
            * \param f1 The first Fraction
            * \param f2 The second Fraction
            * \return The Fraction that is equal to the quotient of the two Fractions
            */
            friend Fraction operator/(const Fraction& f1, const Fraction& f2);
            /** Assignment operator
             *  \param other Fraction to assign from
             *  \return A reference to this
             */
            virtual Fraction& operator=(const Fraction& other);
            /** Assignment operator
             *  \param n Other int to assign from
             *  \return A reference to this
             */
            virtual Fraction& operator=(const int n);
            virtual Fraction& operator+=(const int other);
            virtual Fraction& operator-=(const int other);
            virtual Fraction& operator*=(const int other);
            virtual Fraction& operator/=(const int other);
            virtual Fraction& operator+=(const Fraction& other);
            virtual Fraction& operator-=(const Fraction& other);
            virtual Fraction& operator*=(const Fraction& other);
            virtual Fraction& operator/=(const Fraction& other);

            virtual Fraction operator-() const;
            virtual Fraction operator+() const;
            virtual bool operator>(const Fraction& other) const;
            virtual bool operator<(const Fraction& other) const;
            virtual bool operator==(const Fraction& other) const;
            virtual bool operator!=(const Fraction& other) const;
            virtual bool operator>=(const Fraction& other) const;
            virtual bool operator<=(const Fraction& other) const;

            /** \brief Returns the greatest common divisor
            * \param a
            * \param b These parameters can be negative, but the return value will always be positive.
            * \return The greatest positive common divisor of a and b
            *
            */
            static int gcd(int a, int b); // takes the gcd of two numbers

            /** \brief Returns the least common multiple
            * \param a
            * \param b These parameters can be negative
            * \return These just uses a * b / gcd(a, b), so to determine the sign of the LCM, refer to that.
            */
            static int lcm(int a, int b);

            /** \brief Prints the `Fraction` as numerator/denominator
            *
            * "numerator/denominator". So, the `Fraction` that has a value of \f$ \frac{3}{5} \f$ would cause this to return ` "3/5" `.
            */
            friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);

            /** \brief Returns the `double` value of the Fraction
            * \return The value of the Fraction as a double.
            */
            virtual double getValue() const;

        protected:

        private:
            int mNumerator = 0;
            int mDenominator = 1;
            void simplify();
    };

}

#endif // FRACTION_H
