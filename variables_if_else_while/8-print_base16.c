#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char c;

	n = 0;

	while (n < 10)
	{
		putchar(n + '0');
		n++;
	}

	c = 'a';

	while (c <= 'f')
	{
		putchar(c);
		c++;
	}

	putchar('\n');

	return (0);
}
