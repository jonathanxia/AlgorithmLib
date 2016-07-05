template <typename cont, typename T>
int binarysearch(cont A, T key)
{
    // We are searching for the key in between A[lowerInd] and A[upperInd - 1]
    // The midpoint will be the average, and then we shall confine our search there.
    int lowerInd = 0;
    int upperInd = A.size();
    int midpoint = (lowerInd + upperInd) / 2;

    while(lowerInd != upperInd) //if lowerInd == midpoint, then that means lowerInd and upperInd differ by
        //at most 1
    {
        if(key == A[midpoint])
        {
            return midpoint;
        }
        else if (key < A[midpoint]) //We constrain our search from lowerInd to midpoint
        {
            upperInd = midpoint;
            midpoint = (lowerInd + upperInd) / 2;
        }
        else
        {
            lowerInd = midpoint;
            midpoint = (lowerInd + upperInd) / 2;
        }
    }

    return -1;
}
