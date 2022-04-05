#include <stdlib.h>

/**
 * free_grid - empties memeory allocated by malloc
 * @grid: grid
 * @height: height of grid
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
