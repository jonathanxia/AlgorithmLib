#include <initializer_list>
#include <vector>
#include <exception>
#include <algorithm>
#include <utility>

// Constructors
template<typename T>
AlgLib::Permutation::Permutation(std::initializer_list<T> list) {
    mPermutation.reserve(list.size());
	int i = 1;
    for(auto c: list) {

        mPermutation.push_back(make_pair(i, c));
    }
}

template<typename T>
AlgLib::Permutation::Permutation(std::initializer_list<std::initializer_list<T>> p) {
	for (std::initializer_list<std::initializer_list<T>>::iterator iter = p.begin(); iter != p.end(); iter++) {
		for (std::initalizer_list<T>::iterator i = iter->begin(); i != iter->end(); i++) {
			if (i.next() != iter->end()) {
				std::pair<T, T> j = std::make_pair(*i, *i.next());
				mPermutation.push_back(j);
			}
			else {
				std::pair<T, T> j = std::make_pair(*i, *iter.begin());
				mPermutation.push_back(j);
			}
		}
	}
}

template<typename T>
std::vector<int> AlgLib::Permutation::operator()(const std::vector<T>& li) const {
    std::vector<int> newli;
    newli.reserve(li.size());
    for(int i = 0; i < li.size(); i ++) {
        newli[i] = li[mPermutation[i]];
    }
    return newli;
}

template<typename T>
AlgLib::Permutation AlgLib::Permutation::operator* (const Permutation& other) const {

}