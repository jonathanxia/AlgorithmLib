#include <initializer_list>

AlgLib::Permutation::Permutation(std::initializer_list list) {
    mPermutation.reserve(list.size());
    for(auto c: args) {
        mPermutation.push_back(c);
    }
}

vector<int> AlgLib::Permutation::permute(vector<int> li) {
    vector<int> newli;
    newli.reserve(li.size());
    for(int i = 0; i < li.size(); i ++) {
        newli[i] = li[mPermutation[i]];
    }
    return newli;
}