#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "solve_grid.h"
#include "grid_check.h"
#include "typedef.h"

int	main(int argc, char **argv)
{
	//2-Dimensional 9x9 grid
	int	used_sodoku[9][9] = {
    {0, 2, 6, 0, 0, 0, 8, 1, 0},
    {3, 0, 0, 7, 0, 8, 0, 0, 6},
    {4, 0, 0, 0, 5, 0, 0, 0, 7},
    {0, 5, 0, 1, 0, 7, 0, 9, 0},
    {0, 0, 3, 9, 0, 5, 1, 0, 0},
    {0, 4, 0, 3, 0, 2, 0, 5, 0},
    {1, 0, 0, 0, 3, 0, 0, 0, 2},
    {5, 0, 0, 2, 0, 4, 0, 0, 9},
    {0, 3, 8, 0, 0, 0, 4, 6, 0},
	};

    int hardest_sodoku[9][9] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 9, 0, 2, 0, 0},
    {0, 5, 0, 0, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 4, 5, 7, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 3, 0},
    {0, 0, 1, 0, 0, 0, 0, 6, 8},
    {0, 0, 8, 5, 0, 0, 0, 1, 0},
    {0, 9, 0, 0, 0, 0, 4, 0, 0},
    };

	printf("Empty grid: \n");
	ft_print_grid(hardest_sodoku);	
	if (ft_solve_grid(0, 0, hardest_sodoku) == VALID) //solve grid and start at (0/0)
    {
        printf("\nSolved Grid: \n");
		ft_print_grid(hardest_sodoku);	//solve_grid return INVALID if it didnt found a solution, VALID when success
    }
	else
		write(1, "Error\n", 6);
	return (0);
}
