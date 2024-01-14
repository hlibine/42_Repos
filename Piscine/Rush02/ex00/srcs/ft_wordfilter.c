/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordfilter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:34:48 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/30 21:46:21 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ft_char(int i, char *str)
{
	if (str[i] >= 33 && str[i] <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_wordlen(char *str)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (str[i2] != '\n' && str[i2] != '\0')
	{
		if ((str[i2] == ' ' && ft_char(i2 - 1, str)) == 1)
			i++;
		else if (ft_char(i2, str) == 1)
			i++;
		i2++;
	}
	return (i);
}

int	ft_wordfilter(char *str)
{
	int		i;
	int		i2;
	char	*o;

	i = 0;
	i2 = 0;
	o = malloc((ft_wordlen(str) + 1) * sizeof(char));
	while (str[i - 1] != ':')
		i++;
	if (str[i - 1] == ':' && str[i] == ' ')
		i++;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == ' ' && ft_char(i - 1, str))
			o[i2++] = str[i];
		else if (ft_char(i, str))
			o[i2++] = str[i];
		i++;
	}
	if (i2 == 0)
		return (print_dicterror());
	o[i2] = '\0';
	ft_putstr(o);
	free (o);
	return (1);
}

/*
int	main(void)
{
	char str[] = "50 :      ";

	ft_wordfilter(str);
	return (0);
}
*/
