#ifndef GRID_CHECK_H
#define GRID_CHECK_H

int	ft_check_duplicates(int	sequence[9]);

int	ft_check_col(int grid[9][9], int col);

int	ft_check_row(int grid[9][9], int row);

int ft_check_box(int grid[9][9], int row, int col);

int	ft_is_valid_candidate(int row, int col, int grid[9][9]);

#endif
