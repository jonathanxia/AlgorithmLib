#ifndef SORTING_H
#define SORTING_H

namespace AlgLib
{
    /** \defgroup sorting "sorting.h"
    * @{
    */
    /** \brief Performs an insertion sort on the container
     *
     * \param T The type of the container e.g. `std::vector<int>`
     * \param arr The container to be sorted
     *
     */
    template <typename T>
    void insertionSort(T& arr);

    /** \brief Performs a merge sort on the container
     *
     * \param T The type of the container e.g. `std::vector<int>`
     * \param arr The container to be sorted
     *
     */
    template <typename T>
    void mergeSort(T& arr);
    template <typename T>
    T MERGE(T& left, T& right);

    /** \brief Performs a heap sort on the container
     *
     * \param T The type of the container e.g. `std::vector<int>`
     * \param S The type that is stored in the container e.g. `int`
     * \param arr The container to be sorted
     *
     */
    template <typename T, typename S>
    void heapSort(T & arr);

    /** \brief Performs a quick sort on the container
    *
    * Sorts the container arr in non-decreasing order from `arr[startIndex]` to `arr[endIndex]`
    * \param T The type of the container e.g. `std::vector<int>`
    * \param arr The container to be sorted.
    *
    */
    template <typename T>
    void quickSort(T& arr);

    /** \brief Performs a counting sort on the container
    *
    * Sorts the container `arr` in linear time
    * \param T The type of the container e.g. `std::vector<int>` that **stores ints**
    * \param arr The container to be sorted.
    *
    * Performs the sort in O(n + k) where n is the number of elements and k is max_element - min_element.
    */
    template <typename T>
    void countingSort(T& arr);
    /**@} */
}
#include "../sorting/insertionsort.inl"
#include "../sorting/mergesort.inl"
#include "../sorting/heapsort.inl"
#include "../sorting/quicksort.inl"
#include "../sorting/countingsort.inl"
#endif // SORTING_H
