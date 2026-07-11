#include "main.h"

/**
 * more_numbers - prints 0 to 14 ten times
 *
 * Return: nothing
 */
void more_numbers(void)
{
	int i;
	int line;

	for (line = 0; line < 10; line++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
			{
				_putchar(i / 10 + '0');
			}

			_putchar(i % 10 + '0');
		}

		_putchar('\n');
	}
}