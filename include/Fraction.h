#ifndef FRACTION_H
#define FRACTION_H
#include <string>
namespace AlgLib
{
    class Fraction
    {
        public:
            /** Default constructor */
            Fraction();
            /** Default destructor */
            virtual ~Fraction();
            /** Copy constructor
             *  \param other Object to copy from
             */
            Fraction(const Fraction& other);
            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            Fraction& operator=(const Fraction& other);
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            Fraction operator+(const int other) const;
            Fraction operator-(const int other) const;
            Fraction operator*(const int other) const;
            Fraction operator/(const int other) const;
            Fraction& operator+=(const int other);
            Fraction& operator-=(const int other);
            Fraction& operator*=(const int other);
            Fraction& operator/=(const int other);
            Fraction& operator+=(const Fraction& other);
            Fraction& operator-=(const Fraction& other);
            Fraction& operator*=(const Fraction& other);
            Fraction& operator/=(const Fraction& other);

            Fraction(int n, int d);

            static int gcd(int a, int b); // takes the gcd of two numbers
            static int lcm(int a, int b);

            std::string toString();

        protected:

        private:
            int mNumerator = 0;
            int mDenominator = 1;
            void simplify();
    };

}

#endif // FRACTION_H
