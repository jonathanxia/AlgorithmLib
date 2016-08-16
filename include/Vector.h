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

        /** \brief Gives the dot product of two Vector objects
        *
        * Usage is just v1 * v2
        *
        * \return The dot product of the two `Vector`s.
        *
        * \throw std::length_error When the `Vector`s do not have matching dimensions
        */
        T operator* (const Vector<T>& other);
    };
}
#include "../src/Vector/Vector.inl"
