/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/18 15:44:18 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_ps(int f2, char* cmd)
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(f2, ...);
	dup2(end[0], ...);
	close[1];
	close(f2)
	execv();
	exit(EXIT_FAILURE)
}

void	child_ps(int f1, char* cmd)
{
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	execve();
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, char **argv, char** envp)
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

int	main(int argc, char **argv, char **envp)
{
	int	*infile;
	int	*outfile;

	if (argc != 5)
		px_error("not enough / too many arguments");
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY);
	pipex(infile, outfile, argv, envp);
	return (0);
}