#pragma once
#include <utility>
#include <random>
#include <functional>
namespace AlgLib
{
    /** \brief Computes the index `ind` that will partition the container `arr`
    *
    * Returns index `ind` such that `A[ind]` \f$ \ge \f$ `A[i]` for \f$ startIndex \le i < ind \f$ and `A[ind]` \f$ \ge \f$ `A[i]` for \f$
    * ind < i \le endIndex \f$
    *
    * \param T The type of the container
    * \param startIndex The starting index
    * \param endIndex The ending index
    *
    * \return Partitions `arr` into `arr[startIndex...ind-1]` and `arr[ind+1...endIndex]` and returns the value of `ind`.
    * Note that this function will modify the container `arr`
    */
    template <typename T, typename E>
    int PARTITION(T & arr, int startIndex, int endIndex, std::function<bool(E, E)> compare = [](E x, E y){ return x < y; });

    template <typename T, typename E>
    void quickSort(T & arr, int startIndex, int endIndex, std::function<bool(E, E)> compare)
    {
        if (startIndex < endIndex)
        {
            std::random_device rd; // This will generate a random number to act as a seed
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(startIndex, endIndex - 1);

            int randomIndex = dis(gen);
            std::swap(arr[randomIndex], arr[endIndex - 1]);
            int q = PARTITION(arr, startIndex, endIndex, compare);
            quickSort(arr, startIndex, q, compare);
            quickSort(arr, q + 1, endIndex, compare);
        }
    }

    template <typename T, typename E>
    int PARTITION(T & arr, int startIndex, int endIndex, std::function<bool(E, E)> compare)
    {
        // The element at endIndex will end up being the split between the two halves.

        // We will go through arr to see whether it is bigger or smaller than arr[endIndex]
        // Everything to the left of divider is < arr[endIndex] and everything with index >= divider is >= arr[endIndex]
        int divider = startIndex;

        for (int i = startIndex; i < endIndex - 1; i++) // We stop one short since we don't need to look at arr[endIndex]
        {
            if(compare(arr[i], arr[endIndex - 1]))
            {
                std::swap(arr[i], arr[divider]);
                divider++;
            }
        }
        std::swap(arr[divider], arr[endIndex - 1]);
        return divider;
    }

    template <typename T, typename E>
    void quickSort(T& arr, std::function<bool(E, E)> compare)
    {
        quickSort<T>(arr, 0, arr.size(), compare);
    }
}
