#include "main.h"

int actual_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: natural square root, or -1 if non-natural
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (actual_sqrt(n, 1));
}

/**
 * actual_sqrt - recurses to find the natural square root of a number
 * @n: number to calculate the square root of
 * @i: iterator/guess value
 *
 * Return: natural square root, or -1 if non-natural
 */
int actual_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);

	return (actual_sqrt(n, i + 1));
}

