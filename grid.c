#include <unistd.h>
#include "grid.h"

/*
This function prints the 5x5 grid to the console
*/
void	ft_print_grid(int grid[9][9])
{
	int		row;
	int		col;
	char	current_num;

	row = 0;
	col = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			current_num = grid[row][col] + 48;
			write(1, &current_num, 1);
			if ((col + 1) % 3 == 0)
				write(1, "   ", 1);
			if  (((row + 1) % 3 == 0) && (col == 8))
				write(1, "\n", 1);
			if (col < 8)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
    write(1, "\n", 1);
}
