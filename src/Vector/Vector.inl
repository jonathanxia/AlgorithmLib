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
    T Vector<T>::operator* (const Vector<T>& other) const
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

    template <typename T>
    Vector<T> Vector<T>::operator* (const T& scalar) const
    {
        Vector<T> ret(this->size());
        for(int i = 0; i < static_cast<int>(ret.size()); i++)
        {
            ret[i] = scalar * (*this)[i];
        }
        return ret;
    }

    template <typename T>
    Vector<T> Vector<T>::operator-() const
    {
        Vector<T> ret(this->size());
        for(int i = 0; i < static_cast<int>(ret.size()); i++)
        {
            ret[i] = -(*this)[i];
        }
        return ret;
    }

    template <typename T>
    Vector<T> Vector<T>::operator-(const Vector<T>& other) const
    {
        return (*this) + (-other);
    }
    template <typename T>
    Vector<T> Vector<T>::operator+(const Vector<T>& other) const
    {
        if(other.size() != this->size())
            throw std::length_error("Attempted to add two Vectors with mismatched dimensions");
        Vector<T> sum(this->size());
        for(int i = 0; i < static_cast<int>(this->size()); i++)
        {
            sum[i] = this->operator[](i) + other[i];
        }
        return sum;
    }

    template <typename T>
    const T& Vector<T>::operator[](int n) const
    {
        if(n < 0 || n >= (int) this->size())
            throw std::out_of_range("Attempted to index out of bounds on a AlgLib::Vector");
        return std::vector<T>::operator[](n);
    }

    template <typename T>
    T& Vector<T>::operator[](int n)
    {
        if(n < 0 || n >= (int) this->size())
            throw std::out_of_range("Attempted to index out of bounds on a AlgLib::Vector");
        return std::vector<T>::operator[](n);
    }

    template <typename T>
    Vector<T> operator*(const T& scalar, const Vector<T>& vec)
    {
        return vec * scalar;
    }

    template <typename T>
    Vector<T> Vector<T>::operator/(const T& scalar) const
    {
        if(scalar == T(0))
            throw std::invalid_argument("Attempted to divide Vector by a 0-scalar");
        Vector<T> ret(this->size());
        for(int i = 0; i < static_cast<int>(this->size()); i++)
        {
            ret[i] = (*this)[i] / scalar;
        }
        return ret;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator/= (const T& scalar)
    {
        *this = (*this) / scalar;
        return *this;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator+= (const Vector<T>& other)
    {
        if(other.size() != this->size())
            throw std::length_error("Attempted to add Vectors of differing dimensions");
        for(int i = 0; i < static_cast<int>(this->size()); i++)
        {
            (*this)[i] += other[i];
        }
        return *this;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator-= (const Vector<T>& other)
    {
        if(other.size() != this->size())
            throw std::length_error("Attempted to add Vectors of differing dimensions");
        for(int i = 0; i < static_cast<int>(this->size()); i++)
        {
            (*this)[i] -= other[i];
        }
        return *this;
    }
}
