#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <initializer_list>

namespace AlgLib {
    class Permutation {
        public:
        Permutation(); // Identity
        Permutation(std::vector<int> list);
        
        Permutation operator* (const Permutation& other) const;

        private:
        std::vector<int> myPermutation;

    };
}

#include "../src/Permutation/Permutation.cpp"
#endif