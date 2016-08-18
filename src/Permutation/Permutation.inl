#include <stdexcept>
#include "Vector.h"
namespace AlgLib
{
    Permutation::Permutation(int n) :
        mPermutation(n)
    {
        for(int i = 0; i < n; i++)
        {
            mPermutation[i] = i;
        }
    }

    Permutation::Permutation(const std::vector<int>& perm) :
        mPermutation(perm)
    {
        Vector<bool> checker(perm.size(), false); // This will check whether each number from 0 to perm.size() - 1 exists
        for(int i = 0; i < static_cast<int>(perm.size()); i++)
        {
            if(perm[i] >= (int) perm.size() || perm[i] < 0)
                throw std::invalid_argument("Permutation vector does not have appropriate elements");
            checker[perm[i]] = true;
        }
        // Now to check through the checker and see if there is any false
        for(auto c : checker)
        {
            if(!c)
            {
                throw std::invalid_argument("Permutation vector's elements do not form a permutation");
            }
        }
    }

    template <typename T>
    T Permutation::operator() (const T& container, int start, int last) const
    {
        if(last - start != numElements())
            throw std::length_error("Permutation object has a different length than the object being acted on");
        T copyOf(container);
        for(int i = start; i < last; i++)
        {
            copyOf[i] = container[ start +  mPermutation[i - start] ];
        }
        return copyOf;
    }

    int Permutation::numElements() const
    {
        return mPermutation.size();
    }
}
