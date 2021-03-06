#include <vector>
#include <string>
#include <stdexcept>
#include "AlExcept.h"
#include "Vector.h"

namespace AlgLib
{
    template <typename T>
    Matrix<T>::Matrix(int row, int column) :
        mMatrix(row, AlgLib::Vector<T>(column, T(0))), // creates 0-matrix
        rows(row),
        columns(column)
    {
    }

    template <typename T>
    Matrix<T>::Matrix(const std::vector< std::vector<T> >& theMatrix) :
        rows(theMatrix.size()),
        columns(theMatrix[0].size())
    {
        mMatrix.reserve(rows);

        for(int i = 0; i < (int) theMatrix.size() - 1; i++)
        {
            if(theMatrix[i].size() != theMatrix[i+1].size())
                throw bad_dimension("Matrix has inconsistent dimensions");
        }
        for(auto it = theMatrix.begin(); it != theMatrix.end(); ++it)
        {
            mMatrix.push_back(AlgLib::Vector<T>());
            for(auto jt = it->begin(); jt != it->end(); ++jt)
            {
                mMatrix[it - theMatrix.begin()].push_back(*jt);
            }
        }
    }

    template <typename T>
    Matrix<T>::Matrix(const std::vector< AlgLib::Vector<T> >& theMatrix) :
        mMatrix(theMatrix.size()),
        rows(theMatrix.size()),
        columns(theMatrix[0].size())
    {
        for(int i = 0; i < (int) theMatrix.size() - 1; i++)
        {
            if(theMatrix[i].size() != theMatrix[i+1].size())
                throw std::invalid_argument("Matrix has inconsistent dimensions");
        }
        mMatrix = theMatrix;
    }
    template<typename T>
    Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > matrix) :
        rows(matrix.size()),
        columns(matrix.begin()->size())
    {
        // Create matrix
        std::vector< AlgLib::Vector<T> > m;
        int col = matrix.begin()->size();
        for (auto i = matrix.begin(); i != matrix.end(); i++) {
            AlgLib::Vector<T> row;
            row.reserve( i->size() );
            int counter = 0;
            for (auto j = i->begin(); j != i->end(); j++) {
                row.push_back(*j);
                counter++;
            }
            if(counter != col)
                throw std::invalid_argument("Initializer list did not provide rectangular matrix");
            m.push_back(row);
        }
        mMatrix = m;
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& rhs) :
        mMatrix(rhs.mMatrix),
        rows(rhs.rows),
        columns(rhs.columns)
    {

    }

    template <typename T>
    std::vector< AlgLib::Vector<T> > Matrix<T>::getRowVectors() const
    {
        return mMatrix;
    }

    template <typename T>
    std::vector< AlgLib::Vector<T> > Matrix<T>::getColumnVectors() const
    {
        std::vector< AlgLib::Vector<T> > ret(this->numColumns(), AlgLib::Vector<T>(this->numRows()));
        for (int r = 0; r < this->numRows(); r++)
        {
            for (int c = 0; c < this->numColumns(); c++)
            {
                ret[c][r] = mMatrix[r][c];
            }
        }
        return ret;
    }

    template <typename T>
    void Matrix<T>::setValue(int row, int col, T value)
    {
        if(row >= (int) mMatrix.size() || row < 0 || col < 0 || col >= (int) mMatrix[0].size())
            throw std::out_of_range("Attempted to set value for Matrix out of range");
        mMatrix[row][col] = value;
    }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](int row)
    {
        return mMatrix[row];
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](int row) const
    {
        return mMatrix[row];
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other) const
    {
        if(other.mMatrix.size() != mMatrix.size() || other.mMatrix[0].size() != mMatrix[0].size())
            throw std::invalid_argument("Attempted Matrix addition with mismatched dimensions");
        int row = mMatrix.size();
        int col = mMatrix[0].size();

        std::vector< std::vector<T> > retMatrix(row, std::vector<T>(col));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                retMatrix[i][j] = mMatrix[i][j] + other.mMatrix[i][j];
            }
        }
        return Matrix(retMatrix);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator- (const Matrix<T>& other) const
    {
        if(other.mMatrix.size() != mMatrix.size() || other.mMatrix[0].size() != mMatrix[0].size())
            throw std::invalid_argument("Attempted Matrix addition with mismatched dimensions");
        int row = mMatrix.size();
        int col = mMatrix[0].size();

        std::vector< std::vector<T> > retMatrix(row, std::vector<T>(col));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                retMatrix[i][j] = mMatrix[i][j] - other.mMatrix[i][j];
            }
        }
        return Matrix(retMatrix);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator^(int exp) const
    {
        if(rows != columns)
            throw AlgLib::bad_dimension("Attempted to exponent a non-square matrix");
        // int counter = 0;
        auto ret = identity(rows);
        if(exp >= 0)
        {
            if (exp == 0) {
                return Matrix::identity(rows);
            }
            Matrix tmp = (*this)^(exp / 2);
            tmp = tmp * tmp;
            if (exp % 2 == 1) {
                tmp = tmp * (*this);
            }
            return tmp;
        }
        else
        {
            int mag = -exp;
            auto copyOf(*this);
            // Now we append the identity matrix to the right of copyOf
            auto idCols = ret.getColumnVectors();
            for(auto col : idCols)
            {
                copyOf.addColumn(col);
            }
            copyOf = copyOf.rref();
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    if(copyOf[i][j] != ret[i][j])
                        throw inverse_zero("Attempted to take the inverse of an non-invertible Matrix");
                }
            }
            idCols = copyOf.getColumnVectors();
            idCols.erase(idCols.begin(), idCols.begin() + rows);
            Matrix<T> inverse(idCols);
            inverse = inverse.transpose();
            return (inverse)^(mag);
        }
    }

    template <typename T>
    bool Matrix<T>::operator==(const Matrix<T>& rhs) const
    {
        if(rhs.rows != rows || rhs.columns != columns)
        {
            return false;
        }
        for(int i = 0; i < rhs.rows; i++)
        {
            for(int j = 0; j < rhs.columns; j++)
            {
                if((*this)[i][j] != rhs[i][j])
                    return false;
            }
        }
        return true;
    }

    template <typename T>
    bool Matrix<T>::operator!=(const Matrix<T>& rhs) const
    {
        return !(this->operator==(rhs));
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator* (const Matrix<T>& other) const
    {
        // Jonathan Xia 7/18/16: may implement Strassen's Algorithm later
        if(mMatrix[0].size() != other.mMatrix.size())
            throw std::invalid_argument("Attempted Matrix multiplication with mismatched dimensions");
        std::vector< std::vector<T> > retMatrix(mMatrix.size(), std::vector<T>(other.mMatrix[0].size()));
        for(int r = 0; r < (int) mMatrix.size(); r++)
        {
            for(int c = 0; c < (int) other.mMatrix[0].size(); c++)
            {
                T sum = T(0);
                for(int run = 0; run < (int) mMatrix[0].size(); run++)
                {
                    sum += mMatrix[r][run] * other.mMatrix[run][c];
                }
                retMatrix[r][c] = sum;
            }
        }
        return retMatrix;
    }

    template <typename T>
    AlgLib::Matrix<T> Matrix<T>::operator*(const T& c) const
    {
        Matrix<T> m(*this);
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.columns; j++)
            {
                m[i][j] *= c;
            }
        }
        return m;
    }

    template <typename T>
    AlgLib::Vector<T> Matrix<T>::operator*(const std::vector<T>& other) const
    {
        if((int) other.size() != columns)
            throw bad_dimension("Tried to multiply a Vector with improper dimensions");
        std::vector< std::vector<T> > vec(columns, std::vector<T>(1));
        for(size_t i = 0; i < vec.size(); i++)
        {
            vec[i][0] = other[i];
        }
        Matrix<T> vecMatrix(vec);
        return ((*this) * vecMatrix).getColumnVectors()[0];
    }

    template <typename T>
    int Matrix<T>::numRows() const
    {
        return rows;
    }
    template <typename T>
    int Matrix<T>::numColumns() const
    {
        return columns;
    }

    template <typename T>
    void Matrix<T>::addRow()
    {
        mMatrix.push_back(AlgLib::Vector<T>(this->numColumns()));
        rows++;
    }

    template <typename T>
    void Matrix<T>::addRow(const std::vector<T>& newRow)
    {
        AlgLib::Vector<T> theVec(newRow);
        mMatrix.push_back(theVec);
        rows++;
    }

    template <typename T>
    void Matrix<T>::addColumn()
    {
        for(int i = 0; i < (int)mMatrix.size(); i++)
        {
            mMatrix[i].push_back( T(0) );
        }
        columns++;
    }

    template <typename T>
    T Matrix<T>::getValue(int row, int col) const
    {
        return mMatrix[row][col];
    }

    template <typename T>
    T Matrix<T>::det() const
    {
        // First throw not_square_matrix if not a square matrix
        // Determinants cannot be evaluated for non square matrices
        if(mMatrix.size() != mMatrix[0].size())
            throw not_square_matrix("Attempted to take determinant of non-square matrix");

        // If the matrix is 1x1 then we just return the value in that entry!
        if(mMatrix.size() == 1)
            return mMatrix[0][0];

        // We now have to triangulate this matrix
        T ret(1);
        auto triangle = this->triangulate();
        for(int r = 0; r < rows; r++)
        {
            ret *= triangle[r][r];
        }
        return ret;
    }

    template <typename T>
    Matrix<T> Matrix<T>::getMinor(int i, int j) const
    {
        // Should throw exception if i and j are bad

        std::vector< AlgLib::Vector<T> > copyOfMatrix(mMatrix);
        copyOfMatrix.erase(copyOfMatrix.begin() + i); // erases the i-th row

        // Now to erase the j-th column
        for(int r = 0; r < static_cast<int>(copyOfMatrix.size()); r++)
        {
            copyOfMatrix[r].erase(copyOfMatrix[r].begin() + j);
        }

        return Matrix(copyOfMatrix);
    }

    template <typename T>
    Matrix<T> Matrix<T>::transpose() const
    {
        return Matrix<T>(this->getColumnVectors());
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& out, const Matrix<T>& m)
    {
        for(int i = 0; i < m.numRows(); i++)
        {
            for(int j = 0; j < m.numColumns(); j++)
            {
                out << m.getValue(i, j) << " ";
            }
            out << std::endl;
        }
        return out;
    }

    template <typename T>
    void Matrix<T>::addColumn(const std::vector<T>& newColumn)
    {
        if((int) newColumn.size() != rows)
            throw bad_dimension("The new column does not match the dimensions of the Matrix!");
        for(int i = 0; i < rows; i++)
        {
            mMatrix[i].push_back(newColumn[i]);
        }
        columns++;
    }

    template <typename T>
    Matrix<T> Matrix<T>::identity(int n)
    {
        if(n <= 0)
            throw std::invalid_argument("Attempted to create an identity Matrix with non-positive dimension");
        Matrix<T> tmp(n, n); // Constructs the 0 matrix
        for(int i = 0; i < n; i++)
        {
            tmp[i][i] = T(1);
        }
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::triangulate() const
    {
        auto the_rows = this->getRowVectors();
        T zero = T(0); // Defines zero variable so we don't have to repeatedly construct
        /* Algorithm:
         *
         * Start at the left of the Matrix, with the first row. Find the leftmost column that does contain a non-zero value
         * Use that to change all entries below it to 0
         * Move on to the next row.
         */

        int pivot = 0; // This is meant to store the left most non-zero value in the Matrix on row r

        for(int r = 0; r < static_cast<int>(the_rows.size()); r++)
        {
            /* The value of r will loop through the row indexes */
            for(int c = pivot; c < columns; c++)
            {
                /* Tries to see if there are any nonzero entries from [r][c] to [rows-1][c] */
                bool allZero = true;
                int rest;
                for(rest = r; rest < rows; rest++)
                {
                    if (the_rows[rest][c] != zero)
                    {
                        allZero = false;
                        break;
                    }
                }

                /* If there is a nonzero... */
                if(!allZero)
                {
                    if(r != rest)
                        the_rows[r] += the_rows[rest]; // This will make the_rows[r][c] a nonzero entry

                    /* Time to eliminate everything below the_rows[r][c] */
                    for(int i = r + 1; i < rows; i++)
                    {
                        the_rows[i] -= (the_rows[i][c] / the_rows[r][c]) * the_rows[r];
                    }
                    pivot = c + 1; // Put the pivot position one after the column position
                    break;
                }
            }
        }
        return Matrix<T>(the_rows);
    }

    template <typename T>
    Matrix<T> Matrix<T>::rref() const
    {
        Matrix<T> triangle = this->triangulate();
        auto the_rows = triangle.getRowVectors();

        /* We are going to loop from right to left. In each row, we take the left most non-zero.
         * After that, we will make everything above that entry 0.
         */
        int r = rows - 1;
        int pivot = columns - 1;
        T zero = T(0);
        for(r = rows - 1; r >= 0; r--)
        {
            int leftMostZero; // This is meant to store the left most NON-zero (oops sorry for the confusing var name
            for(leftMostZero = 0; leftMostZero < columns; leftMostZero++)
            {
                if(the_rows[r][leftMostZero] != zero)
                    break;
            }
            // leftMostZero now holds the index of the leftMostZero.
            // We must check if it is columns, because that means that row is completely zeros!
            if(leftMostZero != columns)
            {
                // First, make the coefficient of the non-free variable a 1
                the_rows[r] = the_rows[r] / (the_rows[r][leftMostZero]);
                // Now, we want to make everything above the_rows[r][leftMostZero] a zero
                for(int i = 0; i < r; i++)
                {
                    the_rows[i] -= the_rows[r] * (the_rows[i][leftMostZero]);
                }
                pivot = leftMostZero;
            }
        }
        return Matrix<T>(the_rows);

    }
}
