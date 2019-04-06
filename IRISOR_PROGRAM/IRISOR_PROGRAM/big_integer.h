#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
class BIG_INTEGER
{
public:
	friend ostream& operator <<(ostream& out,const BIG_INTEGER& p);
	char value[2048] = { 0 };
	BIG_INTEGER& operator =(const BIG_INTEGER& A)
	{
		for (int i = 0; i < strlen(A.value); i++)
		{
			this->value[i] = A.value[i];
		}
		return *this;
	}
	BIG_INTEGER& operator =(const char* A)
	{
		for (int i = 0; i < strlen(A); i++)
		{
			this->value[i] = A[i];
		}
		return *this;
	}
	BIG_INTEGER operator +(BIG_INTEGER& A, BIG_INTEGER& B)
	{
		
	}
};
ostream& operator <<(ostream &out,const BIG_INTEGER& p)
{
	out << p.value <<endl;
	return out;
}