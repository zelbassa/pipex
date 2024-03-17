/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:13:47 by zelbassa          #+#    #+#             */
/*   Updated: 2024/03/15 02:57:46 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **av, char **env, int fds[])
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("error");
		exit(0);
	}
	dup2(fds[1], 1);
	dup2(fd, 0);
	close(fds[0]);
	exec_pipe(av[2], env);
}

void	parent(char **av, char **env, int fds[])
{
	int	fd1;

	fd1 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd1 == -1)
	{
		perror("error");
		exit(0);
	}
	dup2(fds[0], 0);
	dup2(fd1, 1);
	close(fds[1]);
	exec_pipe(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fds[2];
	int	id;

	if (ac != 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
		exit(0);
	}
	if (pipe(fds) == -1)
		exit(0);
	id = fork();
	if (id == -1)
		exit(0);
	else if (id == 0)
		child(av, env, fds);
	parent(av, env, fds);
}
