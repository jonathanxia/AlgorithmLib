#include <vector>
#include <initializer_list>
#include <functional>
#include <stdexcept>
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
    template <typename T>
    void Heap<T>::push(T elem)
    {
        mContainer.push_back(elem);
        heapSize++;

        int index = heapSize - 1;
        while(index > 0 && elem > mContainer[parent(index)])
        {
            mContainer[index] = mContainer[parent(index)];
            mContainer[parent(index)] = elem;
            index = parent(index);
        }
    }

    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    template <typename T>
    void Heap<T>::increaseKey(int index, T key)
    {
        //PRECONDITION: make sure that key really does increase it
        if(mContainer[index] > key)
        {
            throw std::invalid_argument("key is not bigger than mContainer[index]");
        }

        mContainer[index] = key;
        while(index > 0 && mContainer[index] > mContainer[parent(index)])
        {
            // This exchanges mContainer[index] with its parent
            T tmp = mContainer[index];
            mContainer[index] = mContainer[parent(index)];
            mContainer[parent(index)] = tmp;

            index = parent(index); // Updates the index to the parent index to continue looping
        }
    }


}
