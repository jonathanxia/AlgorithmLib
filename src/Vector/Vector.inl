#include <stdexcept>
namespace AlgLib
{
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
