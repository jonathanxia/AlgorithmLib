#ifndef SORTING_H
#define SORTING_H
#include "insertionsort.cpp"
#include "mergesort.cpp"
template <typename T>
void insertionSort(vector<T>& arr);

template <typename T>
void mergeSort(vector<T>& arr);
template <typename T>
vector<T> MERGE(vector<T>& left, vector<T>& right);
#endif // SORTING_H
