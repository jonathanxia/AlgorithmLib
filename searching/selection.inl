#include <vector>
#include "sorting.h"
#include "../sorting/quicksort.inl"
#include <utility>
#include <stdexcept>
#include <sstream>
namespace AlgLib
{
    template <typename cont, typename E>
    E cSelection(cont& A, int i, int start, int last)
    {
        if (i < 0 || i >= last - start)
        {
            std::ostringstream sout;
            sout << i << " is not between 0 and last-start-1 = " << last << " - " << start << " - 1";
            throw std::out_of_range(sout.str());
        }
        int length = last - start;
        // We now split A into groups of 5 and then do an insertion sort on each group
        std::vector<E> medians((length - 1) / 5 + 1); // basically the ceiling of length/5
        for(int part = 0; 5 * (part + 1) < length; part++)
        {
            insertionSort(A, start + 5 * part, start + 5 * (part + 1));
            medians[part] = A[start + 5 * part + 2]; // The median of A[5 * part...5 * (part + 1)]
        }
        // Deal with the edge case
        insertionSort(A, start + 5 * ( (length - 1) / 5), last);
        medians[(length - 1) / 5] = A[start + 5 * ( (length - 1) / 5) + ( (length-1) % 5) / 2];
        /* Now we have to find the median of medians */
        // This can be done recursively
        E medianOfMedians;
        if(length > 1)
            medianOfMedians = selection<std::vector<E>, E>(medians, medians.size() / 2);
        else
            medianOfMedians = medians[0];

        // Now we want to perform the quicksort partition with medianOfMedians being the pivot.
        // First find the median's index...
        int medianIndex = start;
        while (medianIndex < last)
        {
            if (A[medianIndex] == medianOfMedians)
            {
                break;
            }
            medianIndex++;
        }
        std::swap(A[medianIndex], A[last - 1]);
        int divideIndex = PARTITION(A, start, last);
        if(divideIndex == start + i)
            return A[divideIndex];
        else
        {
            if (start + i < divideIndex)
            {
                return cSelection<cont, E>(A, i, start, divideIndex);
            }
            else
            {
                return cSelection<cont, E>(A, i + start - divideIndex - 1, divideIndex + 1, last);
            }
        }
    }
    template <typename cont, typename E>
    E selection(const cont& A, int i, int start, int last)
    {
        std::vector<E> copyOfA(last - start);
        for(int j = start; j < last; j++)
        {
            copyOfA[j - start] = A[j];
        }
        return cSelection<cont, E>(copyOfA, i, 0, last-start);
    }
    template <typename cont, typename E>
    E selection(const cont& A, int i)
    {
        return selection<cont, E>(A, i, 0, A.size());
    }
}
