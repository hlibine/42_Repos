/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:55:57 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/23 22:09:11 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funtions.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	border[16];
	int	table1[4][4];
	int	array[4];

	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	make_border_array(argv[1], border);
	make_table(table1, array, 0, 3, 0, border);
	return (0);
}

int	make_border_array(char border_str[], int border[])
{
	int	i;
	int	g;

	if (ft_strlen(border_str) != 31)
		return (20);
	else
	{
		i = 0;
		g = 0;
		while (border_str[i] || g < 16)
		{
			border[g] = char_to_int(border_str[i]);
			g++;
			i++;
			if (border_str[i] != ' ')
				return (-9);
			i++;
		}
	}
	return (0);
}
