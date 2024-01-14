/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrossell <rrossell@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:11 by rrossell          #+#    #+#             */
/*   Updated: 2023/07/23 22:09:11 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funtions.h"

int	check_column(int table[4][4], int border[], int *index);
int	check_column_rev(int table[4][4], int border[], int *index);
int	check_rows(int table[4][4], int border[], int *index);

int	table_check(int table[4][4], int border[])
{
	int	index;
	int	*index_pointer;
	int	i;
	int	reversed[4];

	index = 0;
	index_pointer = &index;
	if (check_column(table, border, index_pointer) != 1)
		return (-4);
	if (check_column_rev(table, border, index_pointer) != 1)
		return (-5);
	if (check_rows(table, border, index_pointer) != 1)
		return (-6);
	i = 0;
	while (index < 16)
	{
		ft_rev_line(table[i], reversed);
		if (ft_check_line(reversed, border[index]) == 0)
			return (-7);
		index++;
		i++;
	}
	return (1);
}

int	check_column(int table[4][4], int border[], int *index)
{
	int	i;
	int	column[4];

	i = 0;
	while (*index < 4)
	{
		column[0] = table[0][i];
		column[1] = table[1][i];
		column[2] = table[2][i];
		column[3] = table[3][i];
		if (ft_check_line(column, border[*index]) == 0)
			return (-4);
		(*index)++;
		i++;
	}
	return (1);
}

int	check_column_rev(int table[4][4], int border[], int *index)
{
	int	i;
	int	column[4];
	int	reversed[4];

	i = 0;
	while (*index < 8)
	{
		column[0] = table[0][i];
		column[1] = table[1][i];
		column[2] = table[2][i];
		column[3] = table[3][i];
		ft_rev_line(column, reversed);
		if (ft_check_line(reversed, border[*index]) == 0)
			return (-5);
		(*index)++;
		i++;
	}
	return (1);
}

int	check_rows(int table[4][4], int border[], int *index)
{
	int	i;

	i = 0;
	while (*index < 12)
	{
		if (ft_check_line(table[i], border[*index]) == 0)
			return (-6);
		(*index)++;
		i++;
	}
	return (1);
}
