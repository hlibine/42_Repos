/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:29:05 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/26 14:51:59 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 1)
		return (0);
	while (i * i <= (unsigned int) nb)
	{
		if (i * i == (unsigned int) nb)
			return (i);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	int nb;

	nb = 16;
	printf("%d\n", ft_sqrt(nb));
}
*/