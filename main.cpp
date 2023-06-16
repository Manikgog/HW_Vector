/*
Необходимо реализовать контейнер для хранения больших
целых чисел, с поддержкой ввода/вывода данных аля поток
ввода/вывода.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include "TestVector.h"

void TestVector()
{
	TestPush_Back();
	TestPush_Front();
	TestPop_Front();
	TestPop_Back();
	TestSize();
	TestEmpty();
	TestClear();
	TestBegin();
	TestEnd();
	TestOperatorEqual();
	TestOperatorSumming();
	TestOperatorAssign();
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	TestVector();
	// testing of overloading << operator
	Vector v;
	v.Push_Back(1);
	v.Push_Back(2);
	v.Push_Back(3);
	v.Push_Back(4);
	v.Push_Back(5);
	v.Push_Back(6);
	v.Push_Back(7);
	v.Push_Back(8);
	std::cout << v;
	// testing of overloading >> operator
	Vector v1;
	std::cin >> v1;
	std::cout << v1;

	return 0;
}
