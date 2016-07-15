#ifndef MATRIX_H
#define MATRIX_H

#include<initializer_list>
#include<vector>
#include<iostream>
#include<string>

namespace AlgLib {
	template<typename T>
	class Matrix {

	public:
		Matrix(int row, int column);
		Matrix(std::initializer_list<std::initializer_list<T> > m); // Probably should add more constructors later

		Matrix operator*(const Matrix& other) const;
		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;
		Matrix inverse();
		Matrix transpose();
		int determinant();

		void toString(); // Temporary solution to viewing... i just found out that you can return an output stream object

	private:
		std::vector<std::vector<T>> mMatrix;
	};
}

#include "../src/Matrix/Matrix.cpp"

#endif