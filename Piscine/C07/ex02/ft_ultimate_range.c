/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:50:54 by hlibine           #+#    #+#             */
/*   Updated: 2023/08/02 16:54:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	r2;

	i = 0;
	r2 = max - min;
	*range = malloc (r2 * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while ((min + i) < max)
	{
		(*range)[i] = (min + i);
		i++;
	}
	if (min + i == max)
		return (r2);
	return (-1);
}
/*
int main(void)
{
	int *arr;
	int **p_arr;

	p_arr = &arr;
	printf ("%d\n", ft_ultimate_range(p_arr, -5, 5));
} 
*/
