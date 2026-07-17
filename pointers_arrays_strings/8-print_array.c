#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array
 * @a: array of integers
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
	int count;

	count = 0;

	while (count < n)
	{
		printf("%d", a[count]);

		if (count != n - 1)
		{
			printf(", ");
		}

		count++;
	}

	printf("\n");
}
