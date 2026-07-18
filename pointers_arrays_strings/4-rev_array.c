#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements
 */
void reverse_array(int *a, int n)
{
	int left;
	int right;
	int temp;

	left = 0;
	right = n - 1;

	while (left < right)
	{
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;

		left++;
		right--;
	}
}
