#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/*ƒоп. к 12 - перегрузить "+" как конкатенацию векторов, а  "-" - как удаление вхождений одного вектора в другой*/
class fVector {
	float* vector;
	int size;
public:
	fVector(int size);
	fVector(void);
	void output(void) const;
	void input(void);
	float get(int index, int& error);
	void set(int index, float value, int& error);
	~fVector(void);
	fVector(const fVector& v);
	fVector& operator = (fVector& v);
	fVector& operator + (fVector& v);
	fVector& operator - (fVector& v);
	fVector& operator * (float number);
	fVector& operator / (float number);
	float operator ^ (fVector& v);
};
#endif
