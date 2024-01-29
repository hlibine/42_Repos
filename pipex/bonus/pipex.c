/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:52:06 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/29 17:31:19 by hlibine          ###   ########.fr       */
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

char*	heredoc(char *limiter)
{
	char *line;
	char *out;
	int flag;

	out = ft_strdup("");
	flag = 0;
	while (flag != 1)
	{
		line = get_next_line(0);
		if (ft_strncmp(limiter, line, ft_strlen(line) - 1) != 0)
			out = ft_strjoin(out, line);
		else
			flag = 1;
		free(line);
	}
	return (out);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fdi;
	int		fdo;

	if (argc < 5)
		px_error("not enough arguments");
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		i = 3;
		heredoc(argv[2]);
		fdo = open(argv[argc - 2], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	}
	else
	{
		i = 2;
		fdi = open(argv[1], O_RDONLY);
		if (fdi < 0)
			px_error("open");
		fdo = open(argv[argc - 2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fdo < 0)
			px_error("problem reading file");
		dup2(fdi, STDIN_FILENO);
	}
	while (i < argc - 3)
		pipewrk(argv[i++], envp);
	excec(argv[argc - 2], envp);
	return (0);
}
