#ifndef FUNC_H
#define FUNC_H
template <typename T>
class Matrix
{
private:
	size_t row;
	size_t column;
	T** matrix;
public:
	Matrix(size_t roww, size_t columnn);//constructor
	Matrix(const Matrix& b);//constructor copy
	Matrix& operator=(const Matrix& b);
	~Matrix();
	void set(size_t row, size_t column);
	T get(size_t row, size_t column);
	Matrix sum(const Matrix& b);
	void print();
};
#endif
