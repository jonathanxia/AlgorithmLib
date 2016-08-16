#include <stdexcept>
namespace AlgLib
{
    template <typename T>
    Vector<T>::Vector(const std::vector<T>& theVec) :
        std::vector<T>(theVec)
    {
    }

    template <typename T>
    Vector<T>::~Vector<T>()
    {
        // dtor
    }
    template <typename T>
    Vector<T>::Vector(const Vector<T>& theVec) :
        std::vector<T>(theVec.size())
    {
        for(int i = 0; i < static_cast<int>(theVec.size()); i++)
        {
            (*this)[i] = theVec[i];
        }
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& other)
    {
        if(&other == this)
            return *this;
        std::vector<T>::operator=(other);
        return *this;
    }
    template <typename T>
    T Vector<T>::operator* (const Vector<T>& other)
    {
        if(this->size() != other.size())
            throw std::length_error("Attempted to take dot product of mismatched Vector objects");
        T sum = T(0);
        for(size_t i = 0; i < this->size(); i++)
        {
            sum += (*this)[i] * other[i];
        }
        return sum;
    }
}
