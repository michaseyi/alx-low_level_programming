#include <stdlib.h>

/**
 * alloc_grid - creates a grid with specified width and height
 * @width: width
 * @height: height
 * Return: grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j, k;

	if (width < 1 || height < 1)
		return (NULL);
	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		*(grid + i) = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(grid[k]);
			}
			free(grid);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}
