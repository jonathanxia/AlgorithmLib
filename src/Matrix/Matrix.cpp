#include <vector>
#include <string>
#include <stdexcept>
namespace AlgLib
{
    template <typename T>
    Matrix<T>::Matrix(int row, int column) { // Creates 0 matrix
        std::vector< std::vector<T> > rows;
        rows.reserve(row);
        for (int i = 0; i < row; i++) {
            std::vector<T> currentRow; // The current row being built up
            currentRow.reserve(column);
            for (int j = 0; j < column; j++) {
                currentRow.push_back(0);
            }
            rows.push_back(currentRow);
        }
        mMatrix = rows;
    }

    template <typename T>
    Matrix<T>::Matrix(const std::vector< std::vector<T> >& theMatrix)
    {
        for(int i = 0; i < (int) theMatrix.size() - 1; i++)
        {
            if(theMatrix[i].size() != theMatrix[i+1].size())
                throw std::invalid_argument("Matrix has inconsistent dimensions");
        }
        mMatrix = theMatrix;
    }

    template<typename T>
    Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > matrix) {
        // Find r and c
        int r = 0, c = 0;
        for (auto i = matrix.begin(); i != matrix.end(); i++) {
            r = i->size() > r ? i->size() : r;
            c++;
        }
        // Create matrix
        std::vector< std::vector<T> > m;
        for (auto i = matrix.begin(); i != matrix.end(); i++) {
            std::vector<T> row;
            row.reserve(c);
            int counter = 0;
            for (auto j = i->begin(); j != i->end(); j++) {
                row.push_back(*j);
                counter++;
            }
            while (counter < c) {
                row.push_back(T(0)); // derp idk if this is allowed..
            }
            m.push_back(row);
        }
        mMatrix = m;
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& rhs) :
        mMatrix(rhs.mMatrix)
    {

    }
    //Let's avoid the code below for now --Jonathan Xia 07/18/2016
    /*
    template<typename T>
    void Matrix<T>::toString() { // Temporary sol until i figure out how to return output streams
        for (auto i = mMatrix.begin(); i != mMatrix.end(); i++) {
            cout << "[ ";
            for (auto j = i->begin(); j != i->end(); j++) {
                cout << " " << (*j) << " ";
            }
            cout << " ]\n";
        }
    }
    */

    template <typename T>
    std::vector< std::vector<T> > Matrix<T>::getVectors() const
    {
        return mMatrix;
    }

    template <typename T>
    void Matrix<T>::setValue(int row, int col, T value)
    {
        if(row >= mMatrix.size() || row < 0 || col < 0 || col >= mMatrix[0].size())
            throw std::out_of_range("Attempted to set value for Matrix out of range");
        mMatrix[row][col] = value;
    }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](int row)
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
                for(int run = 0; run < mMatrix[0].size(); run++)
                {
                    sum += mMatrix[r][run] * other.mMatrix[run][c];
                }
                retMatrix[r][c] = sum;
            }
        }
        return retMatrix;
    }

}
