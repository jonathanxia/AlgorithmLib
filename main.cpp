#include <iostream>
#include <vector>
#include "./sorting/sorting.h"
#include "./searching/searching.h"
using namespace std;

int main()
{
    vector<int> x = {1, 3, 5, 7, 2, 4, 6, 10, 14, 15};
    mergeSort<int>(x);
    cout << binarysearch(x, 2) << endl;

    return 0;
}
