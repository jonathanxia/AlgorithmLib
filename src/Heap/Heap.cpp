#include <vector>
#include <initializer_list>
#include <functional>
namespace AlgLib
{
    template <typename T>
    Heap<T>::Heap() :
        heapSize(0)
    {
        //ctor
    }

    template <typename T>
    Heap<T>::Heap(std::vector<T> container) :
        mContainer(container)
    {
        heapSize = container.size();
        makeHeap();
    }

    template <typename T>
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    Heap<T>::Heap(std::initializer_list<T> args) :
        mContainer(args.size()),
        heapSize(args.size())
    {
        int i = 0;
        for(auto c : args)
        {
            mContainer[i] = c;
            i++;
        }
        makeHeap();
    }

    template <typename T>
    T Heap<T>::top()
    {
        return mContainer[0];
    }

    template <typename T>
    T Heap<T>::pop()
    {
        T retValue = mContainer[0];
        mContainer[0] = mContainer[heapSize - 1]; // moves the last element in the container to the top
        //Now resize and perform heap action
        heapSize--;
        mContainer.resize(heapSize);

        eHeapify(0);
        return retValue;
    }

    template <typename T>
    Heap<T>::~Heap()
    {
        //dtor
    }

    /** @brief gets the index of the child to the right
      *
      * (documentation goes here)
      */
    template <typename T>
    int Heap<T>::right(int index)
    {
        return 2 * (index + 1);
    }

    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    template <typename T>
    int Heap<T>::left(int index)
    {
        return 2 * index + 1;
    }

    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    template <typename T>
    int Heap<T>::parent(int index)
    {
        return (index - 1) / 2;
    }

    template <typename T>
    // Assumes that the Heaps rooted to the left and right are max-heaps
    // but element at index might not be
    void Heap<T>::eHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;
        if(l < heapSize && mContainer[l] > mContainer[index])
        {
            largest = l;
        }
        if(r < heapSize && mContainer[r] > mContainer[largest])
        {
            largest = r;
        }
        if(largest != index)
        {
            T tmp = mContainer[index];
            mContainer[index] = mContainer[largest];
            mContainer[largest] = tmp;
            eHeapify(largest);
        }
    }

    template <typename T>
    void Heap<T>::makeHeap()
    {
        for(int i = (heapSize + 1) / 2; i >= 0; i--)
        {
            eHeapify(i);
        }
    }
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    void Heap::push(T elem)
    {

    }

}
