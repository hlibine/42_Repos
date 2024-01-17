/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/17 20:08:17 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_ps(int fd, char* cmd)
{
	wait(NULL);
}

void	child_ps(int fd, char* cmd)
{
	
}

void	px_pipex(int f1, int f2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		px_error("fork");
	if (!parent)
		child_ps(f1, cmd1);
	else
		parent_ps(f2, cmd2);
}

int	main(int argc, char **argv)
{
	int	*infile;
	int	*outfile;

	if (argc != 5)
		px_error("not enough / too many arguments");
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY);
	px_pipex(infile, outfile);
}