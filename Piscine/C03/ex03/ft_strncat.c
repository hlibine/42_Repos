/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:42 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/23 11:59:36 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlen(char *word)
{
	int	c;

	c = 0;
	while (word[c] != '\0')
		c++;
	return (c);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	c;
	int				n;

	c = 0;
	n = ft_wordlen(dest);
	while (src[c] != '\0' && c < nb)
	{
		dest[c + n] = src[c];
		c++;
	}
	dest[c + n] = '\0';
	return (dest);
}
