/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:10:57 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 14:02:22 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlencust(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (i);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*out;
	int		l1;
	int		l2;

	i = 0;
	l1 = gnl_strlen(s1);
	l2 = gnl_strlen(s2);
	out = malloc(l1 + l2 + 1);
	if (out == NULL)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			out[i] = s1[i];
		else
			out[i] = s2[i - l1];
		i++;
	}
	out[i] = '\0';
	return (out);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gnl_strlen(src));
}

char	*gnl_strdup(const char *s1)
{
	char	*out;
	size_t	len;

	len = gnl_strlen(s1) + 1;
	out = malloc(len);
	if (out == NULL)
		return (NULL);
	gnl_strlcpy(out, s1, len);
	return (out);
}
