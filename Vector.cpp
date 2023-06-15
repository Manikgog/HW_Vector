#include "Vector.h"


Vector::Vector() : _size(0), _massive(nullptr) {}

Vector::Vector(const Vector& v)
{
	this->_size = v._size;
	this->_massive = new long long int[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_massive[i] = v._massive[i];
	}
}

size_t Vector::Size()
{
	return this->_size;
}

bool Vector::Empty()
{
	return this->_size == 0 ? true : false;
}

void Vector::Clear()
{
	if (this->_massive)
		delete[] this->_massive;
	this->_massive = nullptr;
	this->_size = 0;
}

Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (_massive)
		delete[] _massive;
	this->_size = v._size;
	this->_massive = new long long int[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_massive[i] = v._massive[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& v)
{
	Vector newVec;
	newVec._size = this->_size + v._size;
	newVec._massive = new long long int[newVec._size];

	size_t i;
	for (i = 0; i < this->_size; ++i)
	{
		newVec._massive[i] = this->_massive[i];
	}
	for (size_t j = 0; j < v._size; ++j, ++i)
	{
		newVec._massive[i] = v._massive[j];
	}
	return newVec;
}

bool Vector::operator==(const Vector& v)
{
	if (this->_size != v._size)
		return false;
	for (size_t i = 0; i < this->_size; ++i)
	{
		static long long int left_vec = _massive[i];
		static long long int right_vec = v._massive[i];
		if (left_vec != right_vec)
			return false;
	}
	return true;
}

void Vector::Push_Front(long long int value)
{
	_size++;
	long long int* newArray = new long long int[_size];
	if (_massive == nullptr)
	{
		newArray[0] = value;
		_massive = newArray;
		return;
	}
	newArray[0] = value;
	for (size_t i = 1; i < _size; ++i)
	{
		newArray[i] = _massive[i-1];
	}
	delete[] _massive;
	_massive = newArray;
	return;
}

void Vector::Push_Back(long long int element)
{
	_size++;
	long long int* newArray = new long long int[_size];
	if (_massive == nullptr)
	{
		newArray[0] = element;
		_massive = newArray;
		return;
	}

	for (size_t i = 0; i < _size - 1; ++i)
	{
		newArray[i] = _massive[i];
	}
	newArray[_size - 1] = element;
	delete[] _massive;
	_massive = newArray;
	return;
}


void Vector::Pop_Back() {
	if (_massive == nullptr)
	{
		return;
	}
	_size--;
	long long int* newArray = new long long int[_size];
	for (size_t i = 0; i < _size; ++i)
	{
		newArray[i] = _massive[i];
	}
	delete[] _massive;
	_massive = newArray;
	return;
}

void Vector::Pop_Front()
{
	if (_massive == nullptr)
	{
		return;
	}
	long long int* newArray = new long long int[_size-1];
	for (size_t i = 0; i < _size; ++i)
	{
		newArray[i] = _massive[i+1];
	}
	_size--;
	delete[] _massive;
	_massive = newArray;
	return;
}


void Vector::Insert(size_t pos, long long int value) 
{
	if (pos < 0 || pos >= this->_size)
	{
		if (pos == this->_size)
		{
			this->Push_Back(value);
			return;
		}
		std::cout << "Error index!";
		exit(1);
	}
	this->_size++;
	long long int* newArray = new long long int[_size];
	for (size_t i = 0; i < pos; ++i)
	{
		newArray[i] = this->_massive[i];
	}
	newArray[pos] = value;
	for (size_t i = pos+1; i < this->_size; i++)
	{
		newArray[i] = this->_massive[i - 1];
	}
	delete[] _massive;
	_massive = newArray;
	return;
}


void Vector::ShowElements()
{
	for (size_t i = 0; i < _size; ++i)
	{
		std::cout << i << " element: " << _massive[i] << '\n';
	}
}


long long int* Vector::Begin()
{
	return _massive;
}


long long int* Vector::End()
{
	return _massive + _size;
}





long long int& Vector::operator[](int index)
{
	if (index < 0 || index >= _size)
	{
		std::cout << "Error index!";
		exit(1);
	}
	return _massive[index];
}


Vector::~Vector()
{
	if (_massive)
		delete[] _massive;
}


std::ostream& operator<<(std::ostream& output, const Vector& v) {
	bool is_first = true;
	for (size_t i = 0; i < v._size; ++i)
	{
		if (!is_first)
			output << ", ";
		is_first = false;
		output << v._massive[i];
	}
	return output;
}