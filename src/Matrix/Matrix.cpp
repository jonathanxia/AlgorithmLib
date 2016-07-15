#include <vector>
#include <string>
#include <iostream>

template <typename T>
AlgLib::Matrix<T>::Matrix(int r, int c) { // Creates 0 matrix
	std::vector<T> rows;
	rows.reserve(row);
	for (int i = 0; i < row; i++) {
		std::vector<T> row;
		row.reserve(column);
		for (int j = 0; j < column; j++) {
			row.add(0);
		}
		rows.add(row);
	}
	mMatrix = rows;
}

template<typename T>
AlgLib::Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > matrix) {
	// Find r and c
	int r = 0, c = 0;
	for (auto i = matrix.begin(); i != matrix.end(); i++) {
		r = i->size() > r ? i->size() : r;
		c++;
	}
	// Create matrix
	std::vector<std::vector<T>> m;
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

template<typename T>
void AlgLib::Matrix<T>::toString() { // Temporary sol until i figure out how to return output streams
	for (auto i = mMatrix.begin(); i != mMatrix.end(); i++) {
		cout << "[ ";
		for (auto j = i->begin(); j != i->end(); j++) {
			cout << " " << (*j) << " ";
		}
		cout << " ]\n";
	}
}