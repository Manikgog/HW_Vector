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
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста

	TestVector();
	
	return 0;
}
