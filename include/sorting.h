#ifndef SORTING_H
#define SORTING_H
#include "../sorting/insertionsort.cpp"
#include "../sorting/mergesort.cpp"
#include "../sorting/heapsort.cpp"
namespace AlgLib
{
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
}
#endif // SORTING_H
