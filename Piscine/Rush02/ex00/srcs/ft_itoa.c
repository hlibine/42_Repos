/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:57:54 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 19:04:59 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	num_length(int num)
{
	int	counter;

	counter = 0;
	while (num > 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	int		len;

	len = num_length(num);
	i = len - 1;
	str = malloc(sizeof(char) * (len + 1));
	while (i >= 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i --;
	}
	str[len] = '\0';
	return (str);
}
