/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thousands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:46:34 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 19:27:38 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	get_thousands(char *dict, long long nbr)
{
	nbr /= 1000;
	nbr %= 1000;
	if (nbr <= 20)
		ft_strstr(dict, ft_itoa(nbr));
	else
	{
		if (nbr / 100 != 0)
		{
			ft_strstr(dict, ft_itoa((nbr / 100)));
			ft_strstr(dict, ft_itoa((nbr - (nbr % 100)) / (nbr / 100)));
			ft_strstr(dict, ft_itoa((nbr % 100) - (nbr % 10)));
			ft_strstr(dict, ft_itoa(nbr % 10));
		}
		else
		{
			ft_strstr(dict, ft_itoa(nbr / 10 * 10));
			ft_strstr(dict, ft_itoa(nbr % 10));
		}
	}
	if (nbr != 0)
		ft_strstr(dict, "1000");
}
