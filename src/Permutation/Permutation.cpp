#include <initializer_list>
#include <vector>
#include <exception>
#include <algorithm>
#include <utility>
#include "..\..\include\Permutation.h"

// TODO: add precondition checking... 


// Constructors
template<typename T>
AlgLib::Permutation<T>::Permutation() {
}

template<typename T>
AlgLib::Permutation<T>::Permutation(std::initializer_list<int> word) {
	mPermutation.reserve(word.size());
	int i = 1;
	for (auto c : word) {
		mPermutation.push_back(make_pair(i, c));
		i++;
	}
}

template<typename T>
AlgLib::Permutation<T>::Permutation(std::initializer_list<std::initializer_list<T>> cycles) {
	for (auto iter = cycles.begin(); iter != cycles.end(); iter++) {
		std::initializer_list<T>::iterator i;
		for (i = iter->begin(); i + 1 != iter->end(); i++) {
			mPermutation.push_back(make_pair(*i, *(i + 1)));
		}
		mPermutation.push_back(make_pair(*i, *iter->begin()));
	}
}

template<typename T>
AlgLib::Permutation<T>::Permutation(std::vector<std::pair<T, T>> pairs) {
	for (auto i : pairs) {
		mPermutation.push_back(i); //Find out if it's ok to just do 'mPermutation = pairs' or not.
	}
}

// TODO: improve implementation. try to use binary search when the type has overloaded operator>
template<typename T>
std::vector<T> AlgLib::Permutation<T>::operator() (const std::vector<T>& li) const {
	std::vector<T> newList;
	for (auto i = li.begin(); i != li.end(); i++) {
		bool br = false;
		for (auto j = mPermutation.begin(); j != mPermutation.end(); j++) {
			if (j->first == *i) {
				newList.push_back(j->second);
				br = true;
				break;
			}
		}
		if (!br) { // If identity
			newList.push_back(*i);
		}
	}
	return newList;
}

template<typename T>
T AlgLib::Permutation<T>::operator() (const T elem) const {
	for (auto j = mPermutation.begin(); j != mPermutation.end(); j++) {
		if(j->first == elem) {
			return j->second;
		}
	}
	return elem;
}

template<typename T> // Not tested yet
AlgLib::Permutation<T> AlgLib::Permutation<T>::inverse() {
	std::vector < std::pair<T, T>> pairs;
	for (auto i : mPermutation) {
		pairs.push_back(make_pair(i.second, i.first));
	}
	AlgLib::Permutation<T> inv(pairs);
	return inv;
}

template<typename T> // Not Tested yet
AlgLib::Permutation<T> AlgLib::Permutation<T>::operator*(const Permutation<T>& other) const {
	std::vector<std::pair<T, T>> pairs;
	for (auto i = other.mPermutation.begin(); i != other.mPermutation.end(); i++) {
		pairs.push_back(std::make_pair(i->first, (*this)(i->second)));
	}
	AlgLib::Permutation<T> prod(pairs);
	return prod;
}

template<typename T> // Not tested and this seems sketchy but idk it might work
int AlgLib::Permutation<T>::order() {
	AlgLib::Permutation<T> permutation = *this;
	AlgLib::Permutation<T> identity;
	int counter = 1;
	while (permutation != identity) {
		permutation = permutation * (*this);
		counter++;
	}
	return counter;
}

template<typename T>
bool AlgLib::Permutation<T>::operator==(const AlgLib::Permutation<T>& other) const {
	for (auto i = other.mPermutation.begin(); i != other.mPermutation.end(); i++) {
		bool exists = false;
		if (i->first == i->second) {
			continue;
		}
		for (auto j = this->mPermutation.begin(); j != this->mPermutation.end(); j++) {
			if (i->first == j->first && i->second == j->second) {
				exists = true;
			}
		}
		if (!exists) {
			return false;
		}
	}
	for (auto i = this->mPermutation.begin(); i != this->mPermutation.end(); i++) {
		bool exists = false;
		if (i->first == i->second) {
			continue;
		}
		for (auto j = other.mPermutation.begin(); j != other.mPermutation.end(); j++) {
			if (i->first == j->first && i->second == j->second) {
				exists = true;
			}
		}
		if (!exists) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool AlgLib::Permutation<T>::operator!=(const AlgLib::Permutation<T>& other) const {
	return !(*this == other);
}