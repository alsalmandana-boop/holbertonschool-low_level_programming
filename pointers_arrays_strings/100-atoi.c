#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no number is found
 */
int _atoi(char *s)
{
	int index;
	int sign;
	unsigned int number;
	int found;

	index = 0;
	sign = 1;
	number = 0;
	found = 0;

	while (s[index] != '\0')
	{
		if (s[index] == '-')
		{
			sign = -sign;
		}

		if (s[index] >= '0' && s[index] <= '9')
		{
			found = 1;
			number = number * 10 + (s[index] - '0');
		}
		else if (found)
		{
			break;
		}

		index++;
	}

	return (number * sign);
}