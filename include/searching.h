#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED
#include "../searching/binarysearch.cpp"
#include "../searching/inversion.cpp"
template <typename cont, typename T>
int binarysearch(cont A, T key); //search for key within the vector A

template <typename cont>
int inversions(const cont& A); //returns the number of inversions in A
#endif // SEARCHING_H_INCLUDED
