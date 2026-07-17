#include "main.h"
/**
* _puts - prints a string to stdout
* @str: pointer to the string
* Return: void
*/

void _puts(char *str)
{
	int count;

	count = 0;

while (str[count] != '\0')
{
	_putchar(str[count]);
	count++;
}
	 _putchar('\n');
}

