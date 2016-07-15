#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <initializer_list>
#include <functional>
namespace AlgLib
{
    template <typename T>
    class Heap
    {
        public:
            /** Default constructor */
            Heap();
            /** Constructor that takes in vector<T> */
            Heap(std::vector<T> container);
            /** Initializer list constructor */
            Heap(std::initializer_list<T> args);
            /** Default destructor */
            virtual ~Heap();

            /** Access mContainer
             * \return The current value of mContainer
             */
            std::vector<T> GetContainer() { return mContainer; }
            /** Set mContainer
             * \param val New value to set
             */
            void SetContainer(std::vector<T> val) { mContainer = val; }

        protected:

        private:
            std::vector<T> mContainer; //!< Member variable "mContainer"
            int heapSize;
            int parent(int index);
            int left(int index);
            int right(int index);
            void eHeapify(int index);
            void makeHeap();
    };
}
#include "../src/Heap/Heap.cpp"
#endif // HEAP_H
