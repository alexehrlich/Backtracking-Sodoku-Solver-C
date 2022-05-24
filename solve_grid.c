#include "solve_grid.h"
#include "grid_check.h"
#include "grid.h"
#include "typedef.h"
#include <stdio.h>

int	ft_solve_grid(int row, int col, int grid[9][9])
{
	//This is a preset value not at the last colum, we dont want to chang it,
	//we just call ft_solve at the next field on the right.
	if (col < 8 && grid[row][col] > 0)
    {
        //printf("Save value, skip this one.\n");
        return (ft_solve_grid(row, (col + 1), grid));
    }

	//This is a preset value at the last colum, we dont want to chang it,
	//we just call ft_solve at col 1 in the nex row. we jump to this field
	else if (grid[row][col] > 0)
	{
        //printf("Save value, skip this one.\n");
		if (row == 8 && col == 8)
			return (VALID);
		return (ft_solve_grid((row + 1), 0, grid));
	}
	//If it is 0, it is a value we want to change.
	else
	{
		//so we call this function (has to be in another beacuse of rom limit...)
		return (ft_change_value(row, col, grid));
	}
}

int	ft_change_value(int row, int col, int grid[9][9])
{
	int	i;

	//We test every value from 1 to 9 for the given field
	i = 1;
	while (i < 10)
	{
		//We set i at the grid and pass row, col and the grid with the new value to the
		//ft_is_valid_cand.. function, which checks if the set value is valid
		grid[row][col] = i;
		//printf("Changed value in row: %d at col: %d: \n", row, col);
		//ft_print_grid(grid);
		if (ft_is_valid_candidate(row, col, grid) == VALID)
		{
			//If it is valid and we are at the end we return one and start to
			//climb back from our recursion to the main fanction
			if (row == 8 && col == 8)
				return (VALID);
			//If it is not the last, we want to continue with the next field
			else if (col < 8)
			{
				if (ft_solve_grid(row, (col + 1), grid) == VALID)
					return (VALID);
			}
			else
			{
				//If it was the last column we jump to the next row
				if (ft_solve_grid((row + 1), 0, grid) == VALID)
                    return (VALID);
			}
			//If it wasnt a valid value we increment i and test that one, whether it is valid.
		}
        i++;
	}
	//If we testet from 1 to 4 and no value was valid we return -1 from this function call
	//to the previous function call (one recursion area above) then there the i is incremented
	//and it is tried again...
    //printf("No solution found --> Jump back.\n");
	grid[row][col] = 0;
	return (INVALID);
}
