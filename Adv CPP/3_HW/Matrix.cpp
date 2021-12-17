#pragma once

#include <cmath>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix {
	typedef double m_type;
public:
	Matrix(int size) : size(size) {
		srand(time(0));
		for (int i{ 0 }; i < size; ++i) {
			matrix.push_back(vector<m_type>());
			for (int j{ 0 }; j < size; ++j) {
				matrix[i].push_back((double)(rand() % BASE + 1));
			}
		}
	}

	void print() {
		for (vector<m_type> row : matrix) {
			for (m_type item : row) {
				cout.width(PRINT_WIDTH);
				cout << fixed << setprecision(PRINT_PRESITION) << item;
			}
			cout << endl;
		}
	}

	void transform() {
		for (int baseRow{ 0 }; baseRow < size - 1; ++baseRow) {
			for (int rowIndex{ baseRow + 1 }; rowIndex < size; ++rowIndex) {
				double k = matrix[rowIndex][baseRow] / matrix[baseRow][baseRow];

				for (int column{ baseRow }; column < size; ++column) {
					matrix[rowIndex][column] -= matrix[baseRow][column] * k;
				}
			}
		}
	}

	double getDeterminant() {
		transform();
		double result = matrix[0][0];
		for (int i{ 1 }; i < size; ++i) result *= matrix[i][i];
		return result;
	}
private:
	int size;
	vector<vector<m_type>> matrix;
	static constexpr int BASE = 10;
	static constexpr int PRINT_WIDTH = 6;
	static constexpr int PRINT_PRESITION = 1;
};