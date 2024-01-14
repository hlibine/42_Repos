/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:14:39 by jruiz-sc          #+#    #+#             */
/*   Updated: 2023/07/30 21:54:00 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	main(int ac, char **av)
{
	char		*dict;

	if (ac == 2)
	{
		dict = dict_to_string("numbers.dict");
		if (ft_atoi(av[1]) == 0)
			ft_strstr_zero(dict, "0");
		filter_number(dict, ft_atoi(av[1]));
	}
	else if (ac == 3)
	{
		dict = dict_to_string(av[1]);
		if (ft_atoi(av[2]) == 0)
			ft_strstr_zero(dict, "0");
		filter_number(dict, ft_atoi(av[2]));
	}
	else
	{
		print_error();
		return (0);
	}
	free(dict);
	write(1, "\b\n", 2);
	return (0);
}
