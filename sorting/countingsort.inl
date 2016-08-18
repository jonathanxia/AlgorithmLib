#include <vector>
namespace AlgLib
{
    template <typename T>
    void countingSort(T& arr, int start, int last)
    {
        int minElemI = start; // the index of the minimum element
        int maxElemI = start; // the index of the maximum element
        // This is linear

        // This will find the values of minElemI and maxElemI
        for (int i = start; i < last; i++)
        {
            if(arr[minElemI] > arr[i])
            {
                minElemI = i;
            }
            if(arr[maxElemI] < arr[i])
            {
                maxElemI = i;
            }
        }

        // Now we must have a counting container.
        // counts[i] stores how many occurrences of arr[minElemI] + i there are.
        std::vector<int> counts(arr[maxElemI] - arr[minElemI] + 1);
        for(int i = start; i < last; i++)
        {
            counts[arr[i] - arr[minElemI]]++;
        }

        int ind = start;
        int minElem = arr[minElemI]; // safe-keep this because it will be altered
        for (int i = 0; i < (int) counts.size(); i++)
        {
            for(int j = 0; j < (int)counts[i]; j++)
            {
                arr[ind] = minElem + i;
                ind++;
            }
        }
        // Done!
    }
}
