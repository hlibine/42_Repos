/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:34:39 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 21:46:06 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	filter_number(char *dict, long long nbr)
{
	if (nbr < 0)
		print_error();
	else if (nbr == 0)
		ft_strstr(dict, ft_itoa(nbr));
	else if (nbr >= 1000000000)
	{
		get_billions(dict, nbr);
		get_millions(dict, nbr);
		get_thousands(dict, nbr);
		get_hundreds(dict, nbr);
	}
	else if (nbr >= 1000000)
	{
		get_millions(dict, nbr);
		get_thousands(dict, nbr);
		get_hundreds(dict, nbr);
	}
	else if (nbr >= 1000)
	{
		get_thousands(dict, nbr);
		get_hundreds(dict, nbr);
	}
	else
		get_hundreds(dict, nbr);
}
