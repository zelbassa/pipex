/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:56:26 by zelbassa          #+#    #+#             */
/*   Updated: 2024/03/15 03:58:15 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**get_env(char **env)
{
	int		i;
	char	*path;
	char	**path_arr;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strchr(env[i], '=') + 1;
		i++;
	}
	path_arr = ft_split(path, ':');
	return (path_arr);
}

char	*get_path(char *av, char **env)
{
	char	**path_arr;
	char	*path_cmd;
	int		i;
	char	*full_cmd;

	path_arr = get_env(env);
	i = 0;
	while (path_arr && path_arr[i])
	{
		path_cmd = ft_strjoin("/", av);
		full_cmd = ft_strjoin(path_arr[i], path_cmd);
		if (access(full_cmd, F_OK | X_OK) == 0)
		{
			free(path_cmd);
			free(full_cmd);
			return (ft_strjoin(path_arr[i], "/"));
		}
		i++;
	}
	perror("Command");
	return (NULL);
}

void	exec_pipe(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], env);
	if (path == NULL)
	{
		free(cmd);
		exit(0);
	}
	path = ft_strjoin(path, cmd[0]);
	if (execve(path, cmd, env) == -1)
	{
		free_arr(cmd);
		exit(0);
	}
	free_arr(cmd);
	free(path);
}
