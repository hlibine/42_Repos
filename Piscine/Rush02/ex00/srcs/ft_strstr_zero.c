/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:45:12 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 21:51:52 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

long long	ft_strstr_zero(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (ft_wordfilter(&str[i]));
			j++;
		}
		i++;
	}
	return (print_dicterror());
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char	str[] = "50 : Fifty";
	char	to_find[] = "0";
	char	str1[] = "50 :             ";
	char	to_find1[] = "50";

	printf("Checking with ft_strstr: %d\n", ft_strstr(str, to_find));
	printf("Checking with ft_strstr: %d", ft_strstr(str1, to_find1));
	return 0;
}
*/