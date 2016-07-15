#include "Heap.h"
template <typename T, typename S>
void heapSort(T & arr)
{
    AlgLib::Heap<S> arrHeap(arr);
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        arr[i] = arrHeap.pop();
    }
}
