
namespace AlgLib
{
    template <typename T>
    T MERGE(T&, T&);

    /**
    * \brief Sort the elements in container arr with merge sort algorithm
    * @param arr the container to be sorted
    * @return void
    */
    template <typename T>
    void mergeSort(T& arr)
    {
        if(arr.size() < 2)
            return;

        T leftPart, rightPart; //These are the left and right partitions.
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
    T MERGE(T& leftPart, T& rightPart)
    {
        int totalSize = leftPart.size() + rightPart.size(); //totalSize is the combined size of the two vectors
        T merged(totalSize); //The merged (returned) vector

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
}

