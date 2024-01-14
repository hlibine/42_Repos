/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:38:06 by hlibine           #+#    #+#             */
/*   Updated: 2023/08/02 16:53:37 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	r2;
	int	*range;
	int	i;

	r2 = max - min;
	i = 0;
	range = malloc(r2 * sizeof(int));
	if (!range)
		return (NULL);
	if (min >= max)
		return (0);
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int	main(void)
{
	int min = 1812;
	int	max = 1812;
	int len = max - min;
	int	*tab = ft_range(min, max);

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", tab[i]);
	}

	return (0);
}
*/