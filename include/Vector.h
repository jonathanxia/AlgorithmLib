#pragma once
#include <vector>

namespace AlgLib
{
    template <typename T>
    class Vector : public std::vector<T>
    {
    public:
        using std::vector<T>::vector;
        using std::vector<T>::operator=;
        /** Default constructor */
        Vector() : std::vector<T>(){}

        /** Constructor that takes in an std::vector<T> */
        Vector(const std::vector<T>& theVec);

        Vector(const Vector<T>& theVec);
        /** Default destructor */
        virtual ~Vector();

        virtual Vector<T>& operator=(const Vector<T>& other);

        /** \brief Gives the dot product of two Vector objects
        *
        * Usage is just v1 * v2
        *
        * \return The dot product of the two `Vector`s.
        *
        * \throw std::length_error When the `Vector`s do not have matching dimensions
        */
        virtual T operator* (const Vector<T>& other) const;

        /** \brief Multiplies the Vector by a scalar
        * \param scalar The scalar to multiply by
        * \return The Vector that results when multiplied by the scalar.
        */
        virtual Vector<T> operator* (const T& scalar) const;

        /** \brief Divides the Vector by a scalar
        * \param scalar The scalar to divide by
        * \return The Vector that results when divided by the scalar.
        * \throw std::invalid_argument When scalar is 0
        */
        virtual Vector<T> operator/ (const T& scalar) const;

        virtual Vector<T>& operator/= (const T& scalar);

        template <typename U>
        friend Vector<U> operator* (const U& scalar, const Vector<U>& vec);

        /** \brief Adds two vectors together
        * \return The sum of the two Vector objects
        * \throw std::length_error When the `Vector`s do not have matching dimensions
        */
        virtual Vector<T> operator+ (const Vector<T>& other) const;

        /** \brief Subtracts two vectors
        * \return The difference of the two Vector objects
        * \throw std::length_error When the `Vector`s do not have matching dimensions
        */
        virtual Vector<T> operator- (const Vector<T>& other) const;

        /** \brief Negates the vector object
        * \return The additive inverse of the current Vector object.
        */
        virtual Vector<T> operator-() const;

        virtual Vector<T>& operator+=(const Vector<T>& other);

        virtual Vector<T>& operator-=(const Vector<T>& other);

        /** \brief Overloads the indexing operator. Performs the expected operation.
        * \throw std::out_of_range This exception is thrown if the argument is out of bounds
        */
        virtual const T& operator[](int n) const;
        virtual T& operator[](int n);
    };
}
#include "../src/Vector/Vector.inl"
