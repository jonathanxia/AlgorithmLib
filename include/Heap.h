#ifndef HEAP_H
#define HEAP_H

namespace AlgLib
{
    template <typename T>
    class Heap
    {
        public:
            /** Default constructor */
            Heap();
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
    };
}
#include "../src/Heap/Heap.cpp"
#endif // HEAP_H
