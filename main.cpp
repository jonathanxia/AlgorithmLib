#include <iostream>
#include <vector>
#include "./sorting/sorting.h"
using namespace std;

int main()
{
    vector<int> x = {1, 3, 5, 7, 2, 4, 6};
    mergeSort<int>(x);

    for (int i = 0; i < 7; i++)
    {
        cout << x[i] << endl;
    }

    return 0;
}
