#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to string
 */
char *cap_string(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 &&
			str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}

		if ((str[i - 1] == ' ' ||
			 str[i - 1] == '\n' ||
			 str[i - 1] == '\t' ||
			 str[i - 1] == ',' ||
			 str[i - 1] == ';' ||
			 str[i - 1] == '.' ||
			 str[i - 1] == '!' ||
			 str[i - 1] == '?' ||
			 str[i - 1] == '"' ||
			 str[i - 1] == '(' ||
			 str[i - 1] == ')' ||
			 str[i - 1] == '{' ||
			 str[i - 1] == '}') &&
			(str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}

		i++;
	}

	return (str);
}
