/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:26:50 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/19 14:49:30 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlen(char *word)
{
	int	c;

	c = 0;
	while (word[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	n;

	c = 0;
	n = ft_wordlen(dest);
	while (src[c] != '\0')
	{
		dest[c + n] = src[c];
		c++;
	}
	dest[c + n] = '\0';
	return (dest);
}
