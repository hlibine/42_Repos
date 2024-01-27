/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/27 13:13:16 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "get_next_line/get_next_line.h"

void	excec(const char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = px_getpath(s_cmd[0], envp);
	if (execve(path, &s_cmd[0], envp) == -1)
	{
		ft_putstr_fd("pipex error: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		px_free(s_cmd);
		exit(EXIT_FAILURE);
	}
}

void	pipewrk(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if(pipe(fd) == -1)
		px_error("pipe error");
	pid = fork();
	if (pid == -1)
		px_error("fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		excec(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(STDIN_FILENO, fd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fdi;
	int		fdo;
	char	*line

	if (argc < 5)
		px_error("not enough arguments");
	if (ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		line = get_next_line(0);
	}
	else
	{
		i = 2;
		fdi = open(argv[1], 0);
		fdo = open(argv[argc - 1], 1);
		dup2(fdi, STDIN_FILENO);
	}
	while (i < argc - 3)
		pipewrk(argv[i++], envp);
	excec(argv[argc - 2], envp);
	return (0);
}
