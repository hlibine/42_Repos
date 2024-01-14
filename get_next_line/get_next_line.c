/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:10:14 by hlibine           #+#    #+#             */
/*   Updated: 2023/11/21 13:08:03 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
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
		*clean = ft_strdup("");
	if (!*clean)
		return ;
	i = ft_strlen(*clean);
	while (!search(*clean, i))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(*clean, buf);
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
	i = ft_strlcpy(out, *clean, i);
	len = ft_strlencust(*clean);
	if ((*clean)[len] == '\n')
	{
		tmp = ft_strdup(*clean + len + 1);
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
	i = ft_strlencust(clean);
	if (clean[i] == '\n')
		i += 2;
	else if (clean[i] == '\0')
		i += 1;
	out = cleanup(&clean, i);
	return (out);
}

/* int	main(void) {
	const char *filename = "test_input.txt";
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("Error opening file");
		return 1;
	}
	char *line;
	line = get_next_line(fd);
	while (line) {
		printf("New Line: %s", line);
		// printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n");
	close(fd);
	return 0;
} */
