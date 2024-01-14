/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:29:36 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/25 10:48:49 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

//int	main(void)
//{
//	int	nb;
//	int	power;
//
//	nb = 0;
//	power = 0;
//	printf("%d\n", ft_recursive_power(nb, power));	
//}