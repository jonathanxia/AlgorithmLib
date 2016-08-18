#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <initializer_list>
#include "Vector.h"
#include <utility>

namespace AlgLib
{
    /** The Permutation class, which stores a Permutation object. The Permutation object can act like a functor, which can permute the
    * elements of a container.
    */
    class Permutation {
    public:
		// Constructors
		/** \brief Default constructor
		*
		* Constructs the identity Permutation for `n` objects. `n` will default to 1
		* \param n The number of elements
		*/
        Permutation(int n = 1);

        /** \brief Constructor that takes in a std::vector<int> of permutation
        *
        * Constructs the Permutation object that has the mapping of perm. Basically, position i should map to position perm[i]
        * \param perm The std::vector<int> that stores the Permutation. Position i should map to position perm[i]. Note that the elements
        * should be a permutation of 0 to perm.size() - 1.
        * \throw std::invalid_argument Throws this exception if the elements of perm are not a permutation of 0 to perm.size() - 1
        */
        Permutation(const std::vector<int>& perm);

        /** \brief Permutes the elements of container[start...(last-1)]. Note that last is not included in the permutation.
        *
        * This functor will rearrange (or permute) the elements of the container. So, a Permutation of (2, 1, 0, 4, 3) will mean that container[start + 0] is mapped to container[start + 2].
        * This also means that container[start + 4] and container[start + 3] will be flipped.
        * \tparam T The type of the container. So, if the container is an std::vector<int>, then T would be `std::vector<int>`
        * \param start Where to start the permuting. Defaults to 0.
        * \param last The index after where the permutation stops. Thus, container[last] is not in the permutation. Defaults to container.size().
        *
        * \return Return the permuted container. Note that the container itself was not modified.
        *
        * \throw std::length_error Throws this exception if the size of the container (or last - start) is not the same as the Permutation length.
        */
        template <typename T>
        T operator() (const T& container, int start, int last) const;

        template <typename T>
        T operator() (const T& container) const
        {
            return this->operator() (container, 0, container.size());
        }

        /** \brief Returns the number of elements in the Permutation
        * \return Describes the number of elements that the Permutation object can perform on.
        */
        virtual int numElements() const;

    private:
        Vector<int> mPermutation;
    };
}
#include "../src/Permutation/Permutation.inl"
#endif
