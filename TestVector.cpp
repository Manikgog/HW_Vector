#include "TestVector.h"
#include "Vector.h"
#include <cassert>



void TestPush_Back()
{
	Vector v;
	assert(v.Size() == 0);
	v.Push_Back(5);
	assert(v.Size() == 1);
	long long int temp = v[0];
	assert(temp == 5);
	return;
}

void TestPush_Front()
{
	Vector v;
	assert(v.Size() == 0);
	v.Push_Back(5);
	v.Push_Front(1);
	assert(v.Size() == 2);
	long long int temp = v[0];
	assert(temp == 1);

	return;
}

void TestPop_Front()
{
	Vector v;
	v.Push_Back(1);
	v.Push_Back(3);
	v.Push_Back(2);
	long long int tmp = v[0];
	assert(tmp == 1);
	v.Pop_Front();
	tmp = v[0];
	assert(tmp == 3);
}

void TestPop_Back()
{
	Vector v;
	v.Push_Back(1);
	v.Push_Back(3);
	v.Push_Back(2);
	long long int tmp = v[2];
	assert(tmp == 2);
	v.Pop_Back();
	tmp = v[1];
	assert(tmp == 3);
}

void TestSize()
{
	Vector v;
	v.Push_Back(1);
	v.Push_Back(2);
	v.Push_Back(3);
	v.Push_Back(4);
	v.Push_Back(5);
	assert(v.Size() == 5);
	v.Pop_Back();
	assert(v.Size() == 4);
}

void TestEmpty()
{
	Vector v;
	assert(v.Empty() == true);
	v.Push_Back(1);
	assert(v.Empty() == false);
}

void TestClear()
{
	Vector v;
	v.Push_Back(100);
	v.Push_Back(120);
	assert(v.Empty() == false);
	v.Clear();
	assert(v.Empty() == true);
}

void TestBegin()
{
	Vector v;
	v.Push_Back(21);
	v.Push_Back(23);
	v.Push_Back(45);
	assert(*(v.Begin()) == 21);
	v.Pop_Front();
	assert(*(v.Begin()) == 23);
}

void TestEnd()
{
	Vector v;
	v.Push_Back(21);
	v.Push_Back(23);
	v.Push_Back(45);
	assert(v.End() == v.Begin() + v.Size());
	v.Pop_Back();
	assert(v.End() == v.Begin() + v.Size());
}

void TestOperatorEqual()
{
	Vector v1;
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	v1.Push_Back(5);
	v1.Push_Back(6);
	Vector v2;
	v2.Push_Back(1);
	v2.Push_Back(2);
	v2.Push_Back(3);
	v2.Push_Back(4);
	v2.Push_Back(5);
	v2.Push_Back(6);
	assert(v1 == v2);
}

void TestOperatorSumming()
{
	Vector v1;
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	v1.Push_Back(5);
	Vector v2;
	v2.Push_Back(6);
	v2.Push_Back(7);
	v2.Push_Back(8);
	v2.Push_Back(9);
	v2.Push_Back(10);
	v2.Push_Back(11);
	Vector v3 = v1 + v2;
	assert(*(v3.Begin()) == 1);
	assert(*(v3.Begin()) == *(v1.Begin()));
	long long int v1_tmp = v1[4];			// fouth element of v1
	long long int v3_tmp = v3[4];			// fouth element of v3
	assert(v1_tmp == v3_tmp);
	long long int v2_tmp = v2[0];
	v3_tmp = v3[5];
	assert(v2_tmp == v3_tmp);
	v2_tmp = v2[5];
	v3_tmp = v3[10];
	assert(v2_tmp == v3_tmp);
}

void TestOperatorAssign() 
{
	Vector v1;
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	v1.Push_Back(5);
	long long int tmp = v1[0];
	assert(1 == tmp);
	tmp = v1[1];
	assert(2 == tmp);
	tmp = v1[2];
	assert(3 == tmp);
	tmp = v1[3];
	assert(4 == tmp);
	tmp = v1[4];
	assert(5 == tmp);
}

