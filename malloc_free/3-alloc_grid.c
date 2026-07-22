include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - creates a two dimensional array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the grid, or NULL on failure
 */
int **alloc_grid(int width, int heights)
{
	int **grid;
	int width;
	int heights;

	if (width <= 0 || heights <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * heights);

	if (grid == NULL)
		return (NULL);

	width = 0;
	while (width < heights)
	{
		grid[width] = malloc(sizeof(int) * width);

		if (grid[width] == NULL)
		{
			while (width > 0)
			{
				width--;
				free(grid[width]);
			}

			free(grid);
			return (NULL);
		}

		heights = 0;
		while (heights < width)
		{
			grid[width][heights] = 0;
			width++;
		}

		width++;
	}

	return (grid);
}
