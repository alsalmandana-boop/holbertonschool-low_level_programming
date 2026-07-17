#include "main.h"
/**
* print_rev - prints a string in reverse
* @s: pointer to the string
*/

void print_rev(char *s)
{
	int count;

	count = _strlen(s) - 1;

	while (count >= 0)
	{
		_putchar(s[count]);
		count--;
	}
	 _putchar('\n');
}
