#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <initializer_list>

namespace AlgLib {
    class Permutation {
        public:
        Permutation(); // Identity
        Permutation(std::initializer_list<int> list);
        
        Permutation operator* (const Permutation& other) const;
        vector<int> permute(vector<int> li);

        private:
        std::vector<int> mPermutation;

    };
}

#include "../src/Permutation/Permutation.cpp"
#endif