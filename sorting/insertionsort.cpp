#include <vector>
#include <iostream>
using namespace std;
/**
* insertionSort(vector<T>& arr)
*
* Sorts the elements of container arr using the insertion sort algorithm
* Parameters:
*      vector<T>& arr: a reference to the container to be sorted
*
* Returns: void
* Additional Notes: Runs in O(n^2) time
*
*/
template <typename T>
void insertionSort(vector<T>& arr)
{

    //Loop invariant:
    //arr[0] to arr[i-1] inclusive is already sorted
    for (int i = 1; i < arr.size(); i++)
    {
        int newIndex = 0; //newIndex will store where arr[i] should go
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


