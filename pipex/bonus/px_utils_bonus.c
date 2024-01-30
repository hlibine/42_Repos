/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/30 14:06:51 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	bonus_px_error(char *in)
{
	perror(in);
	unlink(".swap");
	exit(EXIT_FAILURE);
}

void	bonus_px_free(char **in)
{
	int	i;

	i = -1;
	while (in[++i])
		free(in[i]);
	free(in);
}

char	*bonus_envpwrk(char *in, char **envp)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	while (envp[i])
	{
		a = 0;
		while (envp[i][a] && envp[i][a] != '=')
			a++;
		str = ft_substr(envp[i], 0, a);
		if (ft_strncmp(str, in, ft_strlen(in)) == 0)
		{
			free(str);
			return (envp[i] + a + 1);
		}
		free(str);
		i++;
	}
	return (NULL);
}

char	*bonus_px_getpath(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	s_cmd = ft_split(cmd, ' ');
	allpath = ft_split(bonus_envpwrk("PATH", envp), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			px_free(s_cmd);
			return (exec);
		}
		free(exec);
	}
	px_free(allpath);
	px_free(s_cmd);
	return (cmd);
}
