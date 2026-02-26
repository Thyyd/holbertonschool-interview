#include <stdio.h>
#include "sandpiles.h"

/* ==== Internal helpers (file-local) ==== */

/**
 * print_grid - Print a 3x3 grid as required
 * @grid: 3x3 integer matrix
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check whether a 3x3 sandpile is stable
 * @grid: 3x3 integer matrix
 *
 * Return: 1 if stable (no cell > 3), otherwise 0
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * add_grids - Element-wise addition of two 3x3 grids (grid1 += grid2)
 * @grid1: left matrix, also output
 * @grid2: right matrix
 */
static void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * topple_once - Perform one toppling round on a 3x3 grid
 * @grid: 3x3 integer matrix, modified in place
 */
static void topple_once(int grid[3][3])
{
	int i, j;
	int acc[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;

				if (i - 1 >= 0)
					acc[i - 1][j] += 1;
				if (i + 1 < 3)
					acc[i + 1][j] += 1;
				if (j - 1 >= 0)
					acc[i][j - 1] += 1;
				if (j + 1 < 3)
					acc[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += acc[i][j];
}

/**
 * sandpiles_sum - Compute the sum of two 3x3 sandpiles and stabilize result
 * @grid1: left matrix; will contain the stable result
 * @grid2: right matrix
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);

	/* Repeatedly topple until stable */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple_once(grid1);
	}
}
