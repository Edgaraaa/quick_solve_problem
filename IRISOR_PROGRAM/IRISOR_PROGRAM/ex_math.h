#pragma once
#ifdef EXMATH
#define EXMATH

int gcd(int a, int b)
{
	return (b == 0) ? gcd(b, a%b):a;
}

long long gcd(long long a, long long b)
{
	return (b == 0) ? gcd(b, a%b) : a;
}
int ex_gcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int p = ex_gcd(b, a%b, y, x);
	y -= a / b * x;
	return p;

}
long long ex_gcd(long long a, long long b, long long& x, long long &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	long long p = ex_gcd(b, a%b, y, x);
	y -= a / b * x;
	return p;
}
#endif // EXMATH

