/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:17:39 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/05 18:01:19 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/header/libft.h"
# include <errno.h>

char	**parse_command(char *argv, char **env);
int		init_check(int argc, char *argv[]);
void	free_paths(char **path);
size_t	ft_strlength(char **c);
char	**parse_arg(char *argv, char c);
int		first_child(char **argv, char **env, int *fd);
void	error_mngr(char **command, int err);
void	close_pipe(int *fd);
// int		pork(int (*fd)[]);
int		pork(void);
int		init_bonus_check(int argc, char *argv[]);
int		parent(int *fd);
// int		second_parent(int *fd);
int		second_parent(void);
int		child(char **argv, char **env, int *fd);
int		second_child(char **argv, char **env, int *fd);
int		waitall(int *fd);

#endif
