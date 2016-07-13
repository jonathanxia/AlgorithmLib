// TODO: make sure to overload == and != function.

#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <initializer_list>
#include <vector>
#include <utility>

namespace AlgLib {
	template <typename T>
    class Permutation {
    public:
		// Constructors
        Permutation(); 
        Permutation(std::initializer_list<int> word);
		Permutation(std::initializer_list<std::initializer_list<T>> cycles);
		Permutation(std::vector<std::pair<T, T>> pairs);

		// Operators
        Permutation<T> operator* (const Permutation<T>& other) const;
        std::vector<T> operator() (const std::vector<T>& li) const;
		bool operator!= (const Permutation<T>& other) const;
		bool operator== (const Permutation<T>& other) const;
		T operator() (const T elem) const;

		Permutation<T> inverse();
		int order();
		/* For some reason this is creating an error...
		vector<Permutation<T>> cycles();
		*/

    private:
        std::vector<std::pair<T,T>> mPermutation; 
    };
}

#include "../src/Permutation/Permutation.cpp"

#endif