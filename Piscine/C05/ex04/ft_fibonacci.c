/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:12 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/25 14:16:43 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	i;
	int	x;
	int	x2;
	int	x3;

	x = 1;
	x2 = 0;
	x3 = 0;
	i = 0;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	while (i + 1 < index)
	{
		x3 = x;
		x = x2 + x;
		x2 = x3;
		i++;
	}
	return (x);
}
/*
int	main(void)
{
	int index;

	index = 0;
	printf("%d\n", ft_fibonacci(index));
}
*/