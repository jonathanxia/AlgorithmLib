#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <initializer_list>
#include "Vector.h"
#include <utility>
#include <algorithm>

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

        /** \brief Performs exponentiation on a Permutation object
        *
        * \param exp Will basically compose the Permutation object exp times. Note that if perm^(-1) will result in the inverse of the Permutation.
        * \return The Permutation object composed exp times.
        */
        virtual Permutation operator^ (int exp) const;

        /** \brief The subscript operator will return what the Permutation maps to.
        *
        * So, if we have a Permutation object called `perm`, then `perm[1]` will return what index 1 will map to.
        * \throw std::out_of_range This error is thrown when the index is out of range. Must be in between 0 and numElements()-1 inclusive.
        */
    protected:
        virtual int& operator[](int n);
    public:
        virtual const int& operator[](int n) const;

        /** \brief Gives the next Permutation that is lexicographically larger. What this means is that given the Permutation (1, 2, 0), this will be larger
        * than (1, 0, 2) because going from left to right and comparing, the 2 in the second position is bigger than the 0.
        * \param is_largest A boolean storage variable to see whether or not the Permutation was already the largest one (where the elements will be in reverse order)
                            When the largest Permutation has been reached, the identity Permutation (which is the smallest out of all Permutations) will be returned
                            and `is_largest` will be set to `true`. Otherwise, `is_largest` will be set to `false`.
        * \return The smallest Permutation object that is lexicographically larger.
        */
        virtual Permutation next(bool& is_largest) const;

        /** \brief Gives the next Permutation. See Permutation::next(bool & is_largest) for more details. This function just lacks the storage parameter. */
        virtual Permutation next() const;

        /** \brief Gives the previous Permutation. Works similarly to Permutation::next(bool& is_largest) but gives the Permutation that is lexicographically smaller.
        * \param is_smallest A `bool` reference that will be set to `true` if the Permutation object is already the identity Permutation. Otherwise it will
        */
        virtual Permutation prev(bool& is_smallest) const;

        /** \brief Gives the previous Permutation. This time, there is not is_smallest bool reference to set. */
        virtual Permutation prev() const;

        /** \brief Returns the order of the Permutation.
        * The order of the Permutation is the number of times it has to be composed with itself to return back to the identity Permutation.
        * For example, the Permutation (3, 2, 1) has an order of 2, since performing this permutation twice will yield the identity.
        * The Permutation (2, 3, 1) will have an order of 3. Note that the identity Permutation will return an order of 1
        * \return An int which is the order of the Permutation.
        */
        virtual int order() const;

        /** \brief Returns whether the Permutation is the identity Permutation
        \return A boolean which is true if the Permutation is an identity Permutation and false otherwise.
        */
        virtual bool isIdentity() const;

    private:
        Vector<int> mPermutation;
    };
}
#include "../src/Permutation/Permutation.inl"
#endif
