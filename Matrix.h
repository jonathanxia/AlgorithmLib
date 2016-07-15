#ifndef MATRIX_H
#define MATRIX_H

#include<initializer_list>
#include<vector>

namespace AlgLib {
	template<unsigned int R, unsigned int C>
	class Matrix {
		Matrix();
		Matrix(std::initializer_list<std::initializer_list<int> >); // Probably should add more constructors later

		
		
	};
}

#endif