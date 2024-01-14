/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:52:58 by hlibine           #+#    #+#             */
/*   Updated: 2023/07/23 11:59:06 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (s1[c] != '\0' || s2[c] != '\0')
	{
		if (n == 0)
			return (0);
		while (c < n)
		{
			if (!(s1[c] == s2[c]))
				return (s1[c] - s2[c]);
			else
				c++;
		}
		c++;
	}
	if (s1[0] == '\0')
		return (s1[0] - s2[c]);
	else if (s2[0] == '\0')
		return (s1[c] - s2[0]);
	return (0);
}
