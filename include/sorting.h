#ifndef SORTING_H
#define SORTING_H
#include "../sorting/insertionsort.cpp"
#include "../sorting/mergesort.cpp"
#include "../sorting/heapsort.cpp"
namespace AlgLib
{
    template <typename T>
    void insertionSort(T& arr);

    template <typename T>
    void mergeSort(T& arr);
    template <typename T>
    T MERGE(T& left, T& right);

    template <typename T, typename S>
    void heapSort(T & arr);
}
#endif // SORTING_H
