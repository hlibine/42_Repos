/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrossell <rrossell@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:11 by rrossell          #+#    #+#             */
/*   Updated: 2023/07/23 22:09:11 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "funtions.h"

int	check_validity(int table[4][4], int row)
{
	int	c;
	int	r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < row)
		{
			if (table[r][c] == table[row][c])
				return (0);
			r++;
		}
		c++;
	}
	return (1);
}

int	condition_satisfied(int table[4][4], int border[])
{
	if (table_check(table, border) == 1)
		return (1);
	return (0);
}

// Function to fill a single row in the table.
void	fill_row(int table[4][4], int array[4], int row, int border[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		table[row][i] = array[i];
		i++;
	}
	if (check_validity(table, row))
	{
		if (row == 3)
		{
			if (condition_satisfied(table, border))
				ft_print_table(border, table);
		}
		else
		{
			int	new_array[4] = {1, 2, 3, 4};
			make_table(table, new_array, 0, 3, row + 1, border);
		}
	}
}

// Function to perform backtracking and fill the entire table.
void	backtracking(int table[4][4], int array[4], int start, int end, int row, int border[])
{
	int	i;

	i = start;
	while (i <= end)
	{
		swap((array + i), (array + start));
		make_table(table, array, start + 1, end, row, border);
		swap((array + i), (array + start));
		i++;
	}
}

// Function to fill the entire table using backtracking.
// IF Call the function to fill the row
// ELSE Call the function to perform backtracking and fill the table
void	make_table(int table[4][4], int array[4], int start, int end, int row, int border[])
{
	if (start == end)
	{
		fill_row(table, array, row, border);
	}
	else
	{
		backtracking(table, array, start, end, row, border);
	}
}
