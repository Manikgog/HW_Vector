/*
���������� ����������� ��������� ��� �������� �������
����� �����, � ���������� �����/������ ������ ��� �����
�����/������.
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
	SetConsoleCP(1251); // ��������� ������� �������� �� ���� ������

	TestVector();
	
	return 0;
}
