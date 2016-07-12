#ifndef FRACTION_H
#define FRACTION_H

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

            Fraction(int n, int d);

            static int gcd(int a, int b); // takes the gcd of two numbers
            static int lcm(int a, int b);

        protected:

        private:
            int mNumerator = 0;
            int mDenominator = 1;
    };

}

#endif // FRACTION_H
