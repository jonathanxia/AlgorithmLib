#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED
namespace AlgLib
{
    /**
    * \defgroup searching "searching.h"
    * @{
    */
    /**
    *   \brief Searches a sorted container A for an element key
    *   @tparam cont the container that contains the elements of type T
    *   @tparam T the type of the elements in the container
    *   @param A the container that has the elements of type T
    *   @param key the element to be found
    *   @return the index the element key is at if the key is in A. If not in A, if the element would be between position x and x+1
                then the value of -x-2 is returned.
    */
    template <typename cont, typename T>
    int binarysearch(cont A, T key); //search for key within the vector A

    /**
    *   \brief Counts the number of inversions in a container A. An inversion is a pair
            of elements A[i] and A[j] such that i < j and A[i] > A[j]. Finds in O(n log n) time.
    *   @tparam cont the type of the container
    *   @param A the container
    *   @return The number of inversions
    */
    template <typename cont>
    int inversions(const cont& A); //returns the number of inversions in A

    /**
    * \brief Returns the element that would be at index i if the container A was sorted
    * \tparam cont The type of the container to be sorted
    * \tparam E The type of the element stored in the container

    * \param A The container
    * \param i The index to pass in
    * \param start The index to start searching in. Defaults to 0 if not provided
    * \param last The index to end searching. The value of A[last] will not be considered in selection. Defaults to A.size().
    * \return The index of the object that is the (i+1)-th largest value from A[start...last-1]. In other words, if A[start...last-1] was sorted, then
    * this function would return the index of the number that would be at index `start + i`.
    */
    template <typename cont, typename E>
    E selection(const cont& A, int i, int start, int last);

    template <typename cont, typename E>
    E selection(const cont& A, int i);



    /**
    @}
    */
}
#include "../searching/binarysearch.inl"
#include "../searching/inversion.inl"
#include "../searching/selection.inl"

#endif // SEARCHING_H_INCLUDED
