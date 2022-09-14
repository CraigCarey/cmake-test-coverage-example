#include "lib_under_test.hpp"

int totally_covered(int a, int b, int c)
{
	if ((a > b) && (a > c))
	{
		return a;
	}
	else if (b > c)
	{
		return b;
	}
	else
	{
		return c;
	}

	// Unreachable
	return 0;
}

int partially_covered(int a, int b, int c)
{
	if ((a > b) && (a > c))
	{
		return a;
	}
	else if (b > c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

int no_coverage()
{
	int x = 0;
	int div_by_zero = 13 / x;

	return div_by_zero;
}
