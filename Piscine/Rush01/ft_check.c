/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:54 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/23 22:09:11 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "funtions.h"

int	ft_line_check(int x, int y)
{
	if (x == 4 && y == 1)
	{
		return (1);
	}
	else if (x == 3 && (y == 1 || y == 2))
	{
		return (1);
	}
	else if (x == 2 && (y == 1 || y == 2 || y == 3))
	{
		return (1);
	}
	else if (x == 1 && (y == 2 || y == 3 || y == 4))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_check(int b[])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!(b[i] >= 1 && b[i] <= 4))
			return (10);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (ft_line_check(b[i], b[i + 4]) == 0)
			return (11);
		i++;
	}
	i = 8;
	while (i < 12)
	{
		if (ft_line_check(b[i], b[i + 4]) == 0)
			return (12);
		i++;
	}
	return (1);
}

int	ft_check_line(int line[], int n)
{
	if (count_boxes(line) == n)
		return (1);
	return (0);
}

int	count_boxes(int boxes[4])
{
	int	i;
	int	g;
	int	count_boxes;

	i = 0;
	g = 1;
	count_boxes = 1;
	while (i < 4 && g < 4)
	{
		if (boxes[i] == 4)
		{
			return (count_boxes);
		}
		else if (boxes[i] < boxes[g])
		{
			count_boxes++;
			i = g;
		}
		g++;
	}
	return (count_boxes);
}
