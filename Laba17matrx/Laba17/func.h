#ifndef FUNC_H
#define FUNC_H
#include<iostream>
template <typename T>
class Matrix
{
private:
	size_t row;
	size_t column;
	T** elem;
public:

	Matrix(size_t roww, size_t columnn)
	{
		row = roww;
		column = columnn;
		elem = new T * [row];
		for (int i = 0; i < row; i++)
			elem[i] = new T[column];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
				elem[i][j] = 0;
		}
	}
	Matrix(const Matrix& b)
	{
		row = b.row;//COPY VALUES
		column = b.column;
		elem = new T* [row];
		for (int i = 0; i < row; i++)
			elem[i] = new T[column];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
				elem[i][j] = b.elem[i][j];
		}
	}
	Matrix<T>& operator = (const Matrix& b)
	{
		if (this != &b)
		{
			row = b.row;
			column = b.column;
			for (int i = 0; i < row; i++)
				delete[] elem[i];
			elem = new T * [row];
			for (int i = 0; i < row; i++)
				elem[i] = new T[column];
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++)
					elem[i][j] = b.elem[i][j];
			}
		}
		return (*this);//Возвращаем текущ. объект, чтобы мб связать в цепь выполнение неск.опер. присваив d1 = d2 = d3
		// Проверка на самоприсваивание 
	}
	~Matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] elem[i];
	}
	void set()
	{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
			{
				std::cin >> elem[i][j];
				if (elem[i][j] < 0)
				{
					throw std::runtime_error("Negative number!");
				}
			}
		}
	}
	
	T get(int i, int j)
	{
		if (i > 100)
			throw std::runtime_error("Max i is 100!");
		return elem[i][j];
	}
	int rows()
	{
		return row;
	}
	int columns()
	{
		return column;
	}
	Matrix<T> sum(const Matrix& b)
	{
		if ((column != b.column) && (row != b.row))//esli rasnue matr
			throw std::runtime_error("Matrices are of different sizes");
		Matrix <T> res(row, column);//initialisation 
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
				res.elem[i][j] = elem[i][j] + b.elem[i][j];
		}
		*this = res;
		return *this;
	}
	void print()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
				std::cout << elem[i][j] << " ";
			std::cout << std::endl;
		}
	}
};
#endif
