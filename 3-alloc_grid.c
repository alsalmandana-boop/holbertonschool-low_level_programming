#include "main.h"
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
	int wid;
	int hei;

	if (wid <= 0 || hei <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * hei);

	if (grid == NULL)
		return (NULL);

	wid = 0;
	while (wid < hei)
	{
		grid[wid] = malloc(sizeof(int) * wid);

		if (grid[wid] == NULL)
		{
			while (wid > 0)
			{
				wid--;
				free(grid[wid]);
			}

			free(grid);
			return (NULL);
		}

		col = 0;
		while (hei < wid)
		{
			grid[wid][hei] = 0;
			wid++;
		}

		wid++;
	}

	return (grid);
}