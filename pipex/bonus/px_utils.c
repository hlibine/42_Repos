/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/24 11:48:49 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	px_error(char *in)
{
	ft_putstr_fd("pipex error: ", 2);
	ft_putendl_fd(in, 2);
	exit(-1);
}

void	px_free(char **in)
{
	int	i;

	i = -1;
	while(in[++i])
		free(in[i]);
	free(in);
}

char	*envpwrk(char *in, char **envp)
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
	return(NULL);
}

char	*px_getpath(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**allpath; 
	char	*path_part;
	char	**s_cmd;

	i = -1;
	s_cmd = ft_split(cmd, ' ');
	allpath = ft_split(envpwrk("PATH", envp), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if(access(exec, F_OK | X_OK) == 0)
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
