/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:10:14 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 13:51:25 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	search(char *buf, int c)
{
	int	i;

	i = 0;
	if (c < BUFFER_SIZE)
		c = 0;
	else
		c -= BUFFER_SIZE;
	while (buf[c + i])
	{
		if (buf[c + i] == '\n')
			return (c + i);
			i++;
	}
	return (0);
}

void	filewrk(int fd, char **clean)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		bytes_read;
	char	*tmp;

	if (!*clean)
		*clean = gnl_strdup("");
	if (!*clean)
		return ;
	i = gnl_strlen(*clean);
	while (!search(*clean, i))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		tmp = gnl_strjoin(*clean, buf);
		free(*clean);
		*clean = tmp;
		if (!*clean)
			break ;
		i += bytes_read;
	}
}

char	*cleanup(char **clean, int i)
{
	int		len;
	char	*tmp;
	char	*out;

	out = malloc(i * sizeof(char));
	if (!out)
		return (NULL);
	i = gnl_strlcpy(out, *clean, i);
	len = gnl_strlencust(*clean);
	if ((*clean)[len] == '\n')
	{
		tmp = gnl_strdup(*clean + len + 1);
		if (!tmp)
			return (NULL);
		free(*clean);
		*clean = tmp;
	}
	else
	{
		free(*clean);
		*clean = NULL;
	}
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*clean;
	char		*out;
	int			i;

	if (read(fd, NULL, 0) < 0)
	{
		free(clean);
		clean = 0;
		return (NULL);
	}
	filewrk(fd, &clean);
	if (!clean || *clean == '\0')
	{
		free(clean);
		clean = NULL;
		return (NULL);
	}
	i = gnl_strlencust(clean);
	if (clean[i] == '\n')
		i += 2;
	else if (clean[i] == '\0')
		i += 1;
	out = cleanup(&clean, i);
	return (out);
}
