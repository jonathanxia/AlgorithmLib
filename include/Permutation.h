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
        Permutation(std::initializer_list<int> p);
		Permutation(std::initializer_list<initializer_list<T>> p)
        
		// Multiply
        Permutation operator* (const Permutation& other) const;
		// Permute
        std::vector<int> operator() (const std::vector<int>& li) const;
		// Inverse
		Permutation inverse();
		// Order
		Permutation order();
		// Cycles
		Permutation cycles();
		

    private:
        std::vector<std::pair<T,T>> mPermutation; 
    };
}

#include "../src/Permutation/Permutation.cpp"
#endif