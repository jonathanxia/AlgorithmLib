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
template <typename T>
vector<T> MERGE(vector<T>&, vector<T>&);
/**
* mergeSort(vector<T> & arr)
*
* Sort the elements in container arr with merge sort algorithm
* Parameters:
*   vector<T>& arr: the container to be sorted
* Returns: void
* Additional notes: Sorts in O(n lg n) time
*/

template <typename T>
void mergeSort(vector<T>& arr)
{
    if(arr.size() < 2)
        return;

    vector<T> leftPart, rightPart; //These are the left and right partitions.
    //The following code partitions the arr
    //leftPart takes from index 0 to index arr.size() / 2 (excluding the upper bound)
    //rightPart takes the rest
    for(int i = 0; i < arr.size() / 2; i++)
        leftPart.push_back(arr[i]);
    for(int i = arr.size() / 2; i < arr.size(); i++)
        rightPart.push_back(arr[i]);

    mergeSort(leftPart);
    mergeSort(rightPart);
    arr = MERGE<T>(leftPart, rightPart);
}

template <typename T>
vector<T> MERGE(vector<T>& leftPart, vector<T>& rightPart)
{
    int totalSize = leftPart.size() + rightPart.size(); //totalSize is the combined size of the two vectors
    vector<T> merged(totalSize); //The merged (returned) vector

    int lIndex = 0, rIndex = 0;
    while(lIndex < leftPart.size() && rIndex < rightPart.size())
    {
        merged[lIndex + rIndex] = (leftPart[lIndex] < rightPart[rIndex] ? leftPart[lIndex] : rightPart[rIndex]); //Places the smallest one in merged
        leftPart[lIndex] < rightPart[rIndex] ? lIndex++ : rIndex++; //Updates the indices
    }
    //The following two while loops will grab the remains
    //One of them is guaranteed to be useless
    while(lIndex < leftPart.size())
    {
        merged[lIndex + rIndex] = leftPart[lIndex];
        lIndex++;
    }
    while(rIndex < rightPart.size())
    {
        merged[lIndex + rIndex] = rightPart[rIndex];
        rIndex++;
    }
    return merged;
}


