#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
using namespace std;

int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b,a%b);
}
void set_coprime(int coprime[], int n)
{
	int i = 1;

	for (; i < n; i++)
	{
		if (gcd(n, i) == 1)
			*(coprime++) = i;
	}
}

int get_a(int coprime[], int a, int n)
{
	int i = 0;

	for (; coprime[i] != 0; i++)
	{
		if ((a*coprime[i]) % n == 1)
			return coprime[i];
	}
	return 0;
}

class affine
{
private:
	char en_code[1024] = {0};
	char de_code[1024] = { 0 };
public:
	void get_en_code(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			this->en_code[i] = str[i];
		}
	}
	void get_de_code(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			this->de_code[i] = str[i];
		}
	}
	void en_cypto(int a, int b)
	{
		for (int i = 0; i < strlen(this->en_code); i++)
		{	
			if (this->en_code[i] >= 'A'&&this->en_code[i] <= 'Z')
			{
				this->de_code[i] = ((this->en_code[i] - 'A')*a + b) % 26 + 'A';
			}
			else if (this->en_code[i] >= 'a'&&this->en_code[i] <= 'z')
			{
				this->de_code[i] = ((this->en_code[i] - 'a')*a + b) % 26 + 'a';
			}else this->de_code[i] = ' ';
		}
		cout << this->de_code << endl;
	}
	void de_cypto(int a, int b, int n) 
		/* 
		这部分解密算法因为有点想不明白，直接照搬某博客的解密函数
		https://blog.csdn.net/qq_35524916/article/details/60960785
		还搬了get_a函数写法和set_coprime
		*/
	{
		char *p_str = this->de_code;
		int coprime[32] = { 0 };
		int _a = 0;
		int i = 0;

		assert(this->de_code);

		for (; i < 32; i++)
		{
			coprime[i] = 0;
		}
		set_coprime(coprime, n);
		_a = get_a(coprime, a, n);
		for (int i = 0; i < strlen(this->de_code); i++)
		{
			if (this->de_code[i] >= 'A'&&this->de_code[i] <= 'Z')
			{
				this->de_code[i] -= 'A';
				this->de_code[i] = (_a*(this->de_code[i] - b + n)) % n;
				this->de_code[i] += 'A';
			}
			else if (this->en_code[i] >= 'a'&&this->en_code[i] <= 'z')
			{
				this->de_code[i] -= 'a';
				this->de_code[i] = (_a*(this->de_code[i] - b + n)) % n;
				this->de_code[i] += 'a';
			}
			else this->de_code[i] = ' ';
		}
		cout << p_str << endl;
	}

};