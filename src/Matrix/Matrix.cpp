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
}
