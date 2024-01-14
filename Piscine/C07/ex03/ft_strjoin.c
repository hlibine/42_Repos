/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:45:09 by hlibine           #+#    #+#             */
/*   Updated: 2023/08/01 17:54:28 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char **str, char *sep, int size)
{
	int	i;
	int	i2;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		i2 = 0;
		while (str[i][i2++] != '\0')
			count++;
		i++;
		i2 = 0;
		if (i < size)
			while (sep[i2++] != '\0')
				count++;
	}
	return (count);
}

void	ft_assignstr(char **strs, char *sep, char *str, int size)
{
	int	i2;
	int	i3;
	int	i4;

	i2 = 0;
	i3 = 0;
	while (i3 < size)
	{
		i4 = 0;
		while (strs[i3][i4++] != '\0')
		{
			str[i2] = strs[i3][i4 - 1];
			i2++;
		}
		i3++;
		i4 = 0;
		if (i3 < size)
		{
			while (sep[i4++] != '\0')
			{
				str[i2] = sep[i4 - 1];
				i2++;
			}
		}
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	i = 0;
	if (size == 0)
	{
		str = malloc(1 * sizeof(char));
		return (str);
	}
	i = (ft_strlen(strs, sep, size));
	str = malloc(i * sizeof(char) + 1);
	ft_assignstr(strs, sep, str, size);
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char *arr[3];
	char sep[] = " ";

	arr[0] = "abc";
	arr[1] = "123";
	arr[2] = "abc";
	printf("%s\n", ft_strjoin(3, arr, sep));
}
*/