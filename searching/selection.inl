#include <vector>
#include "sorting.h"
namespace AlgLib
{
    template <typename cont, typename E>
    E selection(const cont& A, int i)
    {
        return selection<cont, E>(A, i, A.size());
    }
    template <typename cont, typename E>
    E selection(const cont& A, int i, int length)
    {
        std::vector<E> copyOfA(length);
        // Copies the elements of A over into copyOfA
        for(int m = 0; m < length; m++)
        {
            copyOfA[m] = A[m];
        }

        // This is not linear, but we'll have it be a placeholder
        quickSort(copyOfA);
        return copyOfA[i];
    }
}
