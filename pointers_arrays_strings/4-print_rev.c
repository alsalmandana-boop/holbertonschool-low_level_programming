#include "main.h"
/**
* print_rev - prints a string in reverse
* @s: pointer to the string
*/

void print_rev(char *s)
{
	int count;
	int length;
	length = 0;

	while (s[length] != '\0')
	{
    length++;
	}
	count = length - 1;

	while (count >= 0)
	{
		_putchar(s[count]);
		count--;
	}
	 _putchar('\n');
}
