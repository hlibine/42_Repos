/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:29:26 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 20:15:34 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

char	*dict_to_string(char *dict_file)
{
	char		*dict_string;
	char		c;
	long long	byte;
	int			fd;

	dict_string = malloc(sizeof(char));
	if (dict_string == NULL)
		return (NULL);
	dict_string[0] = '\0';
	fd = open(dict_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	byte = read(fd, &c, 1);
	if (byte == -1)
	{
		free(dict_string);
		print_dicterror();
	}
	while (byte > 0)
	{
		dict_string = ft_simple_strjoin(dict_string, c);
		byte = read(fd, &c, 1);
	}
	close(fd);
	return (dict_string);
}
