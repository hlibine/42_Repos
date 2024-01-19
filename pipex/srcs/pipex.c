/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/19 16:20:00 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	excec(const  char *cmd, char **envp)
{
	char **s_cmd;
	char *path;

	s_cmd = ft_split(cmd, ' ');
	path = getpath(s_cmd[0], envp);
	exit(EXIT_SUCCESS);
}

void	child_ps(int e_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(av[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(e_fd[1], STDOUT_FILENO);
	close(e_fd[0]);
	exex(argv[2], envp);
}

void	parent_ps(int e_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(e_fd[0], STDIN_FILENO);
	close(e_fd[1]);
	excec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]
	pid_t	pid;

	if (argc != 5)
		px_error("not enough / too many arguments");
	if (pipe(fd) == -1)
		px_error("pipe error");
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child_ps(fd, argv, envp);
	parent_ps(fd, argv, envp);
	return (0);
}