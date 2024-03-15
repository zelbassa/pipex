/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:03:08 by zelbassa          #+#    #+#             */
/*   Updated: 2024/03/15 02:57:20 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	**get_env(char **env);
char	*get_path(char *av, char **env);
void	exec_pipe(char *av, char **env);
void	child(char **av, char **env, int fds[]);
void	parent(char **av, char **env, int fds[]);
void	free_arr(char **arr);

#endif