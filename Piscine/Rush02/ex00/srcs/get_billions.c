/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_billions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:34:45 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 21:49:37 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	get_billions(char *dict, long long nbr)
{
	nbr /= 1000000000;
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
	{
		ft_strstr(dict, "1000000000");
	}
}
