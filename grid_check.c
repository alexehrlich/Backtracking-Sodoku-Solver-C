#include <stdio.h>
#include "grid_check.h"
#include "typedef.h"

/*
This function checks for duplicates in a sequence of 4  numbers excluding zeros.
The functions get a sequence of 6, where the first and die last number define the rules of that sequence, , e.g:  1  \4 3 2 1\  4
It returns 1 if no duplicate detected, otherwise it returns 0.
*/
int	ft_check_duplicates(int	sequence[9])
{
	int	a;
	int	b;

	a = 0;
	b = 0;

    //starts at idx = 1 and ends at idx = 4 to exclude the "rule-numbers" of the check
	while (a < 9)
	{
        b = 0;
		while (b < 9)
		{
            //Don't compare to yourself :-)
			if (a == b)
			{
				b++;
				continue;
			}
            //Don't consider zeros for duplicate check, since they are placeholders
			if ((sequence[a] == sequence[b]) && (sequence[a] != 0))
            {
                //printf("Duplicate.\n");
                return (INVALID);
            }
			b++;
		}
		a++;
	}
	return (1);
}

int	ft_is_valid_candidate(int row, int col, int grid[9][9])
{
	if (ft_check_col(grid, col) == 0)
    {
        //printf("Inavlid Candidate in col\n");
        return (INVALID);
    }

	if (ft_check_row(grid, row) == 0)
    {
        //printf("Invalid Candidate in row.\n");
        return (INVALID);
    }

	if (ft_check_box(grid, row, col) == 0)
	{
		//printf("Invalid Candidate in box.\n");
		return (INVALID);
	}
		

	//printf("Valid Candidate.\n");
	return (VALID);
}

/*
This function gets the crrent grid and the number of the col.
It builds a sequence with the numbers in the col and checks, 
whether it's valid with ft_check_sequence, forewards and backwards
*/
int	ft_check_col(int grid[9][9], int col)
{
	int	sequence[9];
	int	i;
	
	i = 0;
	while (i < 9)
	{
		sequence[i] = grid[i][col];
		i++;
	}
	//printf("COL:\n");
	i = 0;
	while (i < 9)
	{
		//printf("%d ", sequence[i]);
		i++;
	}
	//printf("\n");

	return (ft_check_duplicates(sequence));
}

/*
This function gets the crrent grid and the number of the row.
It builds a sequence with the numbers in the row and checks, 
whether it's valid with ft_check_sequence, forewards and backwards
*/
int	ft_check_row(int grid[9][9], int row)
{
	int	sequence[9];
	int	i;

	i = 0;

    //write backwards into the row temp array to check the firs tdirection
	while (i < 9)
	{
		sequence[i] = grid[row][i];
		i++;
	}

	//printf("ROW:\n");
	i = 0;
	while (i < 9)
	{
		//printf("%d ", sequence[i]);
		i++;
	}
	//printf("\n");

	return (ft_check_duplicates(sequence));
}

int ft_check_box(int grid[9][9], int row, int col)
{
	int originCol;
	int originRow;
	int sequence[9];
	int tempCol;
	int i;

	originCol = (int)col/3 * 3;
	originRow = (int)row/3 * 3;
	tempCol = originCol;

	i = 0;
	while(i < 9)
	{
			sequence[i] = grid[originRow][tempCol];
			if ((i + 1) % 3 != 0)
				tempCol++;
			else
			{
				tempCol = originCol;
				originRow++;
			}
			i++;
	}

	//printf("BOX:\n");
	i = 0;
	while (i < 9)
	{
		//printf("%d ", sequence[i]);
		i++;
	}
	//printf("\n");
	return(ft_check_duplicates(sequence));
}