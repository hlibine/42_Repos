/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrossell <rrossell@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:11 by rrossell          #+#    #+#             */
/*   Updated: 2023/07/23 22:09:11 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funtions.h"
#include <unistd.h>

void	ft_print_table_end(int border[], int table[4][4]);

void	ft_print_table(int border[], int table[4][4])
{
	int	i;

	ft_putstr("    ");
	i = 0;
	while (i < 4)
	{
		ft_putint(border[i]);
		ft_putstr("  ");
		i++;
	}
	ft_putstr("\n   ------------");
	ft_print_table_end(border, table);
}

void	ft_print_table_end(int border[], int table[4][4])
{
	int	i;
	int	g;

	i = 8;
	g = 0;
	while (i < 12)
	{
		ft_putchar('\n');
		ft_putint(border[i]);
		ft_putstr(" |");
		ft_print_boxes(table[g]);
		ft_putstr("| ");
		ft_putint(border[i + 4]);
		i++;
		g++;
	}
	ft_putstr("\n   ------------\n    ");
	i = 4;
	while (i < 8)
	{
		ft_putint(border[i]);
		ft_putstr("  ");
		i++;
	}
}

void	ft_print_boxes(int row[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_putchar(' ');
		ft_putint(row[i]);
		ft_putchar(' ');
		i++;
	}
}

//function to print 1 character to the terminal
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}
