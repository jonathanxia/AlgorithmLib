#ifndef SORTING_H
#define SORTING_H
#include "../sorting/insertionsort.cpp"
#include "../sorting/mergesort.cpp"
template <typename T>
void insertionSort(T& arr);

template <typename T>
void mergeSort(T& arr);
template <typename T>
T MERGE(T& left, T& right);
#endif // SORTING_H
