#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <initializer_list>
#include <functional>
namespace AlgLib
{
    /** \brief A class for a Heap object
    * \param T The type of the objects stored in the Heap
    */
    template <typename T>
    class Heap
    {
        public:
            /** \brief Default constructor */
            Heap();
            /** \brief Constructor that takes in `std::vector<T>` */
            Heap(std::vector<T> container);
            /** \brief Initializer list constructor */
            Heap(std::initializer_list<T> args);
            /** \brief Default destructor */
            virtual ~Heap();

            /** \brief Access mContainer
             * \return The current value of the container
             */
            virtual std::vector<T> getContainer() { return mContainer; }
            /** \brief Set mContainer
             * \param val New value to set.
             */
            virtual void setContainer(std::vector<T> val) { mContainer = val; }

            /** \brief Returns the largest element of the Heap and removes it */
            virtual T pop(); // returns the highest parent and then removes it
            /** \brief Returns the largest element of the Heap */
            virtual T top();
            /** \brief Inserts the element `elem` into the Heap */
            virtual void push(T elem);

        protected:

        private:
            std::vector<T> mContainer; //!< Member variable "mContainer"
            int heapSize;
            int parent(int index);
            int left(int index);
            int right(int index);
            void eHeapify(int index);
            void makeHeap();
            void increaseKey(int index, T key);
    };
}
#include "../src/Heap/Heap.cpp"
#endif // HEAP_H
