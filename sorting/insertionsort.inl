#include <vector>

namespace AlgLib
{
    template <typename T>
    void insertionSort(T& arr, int start, int last)
    {

        //Loop invariant:
        //arr[0] to arr[i-1] inclusive is already sorted
        for (int i = start+1; i < last; i++)
        {
            int newIndex = start; //newIndex will store where arr[i] should go
            while(arr[i] > arr[newIndex])
            {
                newIndex++;
            }
            //now at this point, we know that arr[i] <= arr[newIndex]
            int temp = arr[i]; //saves the value of arr[i]
            for (int j = i; j > newIndex; j--)
            {
                arr[j] = arr[j-1]; //This shifts everything over
                //Edge case: j = newIndex+1, shifts arr[newIndex] to arr[newIndex+1]

            }
            arr[newIndex] = temp;
        }
        //return arr;
    }
    template <typename T>
    void insertionSort(T& arr)
    {
        insertionSort(arr, 0, arr.size());
    }
}


