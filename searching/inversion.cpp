#include "sorting.h"
#include "searching.h"
#include <vector>
namespace AlgLib
{
    template <typename cont>
    int inversionRef(cont& A)
    {
        if(A.size() == 1)
        {
            return 0;
        }

        // Now we must split the A in half and then find the inversion of each.
        cont leftPart(A.size() / 2);
        cont rightPart(A.size() - A.size() / 2);
        for(unsigned int i = 0; i < A.size() / 2; i++)
        {
            leftPart[i] = A[i];
        }
        for(unsigned int i = 0; i < A.size() - A.size() / 2; i++)
        {
            rightPart[i] = A[A.size() / 2 + i];
        }
        int totalSoFar = inversionRef(leftPart) + inversionRef(rightPart);
        int totalSize = leftPart.size() + rightPart.size(); //totalSize is the combined size of the two vectors
        cont merged(totalSize); //The merged (returned) vector

        unsigned int lIndex = 0, rIndex = 0;
        int howManyOnLeft = leftPart.size();
        while(lIndex < leftPart.size() && rIndex < rightPart.size())
        {
            merged[lIndex + rIndex] = (leftPart[lIndex] < rightPart[rIndex] ? leftPart[lIndex] : rightPart[rIndex]); //Places the smallest one in merged
            if(leftPart[lIndex] < rightPart[rIndex])
            {
                howManyOnLeft--;
            }
            else
            {
                totalSoFar += howManyOnLeft;
            }
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
        A = merged;
        return totalSoFar;
    }

    template <typename cont>
    int inversions(const cont& A)
    {
        cont copyA(A); //the copy of A that we will be using to sort

        //Now we will perform a merge sort algorithm but keep track of inversions
        return inversionRef<cont>(copyA);

    }
}

