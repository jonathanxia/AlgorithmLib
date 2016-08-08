#pragma once
#include <set>
#include <utility>

namespace AlgLib {
	template<typename T>
	class Set : public std::set<T> {
	public:
		template<typename S>
		Set<pair<T, S>> operator*(const Set<S>& other) const;
	};

	template<typename T>
	class Group : public Set<T> {
		Group operator/(const Group& other) const;
	};

	template<typename T>
	class Ring : public Set<T> {
		Ring operator/(const Ring& other) const;
	};
}
