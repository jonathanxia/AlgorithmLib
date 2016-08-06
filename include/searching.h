#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED
#include "../searching/binarysearch.cpp"
#include "../searching/inversion.cpp"
namespace AlgLib
{
    /**
    * \defgroup searching "searching.h"
    * @{
    */
    /**
    *   \brief Searches a sorted container A for an element key
    *   @param cont the container that contains the elements of type T
    *   @param T the type of the elements in the container
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
    *   @param cont the type of the container
    *   @param A the container
    *   @return The number of inversions
    */
    template <typename cont>
    int inversions(const cont& A); //returns the number of inversions in A

    /**
    @}
    */
}

#endif // SEARCHING_H_INCLUDED
