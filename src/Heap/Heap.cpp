#include <vector>
#include <initializer_list>
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
        mContainer.makeHeap();
        heapSize = container.size();
    }

    template <typename T>
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    Heap<T>::Heap(std::initializer_list<T> args) :
        mContainer(args.size())
    {
        int i = 0;
        for(auto c : args)
        {
            mContainer[i] = c;
            i++;
        }
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


}
