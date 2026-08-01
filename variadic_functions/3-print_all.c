#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_char - prints a character
 * @args: list containing the character to print
 *
 * Return: Nothing
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_integer - prints an integer
 * @args: list containing the integer to print
 *
 * Return: Nothing
 */
void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a floating-point number
 * @args: list containing the floating-point number to print
 *
 * Return: Nothing
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: list containing the string to print
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
 * print_all - prints arguments based on a format string
 * @format: string specifying the argument types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	/* your function body */
}
