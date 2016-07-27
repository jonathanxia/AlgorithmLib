#ifndef MATRIX_H
#define MATRIX_H

#include<initializer_list>
#include<vector>
#include<iostream>
#include<string>

namespace AlgLib {

    /** \brief The Matrix class, which stores a rectangular Matrix
    * \param T The type of the objects to be stored in each entry of the Matrix.
    */
	template<typename T>
	class Matrix {

	public:
	    /** \brief Constructor that takes in row and column. Entries are set to 0.
	    * \param row The number of rows the matrix has.
	    * \param column The number of columns the matrix has.
        */
		Matrix(int row, int column);
		/** \brief Constructor that takes in a 2D-vector
		* \param theMatrix Each vector should be a row vector. That means that theMatrix[0] should be
		*        the first row of the matrix
		*/
		Matrix(const std::vector< std::vector<T> >& theMatrix);
		/** \brief Constructor that takes in an initializer list.
		* \param m The initializer list. See Matrix::Matrix(const std::vector< std::vector<T> >& theMatrix) for how to format.
		*/
		Matrix(std::initializer_list<std::initializer_list<T> > m); // Probably should add more constructors later

		/**
		* \brief Copy constructor
		* \param rhs The Matrix object to be copied
		*/
		Matrix(const Matrix& rhs);

		/**
		* \brief Accesses the row vector
		* \param row The row number in the Matrix. The first row is numbered 0
		* \return A std::vector<T> reference to the row vector. Note that assignment can be done. Use with caution. An element can be accessed like [1][2].
		*/
		virtual std::vector<T>& operator[](int row); // Only row because we can't nest it from this class. The vector class can take care of the other

		/**
		* \brief Multiplies two matrices
		*/
		virtual Matrix operator*(const Matrix& other) const;
		/**
		* \brief Adds two matrices
		*/
		virtual Matrix operator+(const Matrix& other) const;
		/**
		* \brief Subtracts two matrices
		*/
		virtual Matrix operator-(const Matrix& other) const;
		/*
		* Pushing implementation until later - 7/18/16 Jonathan Xia
		virtual Matrix inverse();
		virtual Matrix transpose();
		virtual int determinant();
		*/

        /** \brief Returns the matrix in vector form
        * \return A nested std::vector. Each element of the outer vector is a row vector. So, `getVectors()[0]` would be the first row of the
        matrix as a std::vector<T>
        */
		virtual std::vector< std::vector<T> > getVectors() const;

		/** \brief Sets the value of an entry in the matrix
		* \param row The row number of the entry. Note that numbering starts at 0, so the first row is numbered 0
		* \param col The column number of the entry. Numbering starts at 0.
		* \param value The value that the entry will take on
		*/
		virtual void setValue(int row, int col, T value);
		/** \brief Gets the value of an entry in the matrix
		* \param row The row number of the entry to be accessed. Numbering starts at 0, so the first row is numbered 0.
		* \param col The column number of the entry to be accessed. Numbering starts at 0.
		* \return The value at Matrix[row][col]
		*/
		virtual T getValue(int row, int col) const;
		/** \brief Gives the number of rows in the Matrix.
		* \return The number of rows in the Matrix
		*/
		virtual int numRows() const;
		/** \brief Gives the number of columns in the Matrix.
		* \return The number of columns in the Matrix
		*/
		virtual int numColumns() const;

	protected:
	    /** \brief Adds a row to the bottom of the Matrix */
        virtual void addRow();
        /** \brief Adds a column to the right of the Matrix */
        virtual void addColumn();

	private:
		std::vector< std::vector<T> > mMatrix;
	};
}

#include "../src/Matrix/Matrix.cpp"

#endif
