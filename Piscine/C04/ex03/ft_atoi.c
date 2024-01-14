/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:42:52 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/25 11:18:20 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ispace(char str)
{
	if ((str >= 9 && str <= 13) || str == ' ')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	c;
	int	n;
	int	o;

	c = 0;
	n = 1;
	o = 0;
	while (ispace(str[c]))
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			n = n * -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		o = o * 10 + str[c] - '0';
		c++;
	}
	return (o * n);
}
