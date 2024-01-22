/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/22 15:22:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	px_error(char *in)
{
	write (2, "ERROR: ", 7);
	while (in)
	{
		write(2, *in, 1);
		in++;
	}
	write (2, "\n", 1);
	exit(-1);
}

void	px_free(char **in)
{
	while(*in)
	{
		free(*in);
		in++;
	}
	free(in);
}

char	*px_getpath(char *cmd, char **envp)
{
	
}
