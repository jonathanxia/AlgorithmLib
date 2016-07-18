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

		/**
		* Copy constructor
		*/
		Matrix(const Matrix& rhs);

		/*virtual Matrix operator*(const Matrix& other) const;
		virtual Matrix operator+(const Matrix& other) const;
		virtual Matrix operator-(const Matrix& other) const;
		virtual Matrix inverse();
		virtual Matrix transpose();
		virtual int determinant(); */

		//virtual void toString(); // Temporary solution to viewing... i just found out that you can return an output stream object

	private:
		std::vector<std::vector<T>> mMatrix;
	};
}

#include "../src/Matrix/Matrix.cpp"

#endif
