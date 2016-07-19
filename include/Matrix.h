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
		Matrix(const std::vector< std::vector<T> >& theMatrix);
		Matrix(std::initializer_list<std::initializer_list<T> > m); // Probably should add more constructors later

		/**
		* Copy constructor
		*/
		Matrix(const Matrix& rhs);

		virtual std::vector<T>& operator[](int row); // Only row because we can't nest it from this class. The vector class can take care of the other

		virtual Matrix operator*(const Matrix& other) const;
		virtual Matrix operator+(const Matrix& other) const;
		virtual Matrix operator-(const Matrix& other) const;
		/*
		* Pushing implementation until later - 7/18/16 Jonathan Xia
		virtual Matrix inverse();
		virtual Matrix transpose();
		virtual int determinant();
		*/

		virtual std::vector< std::vector<T> > getVectors() const;
		virtual void setValue(int row, int col, T value);
		virtual T getValue(int row, int col) const;
		virtual int numRows() const;
		virtual int numColumns() const;

	protected:
        virtual void addRow();
        virtual void addColumn();

	private:
		std::vector< std::vector<T> > mMatrix;
	};
}

#include "../src/Matrix/Matrix.cpp"

#endif
