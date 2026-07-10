#include <stdio.h>
Print alphabet except e and q
/**
 * main - Prints the alphabet in lowercase except q and e
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	c = 'a';

	while (c <= 'z')
	{
		if (c != 'e' && c != 'q')
		{
			putchar(c);
		}

		c++;
	}

	putchar('\n');

	return (0);
}
