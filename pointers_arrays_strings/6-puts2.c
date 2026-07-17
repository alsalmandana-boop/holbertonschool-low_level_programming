#include "main.h"
/**
 * puts2 - prints every other character of a string, starting with the first character
 * @str: string to be printed
 */

void puts2(char *str)
{
    int count;
    int length;
    count = 0;
    
    length = 0;
	while (str[length] != '\0')
	{
	length++;
	}

     while (count < length)
    {
    _putchar(str[count]);
    count += 2;    
    }
    _putchar('\n');
}
