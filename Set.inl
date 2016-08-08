#include <set>
#include <utility>
#include "Set.h"

namespace AlgLib {
	template<typename T>
	template<typename S>
	Set<pair<T, S>> Set<T>::operator*(const Set<S>& other) const {
		Set<pair<T,S>> product;
		for (auto i = this->begin(); i != this->end(); i++) {
			for (auto j = other.begin(); j != other.end(); j++) {
				product.insert(std::make_pair(*i, *j));
			}
		}
	}
}