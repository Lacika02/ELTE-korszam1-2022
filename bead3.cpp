#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
class Matrix;  

template <typename T>
Matrix<T> elementary_matrix(const int size)
{
	Matrix<T> result(size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result(i, j) = T(i == j);
		}
	}
	
	return result;
}

 template <typename T>
class Matrix
{
private:
	int rows, columns;
	T* values;

public:
	Matrix()
	{
		this->rows = this->columns = 0;
		this->values = nullptr; //  nullptr= null pointer value
	}
	
	Matrix(const int rows, const int columns)
	{
		this->rows = rows;
		this->columns = columns;

		this->values = new T[this->rows * this->columns];
	}

	Matrix(const int size) : Matrix(size, size) {}

	Matrix(const Matrix& matrix) : Matrix(matrix.rows, matrix.columns)
	{
		for (int i = 0; i < this->rows * this->columns; i++)
		{
			this->values[i] = matrix.values[i];
		}
	}

	Matrix& operator= (const Matrix& matrix)
	{
		this->~Matrix();

		this->rows = matrix.rows;
		this->columns = matrix.columns;

		this->values = new T[this->rows * this->columns];

		for (int i = 0; i < this->rows * this->columns; i++)
		{
			this->values[i] = matrix.values[i];
		}

		return *this;
	}

	T& operator() (const int row, const int column) const
	{
		return this->values[row * this->columns + column];
	}

	T minor(const int row, const int column) const
	{
		return this->minor_matrix(row, column).det();
	}


	T algebraic_complement(const int row, const int column) const
	{
		return (((row + column) % 2 == 0) ? 1 : -1) * this->minor(row, column);
	}

	T det() const
	{
		
		
		if (this->rows == 1)
		{
			return this->operator()(0, 0);
		}

		else
		{
			T det = T();

			for (int i = 0; i < this->rows; i++)
			{
				det += this->operator()(i, 0) * algebraic_complement(i, 0);
			}

			return det;
		}
	}

Matrix inverted() const
	{
		T det = this->det();

		
		
		Matrix result(this->rows);

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				result(i, j) = this->algebraic_complement(j, i);
			}
		}

		result /= det;

		return result;
	}

	Matrix operator+ (const Matrix& matrix) const
	{
		Matrix result(this->rows, this->columns);

		for (int i = 0; i < this->rows * this->columns; i++)
		{
			result.values[i] = this->values[i] + matrix.values[i];
		}

		return result;
	}

	Matrix operator- (const Matrix& matrix) const
	{

		Matrix result(this->rows, this->columns);

		for (int i = 0; i < this->rows * this->columns; i++)
		{
			result.values[i] = this->values[i] - matrix.values[i];
		}

		return result;
	}

	Matrix operator* (const Matrix& matrix) const
	{

		Matrix result(this->rows, matrix.columns);

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				result(i, j) = T();

				for (int k = 0; k < this->columns; k++)
				{
					result(i, j) += this->operator()(i, k) * matrix(k, j);
				}
			}
		}

		return result;
	}

	

	Matrix operator^ (const int extent) const
	{
		if (extent == 0)
		{
			return elementary_matrix<T>(this->rows);
		}

		else if (extent > 0)
		{
			Matrix result = *this;

			for (int i = 1; i < extent; i++)
			{
				result *= *this;
			}

			return result;
		}

		else
		{
			return this->inverted() ^ -extent;
		}
	}

	Matrix operator/ (const Matrix& matrix) const
	{
		return *this * matrix.inverted();   // nem érzem úgy, hogy működik, és szerintem túl sok idő ment el ezzel,szóval feladom
	}

};
int main()
{ 
Matrix<int> A(3), B(3, 3);
int value = A(2, 2);
auto result = A + B;
auto result2 = A - B;
auto result3 = A * B;
auto result4 = A / B;
  return 0;
};