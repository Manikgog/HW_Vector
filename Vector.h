﻿#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <string>


class Vector
{
private:
	size_t _size;
	long long int* _massive;

public:

	Vector();

	Vector(const Vector& v);

	~Vector();

	size_t Size();

	bool Empty();

	void Clear();

	Vector& operator=(const Vector& v);

	Vector operator+(const Vector& v);

	bool operator==(const Vector& v);

	void Push_Front(long long int value);

	void Push_Back(long long int element);

	void Pop_Back();

	void Pop_Front();

	void Insert(size_t pos, long long int value);

	void ShowElements();

	long long int* Begin();

	long long int* End();

	friend std::ostream& operator<<(std::ostream& output, const Vector& v);

	friend std::istream& operator>>(std::istream& in, Vector& v);

	long long int& operator[](int index);

};

#endif // !_VECTOR_H_
