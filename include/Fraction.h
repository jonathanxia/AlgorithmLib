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
            friend Fraction operator+(const Fraction& f1, const Fraction& f2);
            friend Fraction operator-(const Fraction& f1, const Fraction& f2);
            friend Fraction operator*(const Fraction& f1, const Fraction& f2);
            friend Fraction operator/(const Fraction& f1, const Fraction& f2);
            Fraction& operator=(const Fraction& other);
            Fraction& operator=(const int n);
            Fraction& operator+=(const int other);
            Fraction& operator-=(const int other);
            Fraction& operator*=(const int other);
            Fraction& operator/=(const int other);
            Fraction& operator+=(const Fraction& other);
            Fraction& operator-=(const Fraction& other);
            Fraction& operator*=(const Fraction& other);
            Fraction& operator/=(const Fraction& other);
            bool operator>(const Fraction& other);
            bool operator<(const Fraction& other);
            bool operator==(const Fraction& other);
            bool operator!=(const Fraction& other);
            bool operator>=(const Fraction& other);
            bool operator<=(const Fraction& other);

            Fraction(int n, int d = 1);

            static int gcd(int a, int b); // takes the gcd of two numbers
            static int lcm(int a, int b);

            std::string toString();
            double getValue() const;

        protected:

        private:
            int mNumerator = 0;
            int mDenominator = 1;
            void simplify();
    };

}

#endif // FRACTION_H
