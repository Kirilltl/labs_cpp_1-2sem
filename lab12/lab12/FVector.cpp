#ifndef LAB_12_CPP
#define LAB_12_CPP
#include "fVector.h"
#include <stdio.h>
fVector::fVector(int s) {
	if (s > 100) {
		printf("ERROR! TOO BIG SIZE!\n");
		return;
	}
	size = s;
	vector = new float[size];
}

fVector::fVector(void) {
	size = 1;
	vector = new float[size];
}

void fVector::output(void) const {
	int i = 0;
	printf("Components of the vector:\n");
	for (i = 0; i < size; ++i) {
		printf("%f ", vector[i]);
	}
	printf("\n");
}

void fVector::input(void) {
	int i = 0;
	printf("Enter the components of vector (%d):\n", size);
	for (i = 0; i < size; ++i) {
		scanf("%f", &vector[i]);
	}
}

fVector :: ~fVector(void) {
	if (vector) {
		delete[] vector;
	}
}

fVector::fVector(const fVector& v) {
	size = v.size;
	vector = new float[size];
	int i = 0;
	for (i = 0; i < size; ++i) {
		vector[i] = v.vector[i];
	}
}

fVector& fVector :: operator = (fVector& v) {
	if (&v == this) {
		return *this;
	}
	if (size < v.size) {
		size = v.size;
	}
	delete[] vector;
	vector = new float[size];
	int i = 0;
	for (i = 0; i < size; ++i) {
		if (i < v.size) {
			vector[i] = v.vector[i];
		}
		else {
			vector[i] = 0;
		}
	}
	return *this;
}

fVector& fVector :: operator + (fVector& v) {
	int i = 0;
	this->size > v.size ? v.size = this->size : this->size = v.size;
	for (i = 0; i < v.size; ++i) {
		vector[i] += v.vector[i];
	}
	return *this;
}

fVector& fVector :: operator - (fVector& v) {
	int i = 0;
	this->size > v.size ? v.size = this->size : this->size = v.size;
	for (i = 0; i < v.size; ++i) {
		vector[i] -= v.vector[i];
	}
	return *this;
}

fVector& fVector :: operator * (float number) {
	int i = 0;
	for (i = 0; i < this->size; ++i) {
		vector[i] *= number;
	}
	return *this;
}

fVector& fVector :: operator / (float number) {
	int i = 0;
	for (i = 0; i < this->size; ++i) {
		vector[i] /= number;
	}
	return *this;
}

float fVector :: operator ^ (fVector& v) {
	float res = 0;
	int i = 0;
	this->size < v.size ? v.size = this->size : this->size = v.size;
	for (i = 0; i < v.size; ++i) {
		res += vector[i] * v.vector[i];
	}
	return res;
}

float fVector::get(int index, int& error) {
	if ((index < 0) || (index >= size)) {
		error = 1;
		return -1;
	}
	else {
		return vector[index];
	}
}

void fVector::set(int index, float value, int& error) {
	if ((index < 0) || (index >= size)) {
		error = 1;
		return;
	}
	else {
		vector[index] = value;
	}
}
#endif