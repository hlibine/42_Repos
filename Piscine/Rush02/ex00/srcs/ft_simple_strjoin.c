/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:50:45 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 20:35:17 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_simple_strjoin(char *str, char c)
{
	char	*new_string;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(str);
	if (!str || !c)
		return (str);
	new_string = malloc(sizeof(char) * (str_len + 2));
	if (!new_string)
		return (NULL);
	while (str[i])
	{
		new_string[i] = str[i];
		i++;
	}
	free(str);
	new_string[i] = c;
	new_string[i + 1] = '\0';
	return (new_string);
}
