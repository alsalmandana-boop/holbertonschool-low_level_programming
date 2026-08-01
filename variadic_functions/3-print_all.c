#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @args: list containing the character
 *
 * Return: Nothing
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_integer - prints an integer
 * @args: list containing the integer
 *
 * Return: Nothing
 */
void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a floating-point number
 * @args: list containing the floating-point number
 *
 * Return: Nothing
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: list containing the string
 *
 * Return: Nothing
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints arguments according to a format string
 * @format: list of argument types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	unsigned int i;
	unsigned int j;
	char *separator;
	va_list args;
	printer_t printers[] = {
		{"c", print_char},
		{"i", print_integer},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	i = 0;
	separator = "";
	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (printers[j].symbol != NULL)
		{
			if (format[i] == printers[j].symbol[0])
			{
				printf("%s", separator);
				printers[j].print(args);
				separator = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
