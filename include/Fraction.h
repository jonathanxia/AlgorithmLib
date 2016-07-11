#ifndef FRACTION_H
#define FRACTION_H


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

    protected:

    private:
        int mNumerator = 0;
        int mDenominator = 1;
};

#endif // FRACTION_H
