#ifndef SORTING_H
#define SORTING_H

#include <functional>

namespace AlgLib
{
    /** \defgroup sorting "sorting.h"
    * @{
    */
    /** \brief Performs an insertion sort on the container
     *
     * \tparam T The type of the container e.g. `std::vector<int>`
     * \tparam E The type of the element in the container e.g. `int`
     * \param arr The container to be sorted
     * \param start The index of where to start to sort. Defaults to 0.
     * \param last The index of where to end. Note that the last index is not going to be part of the sort. Defaults to arr.size().
     * \param compare A function that has prototype `bool compare(E x, E y)` which returns true if x < y. Defaults to `x < y`.
     *
     */
    template <typename T, typename E>
    void insertionSort(T& arr, int start, int last, std::function<bool(E, E)> compare = [](E x, E y){ return x < y; });

    template <typename T, typename E>
    void insertionSort(T& arr, std::function<bool(E, E)> compare = [](E x, E y){ return x < y; });

    /** \brief Performs a merge sort on the container
     *
     * \tparam T The type of the container e.g. `std::vector<int>`
     * \param arr The container to be sorted
     *
     */
    template <typename T>
    void mergeSort(T& arr);
    template <typename T>
    T MERGE(T& left, T& right);

    /**
     * \brief Performs a heap sort on the container
     * \tparam T The type of the container e.g. `std::vector<int>`
     * \tparam S The type that is stored in the container e.g. `int`
     * \param arr The container to be sorted
     *
     */
    template <typename T, typename S>
    void heapSort(T & arr);

    /** \brief Performs a quick sort on the container
    *
    * Sorts the container arr in non-decreasing order from `arr[startIndex]` to `arr[endIndex-1]`
    * \tparam T The type of the container e.g. `std::vector<int>`
    * \tparam E The element type that is stored in the container.
    * \param arr The container to be sorted.
    * \param startIndex Where to begin sorting. Defaults to 0.
    * \param endIndex Where to stop sorting. Note that endIndex will not be included in the sort. Defaults to `arr.size()`.
    * \param compare A function that takes two parameters and returns true if the first parameter is less than the second parameter. Defaults to
    *                x < y.
    *
    */
    template <typename T, typename E>
    void quickSort(T & arr, int startIndex, int endIndex, std::function<bool(E, E)> compare = [](E x, E y){ return x < y; });

    template <typename T, typename E>
    void quickSort(T& arr, std::function<bool(E, E)> compare = [](E x, E y){ return x < y; }); // simply calls quickSort(arr, 0, arr.size())

    /** \brief Performs a counting sort on the container
    *
    * Sorts the container `arr` in linear time, with the stipulation that `arr` must be a container of ints
    * \tparam T The type of the container e.g. `std::vector<int>` that **stores ints**
    * \param arr The container to be sorted.
    * \param start Where to begin sorting. Defaults to 0.
    * \param last The index to stop sorting at. Note that last will not be included in the sort. Defaults to arr.size().
    *
    * This will sort arr[start....(last-1)]. Performs the sort in O(n + k) where n is the number of elements and k is max_element - min_element.
    */
    template <typename T>
    void countingSort(T& arr, int start, int last);

    template <typename T>
    void countingSort(T& arr) // This basically provides a "default parameter" illusion
    {
        countingSort(arr, 0, arr.size());
    }

    /**@} */
}
#include "../sorting/insertionsort.inl"
#include "../sorting/mergesort.inl"
#include "../sorting/heapsort.inl"
#include "../sorting/quicksort.inl"
#include "../sorting/countingsort.inl"

#endif // SORTING_H
