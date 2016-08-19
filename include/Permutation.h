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
        explicit Permutation(int n = 1);

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
        virtual int size() const;

        /** \brief The multiplication operator is overloaded to act like Permutation composition
        *
        * Usage would be something like:
        * `Permutation perm1({3, 2, 1}); Permutation perm2({2, 1, 3}); Permutation perm3 = perm1 * perm2;`
        *
        * This will result in a Permutation of (2, 3, 1).
        * \return The Permutation object that is the composition of the two Permutation objects
        * \throw std::length_error When the Permutations do not have the same size.
        */
        virtual Permutation operator* (const Permutation& other) const;

        /** \brief The subscript operator will return what the Permutation maps to.
        *
        * So, if we have a Permutation object called `perm`, then `perm[1]` will return what index 1 will map to.
        * \throw std::out_of_range This error is thrown when the index is out of range. Must be in between 0 and numElements()-1 inclusive.
        */
        virtual int& operator[](int n);
        virtual const int& operator[](int n) const;

    private:
        Vector<int> mPermutation;
    };
}
#include "../src/Permutation/Permutation.inl"
#endif
