/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/27 14:38:59 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	child_ps(int *e_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		px_error("problem opening file");
	dup2(fd, STDIN_FILENO);
	close(e_fd[0]);
	dup2(e_fd[1], STDOUT_FILENO);
	excec(argv[2], envp);
}

void	parent_ps(int *e_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		px_error("problem reading file");
	dup2(fd, STDOUT_FILENO);
	close(e_fd[1]);
	dup2(e_fd[0], STDIN_FILENO);
	excec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		px_error("not enough / too many arguments");
	if (pipe(fd) == -1)
		px_error("opening the pipe");
	pid = fork();
	if (pid == -1)
		px_error("opening the fork");
	if (!pid)
		child_ps(fd, argv, envp);
	waitpid(pid, NULL, 0);
	parent_ps(fd, argv, envp);
}
